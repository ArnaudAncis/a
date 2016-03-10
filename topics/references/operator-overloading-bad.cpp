matrix<double,3,3> m = translation_matrix(1,0,0);
matrix<double,3,1> v = vector(x, y, z);

// Using pointers
matrix<double,3,1> result = *((&m) * (&v));

// What we want
matrix<double,3,1> result = m * v;
