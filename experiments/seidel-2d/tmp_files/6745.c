// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/seidel-2d/kernel.c' as parsed by frontend compiler rose

void kernel_seidel_2d(int tsteps, int n, double A[2000 + 0][2000 + 0]) {
  int t10;
  int t8;
  int t6;
  int t4;
  int t2;
  for (t2 = 0; t2 <= tsteps - 1; t2 += 1) 
    for (t4 = 1; t4 <= n - 2; t4 += 16) 
      for (t6 = t4; t6 <= (t4 + 15 < n - 2 ? t4 + 15 : n - 2); t6 += 1) 
        for (t8 = 1; t8 <= n - 2; t8 += 16) 
          for (t10 = t8; t10 <= (t8 + 15 < n - 2 ? t8 + 15 : n - 2); t10 += 1) 
            A[t6][t10] = (A[t6 - 1][t10 - 1] + A[t6 - 1][t10] + A[t6 - 1][t10 + 1] + A[t6][t10 - 1] + A[t6][t10] + A[t6][t10 + 1] + A[t6 + 1][t10 - 1] + A[t6 + 1][t10] + A[t6 + 1][t10 + 1]) / 9;
}
