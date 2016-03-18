class int_array {
  int* ns;
public:
  `\only<3->{\tt\bfseries const }`int& at(int index)`\only<2->{ \tt\bfseries const}`
  {
    return ns[index];
  }
};

const int_array arr;
int x = arr.at(0);
