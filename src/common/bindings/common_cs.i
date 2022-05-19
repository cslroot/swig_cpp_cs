%module common_cs

%include "stdint.i"
%include "std_vector.i"
%include "std_string.i"
%include "std_array.i"
%include "std_pair.i"
%include "cpointer.i"
%include "stdint.i"

%include "windows.i"

// Add necessary symbols to generated header
%{
#include "common_export.h"
#include "common.h"
%}

SWIG_CSBODY_PROXY(public, public, SWIGTYPE)
SWIG_CSBODY_TYPEWRAPPER(public, public, public, SWIGTYPE)

// Process symbols in header
%include "common_export.h" 
%include "common.h"
