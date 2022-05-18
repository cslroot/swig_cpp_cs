#include <foo.h>
#include <bar.h>

#include <iostream>

using namespace std;
using namespace cs::foo;
using namespace cs::bar;

int main(int argc, char **argv)
{
  Foo foo_;
  Bar bar_;

  cout << foo_.GetName() << std::endl;
  cout << bar_.GetName() << std::endl;
}