#ifndef ALLOCATOR211807082019_H
#define ALLOCATOR211807082019_H

#include <iostream>
#include <bitset>

template <class T, std::size_t count>
struct My_Alloc
{
    using value_type = T;
    using pointer = T*;

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

        pointer res = nullptr;

        for (std::size_t i = 0; i < count; ++i)
        {
            if (m_b[i] == 0)
            {
                res = m_memory + i;
                m_count += n;
                m_b.set(i);
                break;
            }
        }
        return res;
    }

    void deallocate(pointer p, [[maybe_unused]] std::size_t n)
    {
        if (!p)
            return;

        m_count -= n;
        for (std::size_t i = 0; i < count; ++i)
        {
            if ((m_memory + i) == p)
                m_b.reset(i);
        }
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
    std::bitset<count> m_b;
};

#endif // ALLOCATOR211807082019_H
