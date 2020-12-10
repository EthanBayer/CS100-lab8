
#include "../headers/vectorcontainer.hpp"
#include <iostream>

// void VectorContainer::set_sort_function(Sort* sort_function)
// {
//     this->sort_function = sort_function;
// }

void VectorContainer::add_element(Base* element)
{
    expression.push_back(element);
}

void VectorContainer::print()
{
    for (int i = 0; i < expression.size(); i++)
    {
        std::cout << std::setw(65) << expression.at(i)->stringify() <<  " = " << expression.at(i)->evaluate() << std::endl;
    }
}

void VectorContainer::sort()
{
    if (sort_function)
    {
        sort_function->sort(this);
    }
    else
    {
        throw std::runtime_error("No sort function set");
    }
    
}

void VectorContainer::swap(int i, int j)
{
    Base* temp = expression.at(i);
    expression.at(i) = expression.at(j);
    expression.at(j) = temp;
}

Base* VectorContainer::at(int i)
{
    return expression.at(i);
}

int VectorContainer::size()
{
    return expression.size();
}