// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/jacobi-1d/kernel.c' as parsed by frontend compiler rose

void kernel_jacobi_1d(int tsteps, int n, double A[2000 + 0], double B[2000 + 0]) {
  int t6;
  int t4;
  int t2;
  if (3 <= n) 
    for (t2 = 0; t2 <= tsteps - 1; t2 += 1) {
      for (t4 = 1; t4 <= n - 2; t4 += 32) 
        for (t6 = t4; t6 <= (n - 2 < t4 + 31 ? n - 2 : t4 + 31); t6 += 1) 
          B[t6] = 0.33333000000000002 * (A[t6 - 1] + A[t6] + A[t6 + 1]);
      for (t4 = 1; t4 <= n - 2; t4 += 32) 
        for (t6 = t4; t6 <= (n - 2 < t4 + 31 ? n - 2 : t4 + 31); t6 += 1) 
          A[t6] = 0.33333000000000002 * (B[t6 - 1] + B[t6] + B[t6 + 1]);
    }
}
