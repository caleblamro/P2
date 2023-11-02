#include "CFG.h"
#include <iostream>


// CFG class definitions
CFG::CFG(const std::vector<std::pair<Token, std::vector<Token>>>& rules) : rules(rules) {
}

void CFG::print() const {
    for (const auto& rule : rules) {
        std::cout << "Rule: ";
        rule.first.Print();  // Print LHS
        std::cout << " -> ";
        for (const auto& token : rule.second) {
            token.Print();  // Print each token in RHS
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

const std::vector<std::pair<Token, std::vector<Token>>>& CFG::getRules() {
    return rules;
}