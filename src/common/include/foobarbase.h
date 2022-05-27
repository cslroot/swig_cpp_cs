#pragma once

#include <common_export.h>

#include <string>

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
