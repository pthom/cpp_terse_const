# cpp_terse_const 
This a simple attempt to provide answer to two common issues when trying to enforce const-correctness on C++ code :
- initialization of a complex const variable
- verbosity and readability


## const_initialize 
const_initialize aims to make it easy to instantiate a const variable, even when its initialization is complex.

This is inspired by an article from Herb Sutter: 
http://herbsutter.com/2013/04/05/complex-initialization-for-a-const-variable/

The example below shows the idiomatic C++14 of initializating a complex const variable through a lambda. 

```
//construct and initialize vec
//of type const std::vector<int>
const auto vec = [&]() { //define a lambda that initializes the vector
  std::vector<int> _vec;
  for (unsigned i = 0; i < 10; i++)  
    vec.push_back(i);  
  return _vec;
}(); //run the lambda immediately
```


const_initialize is an attempt to make this code shorter and easier to read. 
With this macro, the previous code can be rewritten as:
```
const_initialize( std::vector<int>, vec,  // here, we define the type and name of the const variable.
  for (unsigned i = 0; i < 10; i++)  //initialization code
    vec.push_back(i);
);  
```

##### Remark
Some people (such a me) like to disable variable shadowing (i.e add -Wshadow to the gcc flags)
This macro is not compatible with that option
We would need a better preprocessor !


# const_typedefs

This one is more controversial...
I think that const ought to be the default, and we should not spend time reading and writing const in any given source code.

So, the philosophy is, for any given class `Foo`to make its const variants very easy and fast to read and write :
  * `_Foo` is a typedef for `const Foo`
  * `_Foo_` is a typedef for `const Foo &`
  * `Foo_`is a typedef for `Foo &`

Example : 
```
  const_typedefs_ns(std, string);
  /*
  After this call :
  std::_string <-> const std::string
  std::_string_ <-> const std::string &
  std::string_ <-> std::string &
  */
   
  void showString(std::_string_ msg) // const std::string &
  {
    std::cout << msg;
  }

  int main()
  {
    std::_string msg{"hello"}; //const std::string
    showString(msg);
  }
```




