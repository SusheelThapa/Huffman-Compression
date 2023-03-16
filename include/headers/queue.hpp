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

    void setHuffmanCodeAndRenderPosition(std::string key, std::string encodingString, SDL_Point position)
    {
        Node *ptr = front;

        while (ptr->getKey() != key)
        {
            ptr = ptr->link;
        }
        ptr->setEncodingValue(encodingString);
        ptr->setRenderPosition(position);
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
    SDL_Point getRenderPosition(std::string key)
    {
        if (key == " ")
        {
            return {0, 0};
        }

        Node *ptr = front;

        while (ptr->getKey() != key)
        {
            ptr = ptr->link;
        }
        return ptr->getRenderPosition();
    }

    void renderNode(Window &window, std::string key)
    {
        if (key == " ")
        {
            return;
        }

        Node *ptr = front;

        while (ptr->getKey() != key)
        {
            ptr = ptr->link;
        }
        ptr->render(window);
    }
};
