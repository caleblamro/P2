#ifndef __PARSER__H__
#define __PARSER__H__
#include "lexer.h"
#include "CFG.h"

class Parser{
    public:
        Parser(LexicalAnalyzer&);
        CFG parse_input();
        CFG parse_rule_list(std::vector<std::pair<Token, std::vector<Token>>>&);
        std::pair<Token, std::vector<Token>> parse_rule();
        std::vector<Token> parse_rhs();
        void parse_id_list(std::vector<Token>&);
        Token parse_id();
        Token expect(TokenType);
    private:
        LexicalAnalyzer lexer;
};

#endif  //__PARSER__H__