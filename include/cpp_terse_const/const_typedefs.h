//
// const_typedefs
//

//const_typedefs adds some syntactic sugar in order to help people adopt "const by default"
//IMHO it can make the code more readable (less "const" noise), and faster to write

//For any given type "MyTpe", const_typedefs will define three new types
// _MyType  <=> const MyType
// _MyType_ <=> const MyType &
//  MyType_ <=> MyType &
#define const_typedefs(MyType) \
  typedef const MyType _##MyType; \
  typedef const MyType & _##MyType##_;\
  typedef MyType &  MyType##_;  

//namespacify is just a helper macro
#define namespacify(namespce, _what) \
  namespace namespce \
  { \
    _what \
  }\

//const_typedefs_ns : is const_typedefs inside a namespace
#define const_typedefs_ns(namespce, MyType) namespacify(namespce, const_typedefs(MyType))
