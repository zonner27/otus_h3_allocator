#ifndef CONTAINER211807082019_H
#define CONTAINER211807082019_H

#include <iostream>

template<typename T>
class My_List
{
public:
    My_List();

    ~My_List();

    void push_front(T data);
    void pop_front();

    void push_back(T data);
    void pop_back();

    void clear();

    // получить количество элементов в списке
    int GetSize() { return Size; }

    // перегруженный оператор []
    T& operator[](const int index);

    //добавление элемента в список по указанному индексу
    void insert(T data, int index);

    //удаление элемента в списке по указанному индексу
    void removeAt(int index);

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
