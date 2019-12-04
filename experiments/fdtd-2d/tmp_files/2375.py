from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/fdtd-2d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/fdtd-2d/tmp_files/2375.c')
procedure('kernel_fdtd_2d')
loop(0)

known(' nx > 1 ')
known(' ny > 1 ')
pragma(1,2,"omp parallel for")
tile(1,2,8,2)
tile(1,4,8,4)

pragma(2,2,"omp parallel for")
tile(2,2,8,2)
tile(2,4,8,4)

pragma(3,2,"omp parallel for")
tile(3,2,8,2)
tile(3,4,8,4)

