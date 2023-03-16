#include "window.hpp"
#include "text.hpp"

class Node
{
private:
    std::string key;           // Acts as character
    int priority;              // Acts as frequency
    std::string encodingValue; // Value used while encoding
    Node *link;                // Points to next node

    Node *leftChild;  // Points to Left Child
    Node *rightChild; // Points to right child

    SDL_Point renderPosition;

    SDL_Point parentPosition;

    Text *nodeText;

public:
    Node();

    Node(std::string key, int priority);

    Node(const Node &nd);

public:
    std::string getKey();

    int getPriority();

    void setEncodingValue(std::string value);
    std::string getEncodingValue();

    Node *getLeftChild() { return leftChild; }
    Node *getRightChild() { return rightChild; }

    void setRenderPosition(SDL_Point position);
    SDL_Point getRenderPosition();

    void setParentPosition(SDL_Point position);
    SDL_Point getParentPosition();

    void render(Window &);

    friend class PriorityQueue;
};
