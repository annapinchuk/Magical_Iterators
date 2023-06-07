#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(&container), iterator(new size_t(0)) {}
MagicalContainer::AscendingIterator::~AscendingIterator() { delete iterator; }
int *MagicalContainer::AscendingIterator::begin()
{
    if (this->container->items.size() == 0)
    {
        return nullptr;
    }
    int *begin = &(this->container->items[0]);
    return begin;
}
int *MagicalContainer::AscendingIterator::end()
{
    if (this->container->items.size() == 0)
    {
        return nullptr;
    }
    int *end = &(this->container->items[this->container->items.size() - 1]);
    return end;
}