import os
import sys
import subprocess
import random

class PlopperChill:
    def __init__(self,sourcefile,outputdir):
        outputdir = "/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/" + outputdir
        compileoptions = ""

        
        # Initilizing global variables
        self.configfile = os.path.dirname(os.path.abspath(__file__))+'/config.txt'
        self.sourcefile = sourcefile
        self.outputdir = outputdir+"/tmp_files"
        self.compileoptions = compileoptions

        if not os.path.exists(self.outputdir):
            os.makedirs(self.outputdir)


    #Creating a dictionary using parameter label and value 
    def createDict(self, x, params):
        dictVal = {}
        for p, v in zip(params, x):
            dictVal[p] = v
        return(dictVal)

    #Replace the Markers in the source file with the corresponding Pragma values
    def plotValues(self, dictVal, inputfile, outputfile):
        with open(inputfile, "r") as f1:
            buf = f1.readlines()
                
        with open(outputfile, "w") as f2:
            for line in buf:
                modify_line = line
                if 'DEST' in modify_line:
                    modify_line = modify_line.replace('DEST',outputfile[:-2] + 'c')
                if 'SRC' in modify_line:
                    modify_line = modify_line.replace('SRC',inputfile[:-len('chill.py')] + 'kernel.c')
                for key, value in dictVal.items():
                    if key in modify_line:
                        if value != 'None': #For empty string options
                            modify_line = modify_line.replace('#'+key, str(value))
                
                if modify_line != line:
                    f2.write(modify_line)
                else:
                    #To avoid writing the Marker
                    f2.write(line)


    # Function to find the execution time of the interim file, and return the execution time as cost to the search module
    def findRuntime(self, x, params):
        interimfile = ""
        #exetime = float('inf')
        exetime = sys.maxsize
        counter = random.randint(1, 10001) # To reduce collision increasing the sampling intervals

        interimfile = self.outputdir+"/"+str(counter)+".py"
        

        # Generate intermediate file
        dictVal = self.createDict(x, params)
        self.plotValues(dictVal, self.sourcefile, interimfile)

        #compile and find the execution time
        tmpbinary = interimfile[:-3]

        #cmd1 = "gcc -fopenmp -DPOLYBENCH_TIME -O2 -I/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/OpenMP_benchmark/utilities -I/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/OpenMP_benchmark/correlation "+interimfile+" /uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/OpenMP_benchmark/utilities/polybench.c -o "+tmpbinary+" -lm"
        kernel_idx = self.sourcefile.rfind('/')
        kernel_dir = self.sourcefile[:kernel_idx]

        subprocess.run(["/uufs/chpc.utah.edu/common/home/u1142914/lib/chill/chill-dev/build/chill", interimfile])
        cmd1 = "clang " + kernel_dir  + "/rest.c "  +interimfile[:-2] + 'c'+" /uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/utilities/polybench.c -O3 -DPOLYBENCH_TIME -march=native -lm -o"+tmpbinary
#-fno-vectorize -fno-slp-vectorize
        cmd2 = "/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/utilities/time_benchmark.sh " +  tmpbinary
        #Find the compilation status using subprocess
        compilation_status = subprocess.run(cmd1, shell=True, stderr=subprocess.PIPE)
        
        #Find the execution time only when the compilation return code is zero, else return infinity
        if compilation_status.returncode == 0 :
        #and len(compilation_status.stderr) == 0: #Second condition is to check for warnings
            execution_status = subprocess.run(cmd2, shell=True, stdout=subprocess.PIPE)
            print(execution_status.stdout)
            exetime = float(execution_status.stdout.decode('utf-8'))
        else:
            print(compilation_status.stderr)
            print("compile failed")
        return exetime #return execution time as cost

if __name__ == '__main__':
    params = ["P1", "P2", "P3"]
    x = ["static", "8", "2"]
    obj = Plopper()
    retVal = obj.findRuntime(x, params)
    print(retVal)
