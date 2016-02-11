const int N = 10000;
int* p[N];

for ( int i = 0; i < N; ++i )
  p[i] = new int[1];

for ( int i = 0; i < N; i += 2 )
  delete[] p[i];

