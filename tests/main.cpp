
#include "../headers/iterator.hpp"
#include "../headers/visitor.hpp"
#include "../compositeclasses/Add.hpp"
#include "../compositeclasses/Sub.hpp"
#include "../compositeclasses/Pow.hpp"
#include "../compositeclasses/Op.hpp"
#include "../compositeclasses/Rand.hpp"
#include "../compositeclasses/Mult.hpp"
#include "../compositeclasses/Div.hpp"
#include <iostream>

int main()
{
    // int size = 0;
    // Op* one = new Op(1.00);
    // Op* two = new Op(2.00);
    // Add* tree1 = new Add(one, two);
    // Op* three = new Op(3.00);
    // Add* tree2 = new Add(tree1, three);
    
    // PreorderIterator* pi = new PreorderIterator(tree2);
    // pi->first();
    // while(!pi->is_done())
    // {
    //     std::cout << "Value: " << pi->current()->stringify() << std::endl;
    //     size++;
    //     pi->next();
    // }
    // std::cout << "Size: " << size << std::endl;

    Op* one = new Op(1);
    Op* thirteen = new Op(13);
    Op* two = new Op(2);
    Op* five = new Op(5);

    Add* sum = new Add(thirteen, five);
    Mult* mult = new Mult(sum, two);
    Sub* sub = new Sub(new Rand(), five);
    Div* div = new Div(sub, mult);

    PreorderIterator* Piter = new PreorderIterator(div);
    CountVisitor* count = new CountVisitor();

    std::cout << "=======================================================\n\n";
    std::cout << "Expression being used:\n\n";

    std::cout << div->stringify() << " = " << div->evaluate() << "\n\n";
    

    Piter->first();
    int i = 1;
    std::cout << "=======================================================\n\n";
    std::cout << "In preorder traversal order (SKIPS FIRST NODE)\n\n";
    while (!Piter->is_done())
    {
        std::cout << "Node # " << i++ << ": " << Piter->current()->stringify() << " = " << Piter->current()->evaluate() << "\n";
        Piter->current()->accept(count);
        Piter->next();
    }

    std::cout << "\n\n";
    std::cout << "=======================================================\n\n";

    std::cout << "Information gathered by CountVisitor using preorder traversal\n\n";

    std::cout << "Number of Operands: " << count->op_count() << "\n";
    std::cout << "Number of Rands: " << count->rand_count() << "\n";
    std::cout << "Number of Adds: " << count->add_count() << "\n";
    std::cout << "Number of Subs: " << count->sub_count() << "\n";
    std::cout << "Number of Pows: " << count->pow_count() << "\n";
    std::cout << "Number of Mults: " << count->mult_count() << "\n";
    std::cout << "Number of Divs: " << count->div_count() << "\n";    

}