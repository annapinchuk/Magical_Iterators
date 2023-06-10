// Author: Anna Pinchuk
// Date: 11/06/2023
// Description : Implementation of container class that contains 3 iterators: AscendingIterator, SideCrossIterator, PrimeIterator.
// credit to: course staff for the header file, and the functions' descriptions.
#include "doctest.h"
#include <iostream>
#include "sources/MagicalContainer.hpp"
using namespace ariel;
TEST_CASE("functional tests and errors")
{
}
#include "doctest.h"

TEST_CASE("Testing iterators")
{
    MagicalContainer container;
    // inatialize the iterators
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::SideCrossIterator crossIter(container);

    SUBCASE("Empty container")
    {

        DOCTEST_SUBCASE("Begin iterator")
        {
            DOCTEST_WARN_THROWS_AS(ascIter.begin(), std::runtime_error);
            DOCTEST_WARN_THROWS_WITH(ascIter.begin(), "Cannot dereference an iterator from an empty container.");

            DOCTEST_WARN_THROWS_AS(primeIter.begin(), std::runtime_error);
            DOCTEST_WARN_THROWS_WITH(primeIter.begin(), "Cannot dereference an iterator from an empty container.");

            DOCTEST_WARN_THROWS_AS(crossIter.begin(), std::runtime_error);
            DOCTEST_WARN_THROWS_WITH(crossIter.begin(), "Cannot dereference an iterator from an empty container.");
        }

        DOCTEST_SUBCASE("End iterator")
        {
            DOCTEST_WARN_THROWS_AS(ascIter.end(), std::runtime_error);
            DOCTEST_WARN_THROWS_WITH(ascIter.end(),"Cannot dereference an iterator from an empty container.");

            DOCTEST_WARN_THROWS_AS(primeIter.end(), std::runtime_error);
            DOCTEST_WARN_THROWS_WITH(primeIter.end(), "Cannot dereference an iterator from an empty container.");

            DOCTEST_WARN_THROWS_AS(crossIter.end(), std::runtime_error);
            DOCTEST_WARN_THROWS_WITH(crossIter.end(), "Cannot dereference an iterator from an empty container.");
        }
    }
    SUBCASE("compering iterator values")
    {
        // add elements to the container
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        // begin iterator
        auto asciterator = ascIter.begin();
        auto primeiterator = primeIter.begin();
        auto crossiterator = crossIter.begin();

        // end iterator
        auto ascend = ascIter.end();
        auto primeend = primeIter.end();
        auto crossend = crossIter.end();

        DOCTEST_SUBCASE("Begin iterator")
        {
            CHECK(*asciterator == 1);
            CHECK(*primeiterator == 2);
            CHECK(*crossiterator == 1);
        }

        DOCTEST_SUBCASE("End iterator")
        {
            CHECK(*ascend == 4);
            CHECK(*primeend == 3);
            CHECK(*crossend == 4);
        }
    }
}

TEST_CASE("container with all iterators")
{
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(17));
    CHECK_NOTHROW(container.addElement(2));
    CHECK_NOTHROW(container.addElement(25));
    CHECK_NOTHROW(container.addElement(9));
    CHECK_NOTHROW(container.addElement(3));

    CHECK(container.size() == 5);
    CHECK_NOTHROW(container.removeElement(9));
    CHECK(container.size() == 4);

    // inatialize the iterators
    MagicalContainer::AscendingIterator ascIter(container);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::SideCrossIterator crossIter(container);
    // check the values of each iterator
    auto ascbeg = *ascIter.begin();
    CHECK(ascbeg == 2);
    auto ascend = *ascIter.end();
    CHECK(ascend == 25);
    auto crossbeg = *crossIter.begin();
    CHECK(crossbeg == 2);
    auto crossend = *crossIter.end();
    CHECK(crossend == 25);
    auto primebeg = *primeIter.begin();
    CHECK(primebeg == 2);
    auto primeend = *primeIter.end();
    CHECK(primeend == 17);
    // check the size of each iterator
    CHECK(ascIter.end() - ascIter.begin() == 5);
    CHECK(crossIter.end() - crossIter.begin() == 5);
    CHECK(primeIter.end() - primeIter.begin() == 3);
}
