#ifndef __CFG__H__
#define __CFG__H__
#include "lexer.h"
#include <vector>


class CFG{
    public:
        CFG(const std::vector<std::pair<Token, std::vector<Token>>>& rules);
        const std::vector<std::pair<Token, std::vector<Token>>>& getRules();
        void print() const;
    private:
        std::vector<std::pair<Token, std::vector<Token>>> rules;
};

#endif  // __CFG__H__