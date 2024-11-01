//
// Created by xiaoxianghui on 2024/10/31.
//

#ifndef TEST_CPP_CALCULATOR_H
#define TEST_CPP_CALCULATOR_H

#include <vector>

// 1+5*8-9(8+6)/2+sin(2pi)
namespace calc {
    class expr {
        std::vector<expr> sub;
    };
    class multExpr : public expr {
        enum {

        } token;
    };
    class calculator {
        expr current;
        std::vector<expr> history;
    };
}

#endif //TEST_CPP_CALCULATOR_H
