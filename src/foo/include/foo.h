#pragma once

#include <foo_export.h>

#ifndef SWIG
#include <string>
#endif

namespace cs
{
  namespace foo
  {
    class FOO_EXPORT FooBarBase
    {
    public:
      virtual std::string GetName() const = 0;

    private:
    };

    class FOO_EXPORT Foo : public FooBarBase
    {
    public:
      std::string GetName() const;
      Foo &Append(int n);

    private:
      int m_data = 0;
    };

  } // namespace foo

} // namespace cs
