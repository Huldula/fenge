#pragma once

#include "Core/Error.h"
#include "Token.h"
#include "Nodes.h"

namespace fenge {

class ParserResult {
public:
	Error error;
	Node* node{ nullptr };

	[[nodiscard]] std::string toString() const;
};

class Parser
{
public:
	explicit Parser(const std::vector<Token*>& input);

	ParserResult parse();
	ParserResult parseBinary(ParserResult(Parser::* toCall)(), bool isType(Token::Type));

	ParserResult parseLogOr();
	ParserResult parseLogXor();
	ParserResult parseLogAnd();
	ParserResult parseCompEq();
	ParserResult parseCompRela();
	ParserResult parseMathAdd();
	ParserResult parseMathMul();
	ParserResult parseBitOr();
	ParserResult parseBitXor();
	ParserResult parseBitAnd();
	ParserResult parseUnary();
	ParserResult parseSimple();
	//ParserResult* parseBinary(ParserResult* (Parser::* func)());

	//ParserResult* parseUnaryExpr();
private:
	int pos_;
	Token* advance();
	Token* peek();
	Token* currentToken_;
	const std::vector<Token*>& input_;
};

}
