#include "../headers/SelectionSort.hpp"

void SelectionSort::sort(Container* container){
    for (int i = 0; i < container->size(); i++){
        for (int j = i + 1; j < container->size(); j++){
            if(container->at(j)->evaluate() < container->at(i)->evaluate()){
                container->swap(i,j);
            }
        }
    }
}