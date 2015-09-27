#include <vector>
#include <iostream>
#include "cpp_terse_const/const_initialize.h"


void myPrintVector(const std::vector<int> & vec) 
{
  for (auto val: vec)
    std::cout << val << std::endl;
}

void sample_const_initialize()
{
  const_initialize( std::vector<int>, vec,  //will instantiate and initialize const std::vector<int> vec
    for (unsigned i = 0; i < 10; i++)  //
      vec.push_back(i);                //this is just a simple example of a complex initialization block
    vec.pop_back();                    //
  );  
  myPrintVector(vec);  
}

