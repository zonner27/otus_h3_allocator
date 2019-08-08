#ifndef CONTAINER211807082019_H
#define CONTAINER211807082019_H

#include <iostream>

template<typename T>
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
        if (head == nullptr)
        {
            head = new Node<T>(data);
        }
        else
        {
            Node<T> *current = this->head;
            while (current->pNext != nullptr)
            {
                current = current->pNext;
            }
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
        current = nullptr;
        return current->data;
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
    template<typename T1>
    class Node
    {
    public:
        Node * pNext;
        T1 data;

        Node(T1 data = T1(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *head;
};


#include "container.cpp"
#endif //  CONTAINER211807082019_H
