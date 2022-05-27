#pragma once

#include <foo_export.h>
#include <common.h>

#include <string>

namespace cs
{
  namespace foo
  {
    class FOO_EXPORT Foo : public cs::common::FooBarBase
    {
    public:
      std::string GetName() const;
      Foo &Append(int n);

    private:
      int m_data = 0;
    };

  } // namespace foo

} // namespace cs
