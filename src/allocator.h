#ifndef ALLOCATOR211807082019_H
#define ALLOCATOR211807082019_H

#include <iostream>

template <class T, std::size_t count>
struct My_Alloc
{
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    My_Alloc() : m_memory(nullptr), m_count(0) {};

    template <typename U>
    struct rebind
    {
        using other = My_Alloc<U, count>;
    };

    pointer allocate(std::size_t n)
    {

        if ((m_count + n) > count)
            throw std::bad_alloc();

        if (!m_memory)
        {
            auto p = std::malloc(sizeof(value_type) * count);
            m_memory = reinterpret_cast<pointer>(p);
        }

        if (!m_memory)
            throw std::bad_alloc();

        pointer res = m_memory + m_count;
        m_count += n;

        return res;

    }

    void deallocate(pointer p, [[maybe_unused]] std::size_t n)
    {
        if (!p)
            return;

        m_count -= n;
        if (m_count != 0)
            return;

        std::free(m_memory);
        m_memory = nullptr;
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args)
    {
        new(p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p)
    {
        p->~T();
    }

private:
    pointer m_memory;
    std::size_t m_count;
};



#endif // ALLOCATOR211807082019_H
