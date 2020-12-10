#ifndef VECTORCONTAINER_HPP
#define VECTORCONTAINER_HPP

#include <vector>
#include <stdexcept>
#include <iomanip>
#include "sort.hpp"
#include "container.hpp"


//class Sort;

class VectorContainer : public Container
{
    private:
        std::vector<Base*> expression;

    public:
        //VectorContainer() : Container() {};
        //VectorContainer(Sort* function) : Container(function) {};

       // void set_sort_function(Sort* sort_function);

        void add_element(Base* element);

        void print();

        void sort();

        // Sort required functions
        void swap(int i, int j);

        Base* at(int i);

        int size();

};

#endif