// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/heat-3d/kernel.c' as parsed by frontend compiler rose

void kernel_heat_3d(int tsteps, int n, double A[120 + 0][120 + 0][120 + 0], double B[120 + 0][120 + 0][120 + 0]) {
  int t14;
  int t12;
  int t10;
  int t8;
  int t6;
  int t4;
  int t2;
  if (3 <= n) 
    for (t2 = 1; t2 <= 500; t2 += 1) {
      for (t4 = 1; t4 <= n - 2; t4 += 8) 
        for (t6 = 1; t6 <= n - 2; t6 += 32) 
          for (t8 = 1; t8 <= n - 2; t8 += 128) 
            for (t10 = t4; t10 <= (t4 + 7 < n - 2 ? t4 + 7 : n - 2); t10 += 1) 
              for (t12 = t6; t12 <= (t6 + 31 < n - 2 ? t6 + 31 : n - 2); t12 += 1) 
                for (t14 = t8; t14 <= (t8 + 127 < n - 2 ? t8 + 127 : n - 2); t14 += 1) 
                  B[t10][t12][t14] = 0.125 * (A[t10 + 1][t12][t14] - 2 * A[t10][t12][t14] + A[t10 - 1][t12][t14]) + 0.125 * (A[t10][t12 + 1][t14] - 2 * A[t10][t12][t14] + A[t10][t12 - 1][t14]) + 0.125 * (A[t10][t12][t14 + 1] - 2 * A[t10][t12][t14] + A[t10][t12][t14 - 1]) + A[t10][t12][t14];
      for (t4 = 1; t4 <= n - 2; t4 += 8) 
        for (t6 = 1; t6 <= n - 2; t6 += 32) 
          for (t8 = 1; t8 <= n - 2; t8 += 128) 
            for (t10 = t4; t10 <= (t4 + 7 < n - 2 ? t4 + 7 : n - 2); t10 += 1) 
              for (t12 = t6; t12 <= (t6 + 31 < n - 2 ? t6 + 31 : n - 2); t12 += 1) 
                for (t14 = t8; t14 <= (t8 + 127 < n - 2 ? t8 + 127 : n - 2); t14 += 1) 
                  A[t10][t12][t14] = 0.125 * (B[t10 + 1][t12][t14] - 2 * B[t10][t12][t14] + B[t10 - 1][t12][t14]) + 0.125 * (B[t10][t12 + 1][t14] - 2 * B[t10][t12][t14] + B[t10][t12 - 1][t14]) + 0.125 * (B[t10][t12][t14 + 1] - 2 * B[t10][t12][t14] + B[t10][t12][t14 - 1]) + B[t10][t12][t14];
    }
}