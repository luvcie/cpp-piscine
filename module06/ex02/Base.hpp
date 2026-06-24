#ifndef BASE_HPP
#define BASE_HPP

class Base {
  public:
    virtual ~Base();
    // virtual destructor
    // because dynamic_cast
    // only works on polymorphic types
    // and just one virtual method
    // is enough to make a class polymorphic
    // (and also deleting A/B/C objects through
    // a Base* would be UB because wrong destructor called so virtual is needed anyway tbhtbh)
};

#endif
