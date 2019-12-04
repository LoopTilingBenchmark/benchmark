from chill import *
source('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/heat-3d/kernel.c')
destination('/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/experiments/heat-3d_chill_openmp/tmp_files/7942.c')
procedure('kernel_heat_3d')
loop(0)
known('n>3')

pragma(0,2,"omp parallel for private(t4,t6,t8,t10,t12)")
tile(0,2,32,2)
tile(0,4,16,4)


pragma(1,2,"omp parallel for private(t4,t6,t8,t10,t12)")

tile(1,2,32,2)
tile(1,4,16,4)


