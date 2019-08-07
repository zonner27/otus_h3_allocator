#include "container.h"

template<typename T>
My_List<T>::My_List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
My_List<T>::~My_List()
{
    clear();
}


template<typename T>
void My_List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void My_List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void My_List<T>::push_back(T data)
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

template<typename T>
void My_List<T>::pop_back()
{
    removeAt(Size - 1);
}

template<typename T>
void My_List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
T& My_List<T>::operator[](const int index)
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
}

template<typename T>
void My_List<T>::insert(T data, int index)
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

template<typename T>
void My_List<T>::removeAt(int index)
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


