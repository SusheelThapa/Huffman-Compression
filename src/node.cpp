#include "node.hpp"

Node::Node()
{
    link = NULL;
    leftChild = nullptr;
    rightChild = nullptr;
    encodingValue = "";
}

Node::Node(std::string key, int priority)
{
    this->key = key;
    this->priority = priority;
    encodingValue = "";
    leftChild = nullptr;
    rightChild = nullptr;
    renderPosition = {0, 0};
}

Node::Node(const Node &nd)
{
    // TODO: To update link of left child and right child
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

std::string Node::setEncodingValue(std::string value)
{
    encodingValue = value;
}

std::string Node::getEncodingValue()
{
    return encodingValue;
}

void Node::setRenderPosition(SDL_Point position)
{
    renderPosition = {position.x, position.y};

    nodeText = new Text(this->key, position, {(rand() % 255), (rand() % 255), (rand() % 255), 255}, 30);
}

SDL_Point Node::getRenderPosition()
{
    return renderPosition;
}

void Node::render(Window &window)
{
    nodeText->render(window);
}