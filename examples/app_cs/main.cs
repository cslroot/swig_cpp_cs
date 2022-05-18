using System;

namespace cs.app
{
public class Module {
  public static int Main(string[] args)
  {
    CS.Foo.Foo foo = new CS.Foo.Foo();
    CS.Bar.Bar bar = new CS.Bar.Bar();
    Console.WriteLine(foo.GetName());
    Console.WriteLine(bar.GetName());
    
    return 0;
  }
}
}