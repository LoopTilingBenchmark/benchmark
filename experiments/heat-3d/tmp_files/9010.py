from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/heat-3d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/heat-3d/tmp_files/9010.c')
procedure('kernel_heat_3d')
loop(0)
known('n>3')

tile(0,2,8,2)
tile(0,4,64,3)

tile(1,2,8,2)
tile(1,4,64,3)

