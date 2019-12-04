void kernel_seidel_2d(int tsteps,
        int n,
        double A[ 2000 + 0][2000 + 0])
{
  int t, i, j;

 for (t = 0; t <= tsteps - 1; t++)
#pragma clang loop(i1,i2) tile sizes(32,16)
#pragma clang loop id(i1)
    for (i = 1; i<= n - 2; i++)
#pragma clang loop id(i2)
      for (j = 1; j <= n - 2; j++)
 A[i][j] = (A[i-1][j-1] + A[i-1][j] + A[i-1][j+1]
     + A[i][j-1] + A[i][j] + A[i][j+1]
     + A[i+1][j-1] + A[i+1][j] + A[i+1][j+1])/9.0;

}
