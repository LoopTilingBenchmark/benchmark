// this source is derived from CHILL AST originally from file '/uufs/chpc.utah.edu/common/home/u1142914/lib/ytopt_vinu/polybench/polybench-code/stencils/fdtd-2d/kernel.c' as parsed by frontend compiler rose

void kernel_fdtd_2d(int tmax, int nx, int ny, double ex[2000 + 0][2600 + 0], double ey[2000 + 0][2600 + 0], double hz[2000 + 0][2600 + 0], double _fict_[1000 + 0]) {
  int t10;
  int t8;
  int t6;
  int t4;
  int t2;
  for (t2 = 0; t2 <= tmax - 1; t2 += 1) {
    for (t4 = 0; t4 <= ny - 1; t4 += 1) 
      ey[0][t4] = _fict_[t2];
    for (t4 = 1; t4 <= nx - 1; t4 += 16) 
      for (t6 = t4; t6 <= (t4 + 15 < nx - 1 ? t4 + 15 : nx - 1); t6 += 1) 
        for (t8 = 0; t8 <= ny - 1; t8 += 64) 
          for (t10 = t8; t10 <= (ny - 1 < t8 + 63 ? ny - 1 : t8 + 63); t10 += 1) 
            ey[t6][t10] = ey[t6][t10] - 0.5 * (hz[t6][t10] - hz[t6 - 1][t10]);
    for (t4 = 0; t4 <= nx - 1; t4 += 16) 
      for (t6 = t4; t6 <= (t4 + 15 < nx - 1 ? t4 + 15 : nx - 1); t6 += 1) 
        for (t8 = 1; t8 <= ny - 1; t8 += 64) 
          for (t10 = t8; t10 <= (ny - 1 < t8 + 63 ? ny - 1 : t8 + 63); t10 += 1) 
            ex[t6][t10] = ex[t6][t10] - 0.5 * (hz[t6][t10] - hz[t6][t10 - 1]);
    for (t4 = 0; t4 <= nx - 2; t4 += 16) 
      for (t6 = t4; t6 <= (t4 + 15 < nx - 2 ? t4 + 15 : nx - 2); t6 += 1) 
        for (t8 = 0; t8 <= ny - 2; t8 += 64) 
          for (t10 = t8; t10 <= (ny - 2 < t8 + 63 ? ny - 2 : t8 + 63); t10 += 1) 
            hz[t6][t10] = hz[t6][t10] - 0.69999999999999996 * (ex[t6][t10 + 1] - ex[t6][t10] + ey[t6 + 1][t10] - ey[t6][t10]);
  }
}
