#pragma once

#include "Core/Error.h"
#include "Token.h"
#include "Nodes.h"

namespace fenge {

class ParserResult {
public:
	Error error{ ErrorCode::NO_ERROR };
	Node* node{ nullptr };

	[[nodiscard]] std::string toString() const;
};

class Parser
{
public:
	explicit Parser(const std::vector<Token*>& input);

	ParserResult* parse();
	ParserResult* parseLiteral();
	ParserResult* parseUnary();
	//ParserResult* parseBinary(ParserResult* (Parser::* func)());

	ParserResult* parseAddExpr();
	ParserResult* parseMulExpr();
	//ParserResult* parseUnaryExpr();
private:
	int pos_;
	Token* advance();
	Token* peek();
	Token* currentToken_;
	const std::vector<Token*>& input_;
};

}
