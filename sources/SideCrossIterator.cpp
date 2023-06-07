#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), iterator(new size_t(0)) {}
MagicalContainer::SideCrossIterator::~SideCrossIterator() { delete iterator; }
int *MagicalContainer::SideCrossIterator::begin()
{
    if (this->container->items.size() == 0)
    {
        return nullptr;
    }
    int *begin = &(this->container->items[0]);
    return begin;
}
int *MagicalContainer::SideCrossIterator::end()
{
   if (this->container->items.size() == 0)
    {
        return nullptr;
    }
    int *end = &(this->container->items[this->container->items.size() - 1]);
    return end;
}