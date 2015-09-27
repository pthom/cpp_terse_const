#include <vector>
#include <iostream>
#include <string>

#include "cpp_terse_const/const_typedefs.h"

//
//  Part 1 : Demonstrate const_typedefs
//
const_typedefs(int);				// _int <-> const int  / _int_ <-> const int & / int_ <-> int & 
const_typedefs_ns(std, string);   // std::_string <-> const std::string / std::_string_ <-> const std::string & / std::string_ <-> std::string &

class Foo
{
public:
  Foo(std::_string_ s) : mThing(s) { }
  std::_string_ getThing() const //i.e const std::string& getThing() const
  {
    return mThing;
  }

  void setThing(std::_string_ ch) 
  { 
    mThing = ch; 
  }

private:
  std::string mThing;
};
const_typedefs(Foo);

void showFooThing(_Foo_ foo) // ie void showFooThing(const Foo & foo)
{
  std::_string_ thing = foo.getThing(); //const std::string & c = g.getThing();
  std::cout << thing << std::endl;  
}

_int sample_const_typedefs()
{
  _int k = 1; // _int stands for "const int"
  //k++; // this line would not compile (const correctness)

  _Foo foo("foo"); //const Foo g("aa")
  //foo.setBlah("qdqs"); //this line would not compile (const correctness) 
  showFooThing(foo);
  
  return k;
}
