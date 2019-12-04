from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/heat-3d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/heat-3d/tmp_files/2963.c')
procedure('kernel_heat_3d')
loop(0)

tile( 0,2,16,2 )
tile( 0,4,64,4 )
tile( 0,6,8,6 )

tile( 1,2,16,2 )
tile( 1,4,64,4 )
tile( 1,6,8,6 )
