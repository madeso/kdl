#include "kdlh/kdlh.h"

namespace kdlh
{

ParseResult ParseString(std::string_view source)
{
	return {};
}

bool ParseResult::has_error() const
{
	return doc.has_value() == false;
}

std::string ToString(const Document&)
{
	return "";
}

}  //  namespace kdlh
