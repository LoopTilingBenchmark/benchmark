// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/jacobi-2d/kernel.c' as parsed by frontend compiler rose

void kernel_jacobi_2d(int tsteps, int n, double A[1300 + 0][1300 + 0], double B[1300 + 0][1300 + 0]) {
  int t10;
  int t8;
  int t6;
  int t4;
  int t2;
  if (3 <= n) 
    for (t2 = 0; t2 <= tsteps - 1; t2 += 1) {
      for (t4 = 1; t4 <= n - 2; t4 += 16) 
        for (t6 = t4; t6 <= (n - 2 < t4 + 15 ? n - 2 : t4 + 15); t6 += 1) 
          for (t8 = 1; t8 <= n - 2; t8 += 64) 
            for (t10 = t8; t10 <= (n - 2 < t8 + 63 ? n - 2 : t8 + 63); t10 += 1) 
              B[t6][t10] = 0.20000000000000001 * (A[t6][t10] + A[t6][t10 - 1] + A[t6][1 + t10] + A[1 + t6][t10] + A[t6 - 1][t10]);
      for (t4 = 1; t4 <= n - 2; t4 += 16) 
        for (t6 = t4; t6 <= (n - 2 < t4 + 15 ? n - 2 : t4 + 15); t6 += 1) 
          for (t8 = 1; t8 <= n - 2; t8 += 64) 
            for (t10 = t8; t10 <= (n - 2 < t8 + 63 ? n - 2 : t8 + 63); t10 += 1) 
              A[t6][t10] = 0.20000000000000001 * (B[t6][t10] + B[t6][t10 - 1] + B[t6][1 + t10] + B[1 + t6][t10] + B[t6 - 1][t10]);
    }
}
