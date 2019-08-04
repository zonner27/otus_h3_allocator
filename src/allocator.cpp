#include <iostream>
#include <typeinfo>
#include <list>
#include <vector>
#include <map>

template <class T>
struct my_alloc
{
    using value_type = T;

    T *allocate(std::size_t n)
    {
        std::cout << "Allocated = " << n << std::endl;
        auto p = std::malloc(n * sizeof(T));
        if (!p)
            throw std::bad_alloc();
        return reinterpret_cast<T*>(p);
    }

    void deallocate(T *p, [[maybe_unused]] std::size_t n)
    {
        std::cout << "Deallocated " << std::endl;
        std::free(p);
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args)
    {
        std::cout << "Called construct \n";
        new(p) U(std::forward<Args>(args)...);
    }

    void destroy(T *p)
    {
        std::cout << "Called destroy\n";
        p->~T();
    }
};

int main()
{
    //std::list<int, my_alloc<int>> a;
    //a.push_back(123);

//    std::vector<int, my_alloc<int>> b;
//    b.reserve(10);
//    b.push_back(1);
//    b.push_back(2);

    std::map<int, char, std::less<int>, my_alloc<std::pair<const int, char>>> b;
    for(int i = 0; i < 10; ++i)
    {
        b.insert(std::make_pair(23, 'g'));
    }


    return 0;
}
