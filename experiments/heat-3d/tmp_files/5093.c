void kernel_heat_3d(int tsteps,
        int n,
        double A[200 + 0][200 + 0][200 + 0],
		        double B[200 + 0][200 + 0][200 + 0])
{
  int t, i, j, k;


  for (t = 1; t <= 1000; t++) {
#pragma clang loop(i1, j1) tile sizes(8, 16)
#pragma clang loop id(i1)
        for (i = 1; i < n-1; i++) {
#pragma clang loop id(j1)
            for (j = 1; j < n-1; j++) {
//#pragma clang loop id(k1)
                for (k = 1; k < n-1; k++) {
                    B[i][j][k] = 0.125 * (A[i+1][j][k] - 2.0 * A[i][j][k] + A[i-1][j][k])
                                 + 0.125 * (A[i][j+1][k] - 2.0 * A[i][j][k] + A[i][j-1][k])
                                 + 0.125 * (A[i][j][k+1] - 2.0 * A[i][j][k] + A[i][j][k-1])
                                 + A[i][j][k];
                }
            }
        }
#pragma clang loop(i2, j2) tile sizes(8, 16)
#pragma clang loop id(i2)
        for (i = 1; i < n-1; i++) {
#pragma clang loop id(j2)
           for (j = 1; j < n-1; j++) {
//#pragma clang loop id(k2)
               for (k = 1; k < n-1; k++) {
                   A[i][j][k] = 0.125 * (B[i+1][j][k] - 2.0 * B[i][j][k] + B[i-1][j][k])
                                + 0.125 * (B[i][j+1][k] - 2.0 * B[i][j][k] + B[i][j-1][k])
                                + 0.125 * (B[i][j][k+1] - 2.0 * B[i][j][k] + B[i][j][k-1])
                                + B[i][j][k];
               }
           }
       }
    }

}
