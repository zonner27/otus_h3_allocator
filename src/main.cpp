#include <iostream>
#include <map>
#include "allocator.h"
#include "container.h"


int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    std::map<int, int> map_standart;
    for(int i = 0; i < 10; ++i)
    {
        map_standart.insert(std::make_pair(i, factorial(i)));
    }

    for(auto it = map_standart.begin(); it != map_standart.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::map<int, int, std::less<int>, my_alloc<std::pair<const int, int>, 10>> map_myallocator;
    for(int i = 0; i < 10; ++i)
    {
        map_myallocator.insert(std::make_pair(i, factorial(i)));
    }

    for(auto it = map_myallocator.begin(); it != map_myallocator.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    std::cout << "-----------------" << std::endl;
    My_List<int> mlst;
   // mlst.push_back(1);
//    mlst.push_back(2);
//    mlst.push_back(3);

//    for (int i = 0; i < mlst.GetSize(); i++)
//    {
//        std::cout << mlst[i] << std::endl;
//    }

    return 0;
}
