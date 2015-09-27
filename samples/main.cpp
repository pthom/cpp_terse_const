#include <iostream>

void sample_const_initialize();
const int sample_const_typedefs();


int main()
{
  int k = sample_const_typedefs();
  std::cout << k << std::endl;
  
  sample_const_initialize();
}