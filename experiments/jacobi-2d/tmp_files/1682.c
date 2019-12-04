void kernel_jacobi_2d(int tsteps,
       int n,
       double A[ 1300 + 0][1300 + 0],
	          double B[ 1300 + 0][1300 + 0])
	   {
  int t, i, j;

 for (t = 0; t < tsteps; t++)
    {
#pragma clang loop(i1, j1) tile sizes(32, 64)
#pragma clang loop id(i1)
		for (i = 1; i < n - 1; i++)
#pragma clang loop id(j1)
 for (j = 1; j < n - 1; j++)
   B[i][j] = 0.2 * (A[i][j] + A[i][j-1] + A[i][1+j] + A[1+i][j] + A[i-1][j]);
#pragma clang loop id(i2, j2) tile sizes(32, 64)
#pragma clang loop id(i2)
      for (i = 1; i < n - 1; i++)
#pragma clang loop id(j2)
 for (j = 1; j < n - 1; j++)
   A[i][j] = 0.2 * (B[i][j] + B[i][j-1] + B[i][1+j] + B[1+i][j] + B[i-1][j]);
    }

}
