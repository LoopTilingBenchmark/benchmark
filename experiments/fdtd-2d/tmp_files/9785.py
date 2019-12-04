from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/fdtd-2d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/fdtd-2d/tmp_files/9785.c')
procedure('kernel_fdtd_2d')
loop(0)

known(' nx > 1 ')
known(' ny > 1 ')
pragma(1,2,"omp parallel for private(t4,t6,t8,t10)")
tile(1,2,32,2)
tile(1,4,128,4)

pragma(2,2,"omp parallel for private(t4,t6,t8,t10)")
tile(2,2,32,2)
tile(2,4,128,4)

pragma(3,2,"omp parallel for private(t4,t6,t8,t10)")
tile(3,2,32,2)
tile(3,4,128,4)
