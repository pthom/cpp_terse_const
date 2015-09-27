
//
// const_initialize
//

//const_initialize is a helper macro for complex initialization of a const variable
//cf http://herbsutter.com/2013/04/05/complex-initialization-for-a-const-variable/
//Example:
//const_initialize( std::vector<int>, vec, //vec will be a const std::vector
//  for (unsigned i = 0; i < 10; i++)  //This is the code that populates the vector
//  {
//    vec.push_back(i);      
//  }
//  vec.pop_back();
//);
#define const_initialize(type, name, initialization_code) \
  const auto name = [ & ]()                 \
  {                                         \
    type name;                              \
    initialization_code;                    \
    return name;                            \
  }();

//Remark : some people (such a me) like to disable variable shadowing (i.e add -Wshadow to the gcc flags)
//This macro is not compatible with that option
//We would need a better preprocessor !
