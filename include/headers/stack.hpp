#include <iostream>
#include <climits>

#include "linkedList.hpp"

using namespace std;

template <class T>
class Stack
{
    LinkedList<T> stack;

public:
    void push(T data)
    {
        stack.insertAtBeginning(data);
    }

    T pop()
    {
        if (stack.isEmpty())
        {
            return nullptr;
        }
        return stack.deleteFromBeginning();
    }

    bool isEmpty()
    {
        return stack.isEmpty();
    }

    void display()
    {
        if (stack.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        stack.display();
    }
};
