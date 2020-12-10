#ifndef LISTCONTAINER_HPP
#define LISTCONTAINE_HPP

#include <list>
#include "container.hpp"
#include <stdexcept>
#include <iostream>
#include <iomanip>


class ListContainer : public Container {
private:
    std::list<Base*> operations;
public:
    void add_element(Base* element);
    void print();
    void sort();
    void swap(int i, int j);
    Base* at(int i);
    int size();
}; 


#endif // LISTCONTAINER_HPP