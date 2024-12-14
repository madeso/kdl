#pragma once

#include <string_view>
#include <string>
#include <optional>
#include <variant>
#include <vector>
#include <unordered_map>
#include <cstdint>

namespace kdlh
{

struct ValueType;
struct Node;
struct Document;

struct ParseResult;

// ---------------------------------------------------------------------------

struct ValueType
{
	std::optional<std::string> type;
	std::variant<std::string,
	int8_t, int16_t, int32_t, int64_t,
	uint8_t, uint16_t, uint32_t, uint64_t,
	float, double,
	bool> value;
};

using Value = std::optional<ValueType>; // null == std::nullopt

struct Node
{
	std::optional<std::string> type;
	std::string name;

	std::unordered_map<std::string, Value> properties;
	std::vector<Value> arguments;
	std::optional<std::vector<Node>> children;
};

struct Document
{
	std::vector<Node> nodes;
};

// ---------------------------------------------------------------------------

struct Message
{
	int line;
	int offset;
	std::string text;
};

struct ParseResult
{
	bool has_error() const;

	std::string get_error() const;
	const Document& require_doc() const;

	std::optional<Document> document;
	std::vector<Message> messages;
};

ParseResult ParseString(std::string_view source);
std::string ToString(const Document& doc);

}  //  namespace kdlh
