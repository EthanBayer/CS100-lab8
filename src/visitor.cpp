

#include "../headers/visitor.hpp"

CountVisitor::CountVisitor()
{
    ops = 0;
    rands = 0;
    mults = 0;
    divs = 0;
    add = 0;
    sub = 0;
    pow = 0;
}

void CountVisitor::visit_op()
{
    ops++;
}

int CountVisitor::op_count()
{
    return ops;
}

void CountVisitor::visit_add()
{
    add++;
}

int CountVisitor::add_count()
{
    return add;
}

void CountVisitor::visit_sub()
{
    sub++;
}

int CountVisitor::sub_count()
{
    return sub;
}

void CountVisitor::visit_pow()
{
    pow++;
}

int CountVisitor::pow_count()
{
    return pow;
}

void CountVisitor::visit_rand()
{
    rands++;
}

int CountVisitor::rand_count()
{
    return rands;
}
void CountVisitor::visit_mult()
{
    mults++;
}

int CountVisitor::mult_count()
{
    return mults;
}

void CountVisitor::visit_div()
{
    divs++;
}

int CountVisitor::div_count()
{
    return divs;
}