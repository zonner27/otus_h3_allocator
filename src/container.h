#ifndef CONTAINER211807082019_H
#define CONTAINER211807082019_H

#include <stdexcept>
#include <iostream>
#include <iterator>
#include <memory>

template<typename T, typename MyAllocator = std::allocator<T>>
class MyList
{
public:

    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    using node_type = Node;
    using allocator_type = typename std::allocator_traits<MyAllocator>::template rebind_alloc<node_type>;

    class My_Iterator
    {
    private:
        node_type *m_node;

    public:
        My_Iterator(node_type *p) : m_node(p) {}
        My_Iterator() : m_node(0) {}

        My_Iterator& operator++()
        {
            m_node = m_node->pNext;
            return *this;
        }

        My_Iterator operator ++(int)
        {
            My_Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        T operator *()
        {
            return m_node->data;
        }

        bool operator==(const My_Iterator& other) const
        {
            return m_node == other.m_node;
        }

        bool operator!=(const My_Iterator& other) const
        {
            return m_node != other.m_node;
        }
    };

    MyList()
    {
        m_size = 0;
        head = nullptr;
    }

    ~MyList()
    {
        while (m_size)
            pop_back();
    }

    My_Iterator begin()
    {
        return My_Iterator(this->head);
    }

    My_Iterator end()
    {
        return My_Iterator(nullptr);
    }

    template<typename ...Args>
    void push_front(Args &&...args)
    {
        auto allocated = m_allocator.allocate(1);
        m_allocator.construct(allocated, std::forward<Args>(args)..., head);
        head = allocated;
        m_size++;
    }

    template<typename ...Args>
    void push_back(Args &&...args)
    {
        auto allocated = m_allocator.allocate(1);
        m_allocator.construct(allocated, std::forward<Args>(args)..., nullptr);

        if(head == nullptr)
        {
            head = allocated;
            m_size++;
        }
        else
        {
            auto current = this->head;
            while(current->pNext != nullptr)
            {
                current = current->pNext;
            }
            current->pNext = allocated;
            m_size++;
        }
    }

    void pop_front()
    {
        node_type *temp = head;
        head = head->pNext;
        m_allocator.destroy(temp);
        m_allocator.deallocate(temp, 1);
        m_size--;
    }

    void pop_back()
    {
        if (m_size == 1)
        {
            m_allocator.destroy(head);
            m_allocator.deallocate(head, 1);
            head = nullptr;
        }
        else
        {
            node_type *current = head;
            for (int i = m_size; i != 2; i--)
                current = current->pNext;
            node_type *todelete = current->pNext;
            current->pNext= nullptr;
            m_allocator.destroy(todelete);
            m_allocator.deallocate(todelete, 1);
        }
        m_size--;
    }

    void clear()
    {
        while (m_size)
            pop_back();
    }

private:
    int m_size;
    Node *head;
    allocator_type m_allocator;

};


#endif //  CONTAINER211807082019_H
