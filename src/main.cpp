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
    try {
        // map standart
        std::map<int, int> map_standart;
        for(int i = 0; i < 10; ++i)
            map_standart.insert(std::make_pair(i, factorial(i)));

        for(auto it = map_standart.begin(); it != map_standart.end(); ++it)
            std::cout << it->first << " " << it->second << std::endl;

        //map with my allocator
        std::map<int, int, std::less<int>, My_Alloc<std::pair<const int, int>, 10>> map_myallocator;
        for(int i = 0; i < 10; ++i)
            map_myallocator.insert(std::make_pair(i, factorial(i)));

        for(auto it = map_myallocator.begin(); it != map_myallocator.end(); ++it)
            std::cout << it->first << " " << it->second << std::endl;

        //my list
        MyList<int> mlst;
        for (int i = 0; i < 10; i++)
            mlst.push_back(i);

        for (auto i = mlst.begin(); i != mlst.end(); i++)
            std::cout << *i << std::endl;

        //my list with my allocator
        MyList<int, My_Alloc<int, 10>> mlsta;
        for (int i = 0; i < 10; i++)
            mlsta.push_back(i);

        for (auto i = mlsta.begin(); i != mlsta.end(); i++)
            std::cout << *i << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
