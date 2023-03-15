#pragma once

#include "node.hpp"

class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue();

    PriorityQueue(const PriorityQueue &pq);

    void push(std::string key, int priority, Node *leftChild = nullptr, Node *rightChild = nullptr);

    Node *pop();

    void display();

    Node top();

    int size();

    bool empty();

    void setHuffmanCode(std::string key, std::string encodingString)
    {
        Node *ptr = front;

        while (ptr->getKey() != key)
        {
            ptr = ptr->link;
        }
        ptr->setEncodingValue(encodingString);
    }

    std::string getHuffmanCode(std::string key)
    {

        Node *ptr = front;

        while (ptr->getKey() != key)
        {
            ptr = ptr->link;
        }
        return ptr->getEncodingValue();
    }
};
