#define BOOST_TEST_MODULE test_main

#include "allocator.h"
#include "container.h"
#include <iostream>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_main)

BOOST_AUTO_TEST_CASE(test_container)
{
    MyList<int> mlst;
    mlst.push_back(1);
    mlst.push_back(2);
    mlst.push_back(3);
    auto it = mlst.begin();
    BOOST_REQUIRE(*it == 1);
    BOOST_REQUIRE(*(++it) == 2);
    BOOST_REQUIRE(*(++it) == 3);
}

BOOST_AUTO_TEST_SUITE_END()
