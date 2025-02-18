//
// Created by xiaoxianghui on 2024/12/13.
//

#ifndef TEST_CPP_EXPR_H
#define TEST_CPP_EXPR_H

#include <string>
#include <vector>

namespace calc {
    class expr {
    protected:
        enum class op {
            num, add, sub, mul, div,
        } token;

        std::vector<expr *> args;
    public:
        virtual bool eval() const = 0;

        virtual std::string toString() const = 0;

        virtual ~expr() {}

        virtual double getValue() const = 0;
    };

    class num final : public expr {
    public:
        num(double n) : n(n) { token = op::num; }

        bool eval() const override { return false; }

        std::string toString() const override { return std::to_string(n); }

        double getValue() const override { return n; }

    private:
        double n;
    };

    class add final : public expr {
    public:
        add(expr *lhs, expr *rhs) {
            token = op::add;
            args.push_back(lhs), args.push_back(rhs);
        }

        bool eval() const override { return args.at(0)->eval() + args.at(1)->eval(); }

        std::string toString() const override { return args.at(0)->toString() + " + " + args.at(1)->toString(); }

        double getValue() const override { return args.at(0)->getValue() + args.at(1)->getValue(); }
    };

    class sub final : public expr {
    public:
        sub(expr *lhs, expr *rhs) : lhs(lhs), rhs(rhs) { token = op::sub; }

        bool eval() const override { return lhs->eval() - rhs->eval(); }

        std::string toString() const override { return lhs->toString() + " - " + rhs->toString(); }

        double getValue() const override { return lhs->getValue() - rhs->getValue(); }

    private:
        expr *lhs;
        expr *rhs;
    };
}


#endif //TEST_CPP_EXPR_H
