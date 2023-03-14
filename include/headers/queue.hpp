#pragma once

#include "node.hpp"

class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue();

    PriorityQueue(const PriorityQueue& pq);

    void push(std::string key, int priority);

    void pop();

    void display();

    Node top();

    int size();

    bool empty();
};

