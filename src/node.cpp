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
    link = nullptr;
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

void Node::setEncodingValue(std::string value)
{

    this->encodingValue = value;
}

std::string Node::getEncodingValue()
{
    return encodingValue;
}

void Node::setRenderPosition(SDL_Point position)
{

    renderPosition = {position.x, position.y};

    if (key.length() > 1)
    {
        nodeText = new Text(" ", position, {(rand() % 255), (rand() % 255), (rand() % 255), 255}, 15);
    }
    else
    {
        nodeText = new Text(this->key, position, {(rand() % 255), (rand() % 255), (rand() % 255), 255}, 15);
    }
}

SDL_Point Node::getRenderPosition()
{
    return renderPosition;
}

void Node::setParentPosition(SDL_Point position)
{
    parentPosition = {position.x, position.y};
}

SDL_Point Node::getParentPosition()
{
}

void Node::render(Window &window)
{
    SDL_SetRenderDrawColor(window.renderer, 255, 255, 255, 255);

    nodeText->render(window);

    if (parentPosition.x != -1)
    {
        SDL_RenderDrawLine(window.renderer, this->renderPosition.x - window.offsetCords.x, this->renderPosition.y - window.offsetCords.y, this->parentPosition.x - window.offsetCords.x, this->parentPosition.y - window.offsetCords.y);
    }

    nodeText->free();
}