# swig_cpp_cs

example code in order to generate c# from c++ via swig.

* common
  * shared lib contains the base class of Foo and Bar
* foo
  * shared lib using common
* bar
  * shared lib using common
* app_cpp
  * C++ executable using foo, bar and common
* app_cs
  * C# executable using foo(C#), bar(C#), common(C#)

## limitations

* used Visual Studio as generator
* not supported linux and dotnet
