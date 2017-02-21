int* a = new int[4];
double* b = new double[3];
bool* c = new bool[4];
char* d = new char[12];

// Cannot be freed in different order
delete[] d;
delete[] c;
delete[] b;
delete[] a;
