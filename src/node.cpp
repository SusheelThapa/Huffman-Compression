#include "node.hpp"

Node::Node()
{
    link = NULL;
}

Node::Node(std::string key, int priority)
{
    this->key = key;
    this->priority = priority;
}

Node::Node(const Node &nd)
{
    key = nd.key;
    priority = nd.priority;
    link = new Node;

    if (nd.link == NULL)
    {
        link = NULL;
    }
    else
    {
        *link = *nd.link;
    }
}

std::string Node::getKey()
{
    return key;
}

int Node::getPriority()
{
    return priority;
}

