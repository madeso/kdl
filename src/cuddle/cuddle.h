#pragma once

#include <string_view>
#include <string>
#include <optional>

namespace cuddle
{

struct Document
{
};

struct ParseResult
{
	bool has_error() const;
	std::optional<Document> doc;
};

ParseResult ParseString(std::string_view source);
std::string ToString(const Document& doc);

}  //  namespace cuddle
