
#include "../headers/bubblesort.hpp"

void BubbleSort::sort(Container* container)
{
    for (int i = 0; i < container->size() - 1; i++)
        {
            for (int j = 0; j < container->size() - i - 1; j++)
            {
                if (container->at(j)->evaluate() > container->at(j+1)->evaluate())
                {
                    container->swap(j, j + 1);
                }
            }
        }
}