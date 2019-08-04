
#define BOOST_TEST_MODULE test_main

#include "lib.h"
#include <vector>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_main)

BOOST_AUTO_TEST_CASE(test_sort)
{

    std::vector<ip_adress> ip_test = {std::make_tuple(1,1,1,1),
                                      std::make_tuple(5,5,5,5),
                                      std::make_tuple(2,2,2,2)};

    std::vector<ip_adress> result = {std::make_tuple(5,5,5,5),
                                     std::make_tuple(2,2,2,2),
                                     std::make_tuple(1,1,1,1)};

    std::sort(ip_test.begin(), ip_test.end(),  std::greater<ip_adress>());
    BOOST_REQUIRE(ip_test == result);

}

BOOST_AUTO_TEST_CASE(test_filter_1)
{
    std::vector<ip_adress> ip_test = {std::make_tuple(1,1,1,1),
                                      std::make_tuple(5,5,5,5),
                                      std::make_tuple(2,2,2,2)};

    std::vector<ip_adress> result = {std::make_tuple(1,1,1,1)};

    auto ip_temp = ipfilter(ip_test, 1);
    BOOST_REQUIRE(ip_temp == result);

}

BOOST_AUTO_TEST_CASE(test_filter_46_70)
{
    std::vector<ip_adress> ip_test = {std::make_tuple(46,5,1,1),
                                      std::make_tuple(46,70,5,5),
                                      std::make_tuple(6,2,70,2)};

    std::vector<ip_adress> result = {std::make_tuple(46,70,5,5)};

    auto ip_temp = ipfilter(ip_test, 46, 70);
    BOOST_REQUIRE(ip_temp == result);
}

BOOST_AUTO_TEST_CASE(test_filter_46_any)
{
    std::vector<ip_adress> ip_test = {std::make_tuple(5,46,1,1),
                                      std::make_tuple(46,70,5,5),
                                      std::make_tuple(6,2,70,2)};

    std::vector<ip_adress> result = {std::make_tuple(5,46,1,1),
                                     std::make_tuple(46,70,5,5)};

    auto ip_temp = ipfilter_any(ip_test, 46);
    BOOST_REQUIRE(ip_temp == result);
}

BOOST_AUTO_TEST_SUITE_END()
