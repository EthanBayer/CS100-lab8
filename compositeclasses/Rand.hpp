#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <random>
#include <time.h>

class Rand : public Base {
    private:
        double elem;
    public:
        Rand(){
            srand(time(NULL));
            elem = rand() % 100;
        }
        virtual double evaluate() { 
            return elem; 
        }
        virtual std::string stringify() { return std::to_string(elem); }

        void accept(CountVisitor* visitor){
            visitor->visit_rand();
        }
        
        Iterator* create_iterator(){
            return new NullIterator(this);
        }
        Base* get_left(){
            return nullptr;
        }
        Base* get_right(){
            return nullptr;
        }
};

#endif //__RAND_HPP__
