#pragma once

#include <common.h>
#include <bar_export.h>

#ifndef SWIG
#include <string>
#endif

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
