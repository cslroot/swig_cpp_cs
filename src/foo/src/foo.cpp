#include "foo.h"

using namespace cs::foo;

std::string Foo::GetName() const { return "Foo"; }
Foo& Foo::Append(int n) {
	m_data += n;
	return *this;
}