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
//    std::map<int, int> map_standart;
//    for(int i = 0; i < 10; ++i)
//    {
//        map_standart.insert(std::make_pair(i, factorial(i)));
//    }

//    for(auto it = map_standart.begin(); it != map_standart.end(); ++it)
//    {
//        std::cout << it->first << " " << it->second << std::endl;
//    }

//    std::map<int, int, std::less<int>, my_alloc<std::pair<const int, int>, 10>> map_myallocator;
//    for(int i = 0; i < 10; ++i)
//    {
//        map_myallocator.insert(std::make_pair(i, factorial(i)));
//    }

//    for(auto it = map_myallocator.begin(); it != map_myallocator.end(); ++it)
//    {
//        std::cout << it->first << " " << it->second << std::endl;
//    }

    std::cout << "-----------------" << std::endl;
    My_List<int> mlst;
    for (int i = 0; i < 10; i++)
    {
        mlst.push_back(i);
    };
    std::cout << "-----------------" << std::endl;
    My_List<int, my_alloc<Node<int>, 10>> mlsta;
    for (int i = 0; i < 10; i++)
    {
        mlsta.push_back(i);
    };

    for (auto i = mlst.begin(); i != mlst.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    for (auto i = mlsta.begin(); i != mlsta.end(); i++)
    {
        std::cout << *i << std::endl;
    }

//    for (const auto& it : mlst)
//       std::cout << it << std::endl;

//    try
//    {
//        for (int i = 0; i < mlst.GetSize(); i++)
//        {
//            std::cout << mlst[i] << std::endl;
//        }
//        std::cout << mlst[10] << std::endl;
//    }
//    catch (const std::out_of_range& ex)
//    {
//         std::cerr << "Out of Range error: " << ex.what() << '\n';
//    }


    return 0;
}
