from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/fdtd-2d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/fdtd-2d/tmp_files/6145.c')
procedure('kernel_fdtd_2d')
loop(0)

known(' nx > 1 ')
known(' ny > 1 ')
tile(1,2,16,2)
tile(1,4,128,4)

tile(2,2,16,2)
tile(2,4,128,4)

tile(3,2,16,2)
tile(3,4,128,4)

