#pragma once

#include <common.h>
#include <bar_export.h>

#include <string>

namespace cs
{
  namespace bar
  {
    class BAR_EXPORT Bar : public cs::common::FooBarBase
    {
    public:
      std::string GetName() const;

    private:
    };
  } // namespace foo

} // namespace cs
