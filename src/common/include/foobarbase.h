#pragma once

#include <common_export.h>

#ifndef SWIG
#include <string>
#endif

namespace cs
{
  namespace common
  {
    class COMMON_EXPORT FooBarBase
    {
    public:
      virtual ~FooBarBase();
      virtual std::string GetName() const = 0;

    private:
    };

  } // namespace common
} // namespace cs
