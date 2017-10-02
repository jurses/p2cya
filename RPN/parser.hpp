#ifndef PARSER_H
#define PARSER_H
#include <string>

namespace CYA{
	bool lessPrec(const char, const char);
	bool isOp(const char);	// is an operator
	std::string inf2Pos(std::string);
}

#endif	// PARSER_H