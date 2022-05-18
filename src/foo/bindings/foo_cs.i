%module foo_cs

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
#include "foo_export.h"
#include "foo.h"
%}

SWIG_CSBODY_PROXY(public, public, SWIGTYPE)
SWIG_CSBODY_TYPEWRAPPER(public, public, public, SWIGTYPE)


// %ignore ""; // ignore all
// %define %unignore %rename("%s") %enddef

// %unignore bar;
// namespace bar {
// %rename("StringVectorOutput") stringVectorOutput(int);
// %rename("StringVectorInput") stringVectorInput(std::vector<std::string>);
// %rename("StringVectorRefInput") stringVectorRefInput(const std::vector<std::string>&);

// %unignore stringJaggedArrayOutput(int);
// %unignore stringJaggedArrayInput(std::vector<std::vector<std::string>>);
// %unignore stringJaggedArrayRefInput(const std::vector<std::vector<std::string>>&);

// %rename("PairVectorOutput") pairVectorOutput(int);
// %rename("PairVectorInput") pairVectorInput(std::vector<std::pair<int, int>>);
// %rename("PairVectorRefInput") pairVectorRefInput(const std::vector<std::pair<int, int>>&);

// %rename("PairJaggedArrayOutput") pairJaggedArrayOutput(int);
// %rename("PairJaggedArrayInput") pairJaggedArrayInput(std::vector<std::vector<std::pair<int, int>>>);
// %rename("PairJaggedArrayRefInput") pairJaggedArrayRefInput(const std::vector<std::vector<std::pair<int, int>>>&);

// %rename("FreeFunction") freeFunction(int);
// %rename("FreeFunction") freeFunction(int64_t);

// %unignore Bar;
// %rename("StaticFunction") Bar::staticFunction(int);
// %rename("StaticFunction") Bar::staticFunction(int64_t);

// %rename("GetInt") Bar::getInt() const;
// %rename("SetInt") Bar::setInt(int);

// %rename("GetInt64") Bar::getInt64() const;
// %rename("SetInt64") Bar::setInt64(int64_t);

// %rename ("ToString") Bar::operator();
// } // namespace bar


// Process symbols in header
%include "foo_export.h"
%include "foo.h"

// %unignore ""; // unignore all
