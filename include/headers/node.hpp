#include "window.hpp"

class Node
{
private:
    std::string key;    //Acts as character    
    int priority;       //Acts as frequency
    Node *link;         //Points to next node

public:
    Node();

    Node(std::string key, int priority);

    Node(const Node& nd);

public:
    std::string getKey();

    int getPriority();
    
    friend class PriorityQueue;
};
