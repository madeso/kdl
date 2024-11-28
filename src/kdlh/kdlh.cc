#include "kdlh/kdlh.h"

namespace kdlh
{

ParseResult ParseString(std::string_view source)
{
	return {"parsing not implemented"};
}

bool ParseResult::has_error() const
{
	return std::holds_alternative<std::string>(data);
}

std::string_view ParseResult::get_error() const
{
	if(has_error()) return std::get<std::string>(data);
	else return "";
}

const Document& ParseResult::require_doc() const
{
	return std::get<Document>(data);
}

std::string ToString(const Document&)
{
	return "";
}

}  //  namespace kdlh
