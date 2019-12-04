// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/heat-3d/kernel.c' as parsed by frontend compiler rose

void kernel_heat_3d(int tsteps, int n, double A[200 + 0][200 + 0][200 + 0], double B[200 + 0][200 + 0][200 + 0]) {
  int t12;
  int t10;
  int t8;
  int t6;
  int t4;
  int t2;
  for (t2 = 1; t2 <= 1000; t2 += 1) {
    #pragma omp parallel for private(t4,t6,t8,t10,t12,t14)
    for (t4 = 1; t4 <= n - 2; t4 += 32) 
      for (t6 = t4; t6 <= (t4 + 31 < n - 2 ? t4 + 31 : n - 2); t6 += 1) 
        for (t8 = 1; t8 <= n - 2; t8 += 16) 
          for (t10 = t8; t10 <= (t8 + 15 < n - 2 ? t8 + 15 : n - 2); t10 += 1) 
            for (t12 = 1; t12 <= n - 2; t12 += 1) 
              B[t6][t10][t12] = 0.125 * (A[t6 + 1][t10][t12] - 2 * A[t6][t10][t12] + A[t6 - 1][t10][t12]) + 0.125 * (A[t6][t10 + 1][t12] - 2 * A[t6][t10][t12] + A[t6][t10 - 1][t12]) + 0.125 * (A[t6][t10][t12 + 1] - 2 * A[t6][t10][t12] + A[t6][t10][t12 - 1]) + A[t6][t10][t12];
    #pragma omp parallel for private(t4,t6,t8,t10,t12,t14)
    for (t4 = 1; t4 <= n - 2; t4 += 32) 
      for (t6 = t4; t6 <= (t4 + 31 < n - 2 ? t4 + 31 : n - 2); t6 += 1) 
        for (t8 = 1; t8 <= n - 2; t8 += 16) 
          for (t10 = t8; t10 <= (t8 + 15 < n - 2 ? t8 + 15 : n - 2); t10 += 1) 
            for (t12 = 1; t12 <= n - 2; t12 += 1) 
              A[t6][t10][t12] = 0.125 * (B[t6 + 1][t10][t12] - 2 * B[t6][t10][t12] + B[t6 - 1][t10][t12]) + 0.125 * (B[t6][t10 + 1][t12] - 2 * B[t6][t10][t12] + B[t6][t10 - 1][t12]) + 0.125 * (B[t6][t10][t12 + 1] - 2 * B[t6][t10][t12] + B[t6][t10][t12 - 1]) + B[t6][t10][t12];
  }
}
