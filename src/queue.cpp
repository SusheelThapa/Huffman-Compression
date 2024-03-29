#include "queue.hpp"

PriorityQueue::PriorityQueue() { front = NULL; }

PriorityQueue::PriorityQueue(const PriorityQueue &other)
{
    front = nullptr;
    if (other.front == NULL)
    {
        return;
    }
    else
    {
        Node *q;
        q = other.front;

        while (q != NULL)
        {
            push(q->getKey(), q->getPriority());
            q = q->link;
        }
    }
}

void PriorityQueue::push(std::string key, int priority, Node *leftChild, Node *rightChild)
{
    Node *tmp, *q;
    tmp = new Node(key, priority);

    tmp->rightChild = rightChild;
    tmp->leftChild = leftChild;

    // Insert at head
    if (front == NULL || priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }

    else
    {
        q = front;
        while (q->link != NULL && q->link->priority < priority)
        {
            q = q->link;
        }

        tmp->link = q->link;
        q->link = tmp;
    }
}

Node *PriorityQueue::pop()
{

    Node *popedNode = nullptr;

    if (front == NULL)
    {
        std::cout << "Queue Underflow\n";
    }
    else
    {
        popedNode = front;

        front = front->link;
    }

    return popedNode;
}

void PriorityQueue::display()
{
    Node *ptr;
    ptr = front;
    if (front == NULL)
    {
        std::cout << "Queue is empty\n";
    }
    else
    {
        std::cout << "Item\tPriority\tEncoded representation\n";
        while (ptr != NULL)
        {
            if (ptr->getKey().length() == 1)
                std::cout << ptr->getKey() << '\t' << ptr->getPriority() << "\t\t" << ptr->getEncodingValue() << std::endl;
            ptr = ptr->link;
        }
    }

    std::cout << std::endl;
}

Node PriorityQueue::top()
{
    if (front == NULL)
    {
        std::cout << "Queue is empty\n";
    }
    else
    {
        return *front;
    }
}

int PriorityQueue::size()
{
    int size = 0;
    Node *ptr;
    ptr = front;
    while (ptr != NULL)
    {
        ptr = ptr->link;
        size++;
    }
    return size;
}

bool PriorityQueue::empty()
{
    if (front == NULL)
    {
        return true;
    }
    return false;
}