# swig_cpp_cs

example code in order to generate c# from c++ via swig.


* foo
  * C++ library using a class in bar as base class
* bar
  * C++ library
* myConsoleApp
  * deps. myClassLib -> myClassLibBase
* myWinFormsApp
  * Windows forms application
* myWPFApp
  * WPF application

## limitations

* used Visual Studio as generator
* not supported linux and dotnet
