// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/heat-3d/kernel.c' as parsed by frontend compiler rose

void kernel_heat_3d(int tsteps, int n, double A[120 + 0][120 + 0][120 + 0], double B[120 + 0][120 + 0][120 + 0]) {
  int t14;
  int t12;
  int t10;
  int t8;
  int t6;
  int t4;
  int t2;
  for (t2 = 1; t2 <= 500; t2 += 1) {
    #pragma omp parallel for private(t4,t8,t10,t12,t14)
    for (t4 = 1; t4 <= n - 2; t4 += 16) 
      for (t6 = t4; t6 <= (t4 + 15 < n - 2 ? t4 + 15 : n - 2); t6 += 1) 
        for (t8 = 1; t8 <= n - 2; t8 += 64) 
          for (t10 = t8; t10 <= (n - 2 < t8 + 63 ? n - 2 : t8 + 63); t10 += 1) 
            for (t12 = 1; t12 <= n - 2; t12 += 16) 
              for (t14 = t12; t14 <= (n - 2 < t12 + 15 ? n - 2 : t12 + 15); t14 += 1) 
                B[t6][t10][t14] = 0.125 * (A[t6 + 1][t10][t14] - 2 * A[t6][t10][t14] + A[t6 - 1][t10][t14]) + 0.125 * (A[t6][t10 + 1][t14] - 2 * A[t6][t10][t14] + A[t6][t10 - 1][t14]) + 0.125 * (A[t6][t10][t14 + 1] - 2 * A[t6][t10][t14] + A[t6][t10][t14 - 1]) + A[t6][t10][t14];
    #pragma omp parallel for private(t4,t8,t10,t12,t14)
    for (t4 = 1; t4 <= n - 2; t4 += 16) 
      for (t6 = t4; t6 <= (t4 + 15 < n - 2 ? t4 + 15 : n - 2); t6 += 1) 
        for (t8 = 1; t8 <= n - 2; t8 += 64) 
          for (t10 = t8; t10 <= (n - 2 < t8 + 63 ? n - 2 : t8 + 63); t10 += 1) 
            for (t12 = 1; t12 <= n - 2; t12 += 16) 
              for (t14 = t12; t14 <= (n - 2 < t12 + 15 ? n - 2 : t12 + 15); t14 += 1) 
                A[t6][t10][t14] = 0.125 * (B[t6 + 1][t10][t14] - 2 * B[t6][t10][t14] + B[t6 - 1][t10][t14]) + 0.125 * (B[t6][t10 + 1][t14] - 2 * B[t6][t10][t14] + B[t6][t10 - 1][t14]) + 0.125 * (B[t6][t10][t14 + 1] - 2 * B[t6][t10][t14] + B[t6][t10][t14 - 1]) + B[t6][t10][t14];
  }
}
