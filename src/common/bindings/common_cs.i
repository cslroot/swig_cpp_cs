%module common_cs

%include "stdint.i"
%include "std_vector.i"
%include "std_string.i"
%include "std_array.i"
%include "std_pair.i"
%include "cpointer.i"
%include "stdint.i"

%include "windows.i"

%typemap(csimports) cs::bar::Bar
%{
using CS.Foo;
%}
%import "../../foo/bindings/foo_cs.i"

// Add necessary symbols to generated header
%{
#include "bar_export.h"
#include "bar.h"
%}

SWIG_CSBODY_PROXY(public, public, SWIGTYPE)
SWIG_CSBODY_TYPEWRAPPER(public, public, public, SWIGTYPE)

// Process symbols in header
%include "bar_export.h" 
%include "bar.h"
