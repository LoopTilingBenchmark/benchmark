#!/usr/bin/python

# Open a file
import os
import subprocess

polybench_dir = "polybench/polybench-code"


#cur_dir = os.path.dirname(os.path.realpath(__file__))

with open("benchmark_list_2", "r") as fo:
    file = fo.readline()
    while file:
        file = file.rstrip('\n')
        if file[0] != "#":
            kernel_idx = file.rfind('/')
            problem_dir = file[:kernel_idx]
            kernel = file[kernel_idx+1:-2]
            #print("kernel")
            #print(kernel)
            print("pragma")
            #subprocess.run(["mpirun", "-np","2","python", "-m", "ytopt.search.async_search", "--prob_path=" + polybench_dir + problem_dir + "/problem.py", "--prob_attr=problem", "--max_time=2400", "--base_estimator=RF", "--exp_dir=experiments/"+kernel+"_pragma", "--exp_id=" + kernel])
            #print("chill")
            #subprocess.run(["mpirun", "-np","2","python", "-m", "ytopt.search.async_search", "--prob_path=" + polybench_dir + problem_dir + "/problem_chill.py", "--prob_attr=problem", "--max_time=2400", "--base_estimator=RF", "--exp_dir=experiments/"+kernel+"_chill", "--exp_id=" + kernel])
            print("chill_openmp")
            subprocess.run(["mpirun", "-np","2","python", "-m", "ytopt.search.async_search", "--prob_path=" + polybench_dir + problem_dir + "/problem_chill_openmp.py", "--prob_attr=problem", "--max_time=900", "--base_estimator=RF", "--exp_dir=experiments/"+kernel+"_chill_openmp", "--exp_id=" + kernel])
            #print("baseline")
            #subprocess.run(["clang","-o","tmp",polybench_dir + file, polybench_dir+"/utilities/polybench.c","-DLARGE_DATASET" , "-DPOLYBENCH_TIME","-O3","-fno-vectorize","-fno-slp-vectorize","-fno-unroll-loops","-lm","-I" + polybench_dir+"/utilities/"])
            #print("Best")
            #subprocess.run(["./polybench/polybench-code/utilities/time_benchmark.sh","./tmp"])
        file = fo.readline()

        #clang 
        #clang -o jacobi-2d jacobi-2d.c -I. -I../../utilities ../../utilities/polybench.c -DPOLYBENCH_TIME -O3 -fno-vectorize -fno-slp-vectorize -fno-unroll-loops -lm
        #clang polly
        #clang -o jacobi-2d_polly jacobi-2d.c -I. -I../../utilities ../../utilities/polybench.c  -DPOLYBENCH_TIME -O3 -mllvm -polly -mllvm -polly-process-unprofitable -mllvm -polly-allow-nonaffine -mllvm -polly-allow-modref-calls -mllvm -polly-allow-nonaffine-loops -mllvm -polly-ignore-aliasing -fno-vectorize -fno-slp-vectorize -fno-unroll-loops -lm

