#include "kdlh/kdlh.h"

#include <sstream>

namespace kdlh
{

ParseResult ParseString(std::string_view source)
{
	return {std::nullopt, {{-1, -1, "parsing not implemented"}}};
}

bool ParseResult::has_error() const
{
	return !document.has_value();
}

std::string ParseResult::get_error() const
{
	std::ostringstream ss;
	bool first = true;
	for(const auto& m: messages)
	{
		if(first) first = false;
		else ss << "\n";

		ss << "(" << m.line << ":" << m.offset << "): " << m.text;
	}
	return ss.str();
}

const Document& ParseResult::require_doc() const
{
	return *document;
}

std::string ToString(const Document&)
{
	return "";
}

}  //  namespace kdlh
