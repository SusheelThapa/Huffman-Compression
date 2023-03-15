#include "window.hpp"

class Node
{
private:
    std::string key;           // Acts as character
    int priority;              // Acts as frequency
    std::string encodingValue; // Value used while encoding
    Node *link;                // Points to next node

    Node *leftChild;  // Points to Left Child
    Node *rightChild; // Points to right child

public:
    Node();

    Node(std::string key, int priority);

    Node(const Node &nd);

public:
    std::string getKey();

    int getPriority();

    std::string setEncodingValue(std::string value);
    std::string getEncodingValue();

    Node *getLeftChild() { return leftChild; }
    Node *getRightChild() { return rightChild; }

    friend class PriorityQueue;
};
