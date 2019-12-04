from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/seidel-2d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/seidel-2d/tmp_files/1961.c')
procedure('kernel_seidel_2d')
loop(0)

known(' n > 2 ')

tile(0,2,16,2)
tile(0,4,64,4)
