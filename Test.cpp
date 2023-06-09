#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;
TEST_SUITE("MagicalContainer Tests") {
    TEST_CASE("Add and Remove Elements") {
        MagicalContainer container;
        container.addElement(0);
        container.addElement(56);
        container.addElement(3);
        container.addElement(14);
        container.addElement(-2);

        CHECK(container.size() == 5);

        SUBCASE("Ascending Order") {
             MagicalContainer exp_Container;
            exp_Container.addElement(-2);
            exp_Container.addElement(0);
            exp_Container.addElement(3);
            exp_Container.addElement(14);
            exp_Container.addElement(56);

            CHECK(container == exp_Container);

        }

        SUBCASE("Cross Order") {
            MagicalContainer exp_Container;
            exp_Container.addElement(72);
            exp_Container.addElement(5);
            exp_Container.addElement(-9);
            exp_Container.addElement(13);
            exp_Container.addElement(8);
            exp_Container.addElement(19);

            MagicalContainer::SideCrossIterator crossIter(container);
            vector<int> act;
            for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
                act.push_back(*it);
            }

            CHECK(container == exp_Container);
        }

        SUBCASE("Prime Numbers") {
            vector<int> exp = {5, 13,19};
            MagicalContainer exp_Container;
            exp_Container.addElement(5);
            exp_Container.addElement(13);
            exp_Container.addElement(19);

            MagicalContainer::PrimeIterator primeIter(container);
            vector<int> act;
            for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
                act.push_back(*it);
            }

            CHECK(container == exp_Container);
        }

        container.removeElement(72);
        container.removeElement(-9);
        container.removeElement(8);

        CHECK(container.size() == 5);

        SUBCASE("Ascending Order After remove") {
            MagicalContainer exp_Container;
            exp_Container.addElement(-9);
            exp_Container.addElement(8);
            exp_Container.addElement(72);

            CHECK(container == exp_Container);
        }
    }

    TEST_CASE("Empty Container") {
        MagicalContainer container;

        CHECK(container.size() == 0);

        SUBCASE("Ascending Order with Empty container") {
          
            MagicalContainer exp_Container;
            CHECK(container == exp_Container);
        }

        SUBCASE("Cross Order with Empty container") {
            MagicalContainer exp_Container;

            MagicalContainer::SideCrossIterator crossIter(container);
            vector<int> act;
            for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
                act.push_back(*it);
            }

            CHECK(container == exp_Container);

        }

        SUBCASE("Prime Numbers with Empty container") {
            MagicalContainer exp_Container;

            MagicalContainer::PrimeIterator primeIter(container);
            vector<int> act;
            for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
                act.push_back(*it);
            }
            CHECK(container == exp_Container);

        }
    }

    TEST_CASE("Conatainer have only One element") {
        MagicalContainer container,exp_Container;
        container.addElement(100);

        CHECK(container.size() == 1);

        SUBCASE("Ascending Order with container have one element") {
            vector<int> exp = {100};
            exp_Container.addElement(exp.at(0));

            CHECK(container == exp_Container);
        }

        SUBCASE("Cross Order with container have one element") {
            vector<int> exp = {100};
        MagicalContainer exp_Container;

            MagicalContainer::SideCrossIterator crossIter(container);
            vector<int> act;
            for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
                act.push_back(*it);
            }

            CHECK(container == exp_Container);
        }

        SUBCASE("Prime Numbers with container have one element") {
            vector<int> exp = {100};
        MagicalContainer exp_Container;

            MagicalContainer::PrimeIterator primeIter(container);
            vector<int> act;
            for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
                act.push_back(*it);
            }

            CHECK(container == exp_Container);
        }
        container.removeElement(100);

        CHECK(container.size() == 0);

        CHECK_THROWS(container.removeElement(100));
              
    }
}
