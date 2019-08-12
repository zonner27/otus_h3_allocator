#ifndef ALLOCATOR211807082019_H
#define ALLOCATOR211807082019_H

#include <iostream>
#include <map>
#include "container.h"


template <class T, std::size_t count>
struct my_alloc
{
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    my_alloc() : m_memory(nullptr), m_count(0) {};

    template <typename U>
    struct rebind
    {
        using other = my_alloc<U, count>;
    };

    pointer allocate(std::size_t n)
    {      
        if (m_memory == nullptr)
        {
            auto p = std::malloc(n * sizeof(value_type) * count);    //auto p
            if (!p)
                throw std::bad_alloc();
            //std::cout << "p = " << p << std::endl;
            //std::cout << "Allocated = " << n * count << std::endl;
            m_memory = reinterpret_cast<pointer>(p);
            //std::cout << m_memory << std::endl;
            return m_memory;
        }
        else
        {
            m_count++;
            if (m_count >= count)
                throw std::bad_alloc();
            //std::cout << (m_memory + m_count) << std::endl;
            return (m_memory + m_count);
        }
        return m_memory;
    }

    void deallocate(pointer p, [[maybe_unused]] std::size_t n)
    {
        //std::cout << "p = " << p << " m_count " << m_count << std::endl;
        if (m_memory != nullptr && m_count == 0)
        {
            //std::cout << "Deallocated " << std::endl;
            std::free(p);
            m_memory = nullptr;
        }
        else
            m_count--;
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args)
    {
        //std::cout << "Called construct " << std::endl;
        new(p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p)
    {
        //std::cout << "Called destroy\n";
        p->~T();
    }
private:
    pointer m_memory;
    std::size_t m_count;

};



#endif // ALLOCATOR211807082019_H
