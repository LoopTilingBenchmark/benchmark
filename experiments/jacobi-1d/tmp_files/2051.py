from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/jacobi-1d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/jacobi-1d/tmp_files/2051.c')
procedure('kernel_jacobi_1d')
loop(0)

known(' n > 2 ')

tile(0,2,8,2)
tile(1,2,8,2)
