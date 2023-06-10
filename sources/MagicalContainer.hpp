#include <vector>
using namespace std;
namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> items;
        vector<int *> p_prime;

    public:
        size_t size();
        MagicalContainer();
        MagicalContainer(const MagicalContainer &other);
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(int element);
        class AscendingIterator
        {
        private:
            MagicalContainer *container;
            size_t *iterator;

        public:
            AscendingIterator(MagicalContainer &container);
            ~AscendingIterator();
            int *begin();
            int *end();
            MagicalContainer *get_container();
            size_t *get_iterator();

        };
        class SideCrossIterator
        {
        private:
            MagicalContainer *container;
            size_t *iterator;

        public:
            SideCrossIterator(MagicalContainer &container);
            ~SideCrossIterator();
            int* begin();
            int* end();
             MagicalContainer *get_container();
            size_t *get_iterator();
        };
        class PrimeIterator
        {
        private:
            MagicalContainer *container;
            size_t *iterator;

        public:
            PrimeIterator(MagicalContainer &container);
            ~PrimeIterator();
            int* begin();
            int* end();
             MagicalContainer *get_container();
            size_t *get_iterator();
        };
    };
} // namespace ariel