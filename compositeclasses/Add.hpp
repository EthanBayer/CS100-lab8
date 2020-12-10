

#ifndef ADD_HPP
#define ADD_HPP

#include "base.hpp"

class Add : public Base
{
private:
  std::pair<Base*, Base*> children;
public:
  Add(Base* Op1, Base* Op2)
  {
    children.first = Op1;
    children.second = Op2;
  }
  virtual double evaluate()
  {
    return (children.first->evaluate() + children.second->evaluate());
  }

  virtual std::string stringify()
  {
    return ("(" + children.first->stringify() + " + " +  children.second->stringify() + ")");
  }

  virtual Iterator* create_iterator()
  {
    BinaryIterator* bi = new BinaryIterator(this);
    return bi;
  }

  virtual Base* get_left()
  {
    return children.first;
  }

  virtual Base* get_right()
  {
    return children.second;
  }

  virtual void accept(CountVisitor* cv)
  {
    cv->visit_add();
  }

};
#endif //ADD_HPP

