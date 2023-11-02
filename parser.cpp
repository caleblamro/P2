#include "parser.h"
#include <iostream>

class DifferentTokenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Different token found than expected";
    }
};

Parser::Parser(LexicalAnalyzer& lexer) : lexer(lexer){}  // Pass by reference

Token Parser::expect(TokenType t) {
    Token token = lexer.GetToken();
    if(token.token_type != t) {
        throw DifferentTokenException();
    }
    return token;
}

CFG Parser::parse_input() {
    std::vector<std::pair<Token, std::vector<Token>>> rules;
    CFG parsed_cfg = parse_rule_list(rules);
    parsed_cfg.print();
    try{
        expect(TokenType::HASH);
    }catch(const DifferentTokenException& e) {
        std::cout << "Invalid input, expected hash" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return parsed_cfg;
}

CFG Parser::parse_rule_list(std::vector<std::pair<Token, std::vector<Token>>>& rules) {
    std::pair<Token, std::vector<Token>> rule = parse_rule();
    rules.push_back(rule);
    Token t = lexer.peek(1);
    if(t.token_type == TokenType::HASH) {
        return CFG(rules);
    }
    parse_rule_list(rules);
}

std::pair<Token, std::vector<Token>> Parser::parse_rule() {
    Token lhs;
    try{
        lhs = expect(TokenType::ID);
    }catch(const DifferentTokenException& e) {
        std::cout << "Invalid rule expected ID" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    try{
        expect(TokenType::ARROW);
    }catch(const DifferentTokenException& e) {
        std::cout << "Invalid rule expected arrow" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    std::vector<Token> rhs;
    rhs = parse_rhs();
    try{
        expect(TokenType::STAR);
    }catch(const DifferentTokenException& e) {
        std::cout << "Invalid rule expected star" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return std::make_pair(lhs, rhs);
}

std::vector<Token> Parser::parse_rhs() {
    std::vector<Token> rhs_list;
    parse_id_list(rhs_list);
    return rhs_list;
}

void Parser::parse_id_list(std::vector<Token>& rhs_list) {
    Token t = lexer.peek(1);
    if (t.token_type == TokenType::STAR) {
        return;
    }
    Token idToken = parse_id();
    rhs_list.push_back(idToken);
    parse_id_list(rhs_list);
}

Token Parser::parse_id() {
    // for now just return the token, we can make sure it is valid later
    return lexer.GetToken();
}