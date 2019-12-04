void kernel_fdtd_2d(int tmax,
      int nx,
      int ny,
      double ex[ 1000 + 0][1200 + 0],
	        double ey[ 1000 + 0][1200 + 0],
			      double hz[ 1000 + 0][1200 + 0],
				        double _fict_[ 500 + 0])
{
  int t, i, j;


 for(t = 0; t < tmax; t++)
    {
      for (j = 0; j < ny; j++)
 ey[0][j] = _fict_[t];

#pragma clang loop(i1, j1) tile sizes(64, 128)
#pragma clang loop id(i1)
	  for (i = 1; i < nx; i++)
#pragma clang loop id(j1)
 for (j = 0; j < ny; j++)
   ey[i][j] = ey[i][j] - 0.5*(hz[i][j]-hz[i-1][j]);
#pragma clang loop(i2, j2) tile sizes(64, 128)
#pragma clang loop id(i2)
      for (i = 0; i < nx; i++)
#pragma clang loop id(j2)
 for (j = 1; j < ny; j++)
   ex[i][j] = ex[i][j] - 0.5*(hz[i][j]-hz[i][j-1]);
#pragma clang loop(i3, j3) tile sizes(64,128)
#pragma clang loop id(i3)
      for (i = 0; i < nx - 1; i++)
#pragma clang loop id(j3)
 for (j = 0; j < ny - 1; j++)
   hz[i][j] = hz[i][j] - 0.7* (ex[i][j+1] - ex[i][j] +
           ey[i+1][j] - ey[i][j]);
    }

}
