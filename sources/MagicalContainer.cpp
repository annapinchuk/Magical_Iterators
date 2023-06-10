#include "MagicalContainer.hpp"
using namespace ariel;
MagicalContainer::MagicalContainer() : items(), p_prime() {}
MagicalContainer::~MagicalContainer() {}
size_t MagicalContainer::size() { return items.size(); }
void MagicalContainer::addElement(int element)
{
    items.push_back(element);
    if (element > 1)
    {
        for (size_t i = 2; i < element; i++)
        {
            if (static_cast<unsigned int>(element) % i == 0)
            {
                return;
            }
        }
        p_prime.push_back(&items[items.size() - 1]);
    }
}
void MagicalContainer::removeElement(int element)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[static_cast<std::vector<int>::size_type>(i)] == element)
        {

            items.erase(items.begin() + i);
            break;
        }
    }
    for (int i = 0; i < p_prime.size(); i++)
    {
        if (*p_prime[static_cast<std::vector<int>::size_type>(i)] == element)
        {
            p_prime.erase(p_prime.begin() + i);
            break;
        }
    }
}
