void kernel_jacobi_1d(int tsteps,
       int n,
       double A[ 4000 + 0],
	   double B[ 4000 + 0])
	   
{
  int t, i;

 for (t = 0; t < tsteps; t++)
    {
#pragma clang loop(i1) tile sizes(8)
#pragma clang loop id(i1)
		for (i = 1; i < n - 1; i++)
 B[i] = 0.33333 * (A[i-1] + A[i] + A[i + 1]);

#pragma clang loop(i2) tile sizes(8)
#pragma clang loop id(i2)
      for (i = 1; i < n - 1; i++)
 A[i] = 0.33333 * (B[i-1] + B[i] + B[i + 1]);
    }

}
