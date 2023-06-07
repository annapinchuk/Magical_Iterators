#include "MagicalContainer.hpp"
using namespace ariel;
// constructor for prime iterator 
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(&container), iterator(new size_t(0)) {}
// destructor for prime iterator
MagicalContainer::PrimeIterator::~PrimeIterator() { delete iterator; }
// begin function for prime iterator
int *MagicalContainer::PrimeIterator::begin()
{
    if (this->container->items.size() == 0)
    {
        return nullptr;
    }
    int *begin = &(this->container->items[0]);
    return begin;
}
// end function for prime iterator
int *MagicalContainer::PrimeIterator::end()
{
    if (this->container->items.size() == 0)
    {
        return nullptr;
    }
    int *end = &(this->container->items[this->container->items.size() - 1]);
    return end;
}