#include "../headers/ListContainer.hpp"

void ListContainer::add_element(Base* element) {
    operations.push_back(element);
}

void ListContainer::print() {
    for (auto element : operations){
        std::cout << std::setw(65) <<  element->stringify() <<  " = " << element->evaluate() << std::endl;
    }
}

void ListContainer::sort(){
    if(sort_function){
        sort_function->sort(this);
    }
    else{
        throw std::runtime_error("sort_function not set");
    }
}

void ListContainer::swap(int i, int j){
    auto op1 = operations.begin(); std::advance(op1,i);
    auto op2 = operations.begin(); std::advance(op2,j);

    std::swap(*op1,*op2);
}

Base* ListContainer::at(int i) {
    auto tempItr = operations.begin();
    std::advance(tempItr, i);
    return *tempItr;
}

int ListContainer::size(){
    return operations.size();
}