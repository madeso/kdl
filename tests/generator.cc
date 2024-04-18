#include <iostream>
#include <string>
#include <fstream>

enum ARGUMENTS
{
	ARG_APP_PATH,
	ARG_NAME,
	ARG_INPUT,
	ARG_EXPECTED,
	ARG_OUTPUT,
	ARG_COUNT
};

int main(int argc, char* argv[])

{
	if (argc != ARG_COUNT)
	{
		std::cerr << "bad usage\n" << argc;
		return -1;
	}

	const std::string name = argv[ARG_NAME];

	std::ifstream input;
	input.open(argv[ARG_INPUT]);
	if (! input)
	{
		std::cerr << "Failed to open input\n";
		return -1;
	}

	std::ifstream expected;
	expected.open(argv[ARG_EXPECTED]);

	std::ofstream out;
	out.open(argv[ARG_OUTPUT]);
	if (! out)
	{
		std::cerr << "Failed to open out\n";
		return -1;
	}

	std::string line;

	out << "#include \"catch.hpp\"\n";
	out << "#include \"kdlh/kdlh.h\"\n";
	out << "\n";
	out << "using namespace kdlh;\n";
	out << "\n";
	out << "TEST_CASE(\"" << name << "\")\n";
	out << "{\n";
	out << "\tconst auto loaded = ParseString(R\"kdl(\n";
	while (input)
	{
		std::getline(input, line);
		out << line;
	}
	out << ")kdl\");\n";

	if (expected.good() == false)
	{
		out << "\tREQUIRE(loaded.has_error());\n";
	}
	else
	{
		out << "\tREQUIRE(loaded.has_error() == false);\n";
		out << "\tconst auto str = ToString(*loaded.doc);\n";
		out << "\tREQUIRE(str == R\"kdl(\n";
		while (expected)
		{
			std::getline(expected, line);
			out << line;
		}
		out << ")kdl\");\n";
	}

	out << "}\n";

	return 0;
}
