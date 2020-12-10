#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    private:
        double elem;
    public:
        Op(): elem(0) { }
        Op(double value) : elem(value) { }
        virtual double evaluate() { return elem; }
        virtual std::string stringify() { return std::to_string(elem); }

        virtual Iterator* create_iterator()
        {
            NullIterator* ni = new NullIterator(this);
            return ni;
        }
        virtual Base* get_left()
        {
            return nullptr;
        }
        virtual Base* get_right()
        {
            return nullptr;
        }
        virtual void accept(CountVisitor* cv)
        {
            cv->visit_op();
        }
};

#endif //__OP_HPP__
