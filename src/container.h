#ifndef CONTAINER211807082019_H
#define CONTAINER211807082019_H

#include <stdexcept>
#include <iostream>
#include <memory>

template<typename T1>
class Node
{
public:
    Node *pNext;
    T1 data;

//    Node(const Node<T1> &node) :
//        data(node.data), next(node.pNext) {}

    template<typename ...Args>
    Node(Args &&...args) : data(std::forward<Args>(args)...)
    {
        pNext = nullptr;
    }

    Node(T1 data = T1(), Node *pNext = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
    }
};

template<typename T>
class My_Iterator
{
private:
    Node<T> *m_node;

public:
    My_Iterator(Node<T> *p) : m_node(p) {}
    My_Iterator() : m_node(0) {}

    My_Iterator<T>& operator++()
    {
        m_node = m_node->pNext;
        return *this;
    }

    My_Iterator<T> operator ++(int)
    {
        My_Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    T operator *()
    {
        return m_node->data;
    }

    bool operator==(const My_Iterator<T>& other) const
    {
        return m_node == other.m_node;
    }

    bool operator!=(const My_Iterator<T>& other) const
    {
        return m_node != other.m_node;
    }
};

template<typename T, typename My_Allocator = std::allocator<Node<T>>>
class My_List
{
public:

    My_List()
    {
        Size = 0;
        head = nullptr;
    }

    ~My_List()
    {
        clear();
    }

    My_Iterator<T> begin()
    {
        return My_Iterator<T>(this->head);
    }

    My_Iterator<T> end()
    {
        return nullptr;
    }

    void push_front(T data)
    {
        head = new Node<T>(data, head);
        Size++;
    }

    void pop_front()
    {
        Node<T> *temp = head;
        head = head->pNext;
        delete temp;
        Size--;
    }

    void push_back(T data)
    {
        if (head == nullptr && Size == 0)
        {
            head = allocator.allocate(1);
            allocator.construct(head, data, &allocator);
            //head = new Node<T>(data);
        }
        else
        {
            Node<T> *current = this->head;
            while (current->pNext != nullptr)
            {
                current = current->pNext;       
            }
            std::cout << current << " " << current->data << std::endl;
            current->pNext = new Node<T>(data);
        }
        Size++;
    }

    void pop_back()
    {
        removeAt(Size - 1);
    }

    void clear()
    {
        while (Size)
        {
            pop_front();
        }
    }

    // получить количество элементов в списке
    int GetSize() { return Size; }

    // перегруженный оператор []
    T& operator[](const int index)
    {
        int counter = 0;
        Node<T> *current = this->head;

        while (current != nullptr)
        {

            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
        throw std::out_of_range("out of range!");
    }

    //добавление элемента в список по указанному индексу
    void insert(T data, int index)
    {
        if (index == 0)
        {
            push_front(data);
        }
        else
        {
            Node<T> *previous = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }

            Node<T> *newNode = new Node<T>(data, previous->pNext);
            previous->pNext = newNode;
            Size++;
        }
    }

    //удаление элемента в списке по указанному индексу
    void removeAt(int index)
    {
        if (index == 0)
        {
            pop_front();
        }
        else
        {
            Node<T> *previous = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }

            Node<T> *toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            delete toDelete;
            Size--;
        }
    }


private:
    int Size;
    Node<T> *head;
    My_Allocator allocator;
};


#include "container.cpp"
#endif //  CONTAINER211807082019_H
