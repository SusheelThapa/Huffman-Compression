#include "window.hpp"
#include "texture.hpp"
#include "queue.hpp"
#include "rectangle.hpp"
#include "stack.hpp"


#include <unordered_map>

class Huffman
{

private:
    SDL_Point clickedPosition;
    SDL_Event e;

    std::string randomText;
    std::string symText, freqText;
    std::unordered_map<std::string, int> fMap;

public:
    Window window;
    Texture randomizeButton, countButton, buildButton, encodeButton;
    Rectangle randomizeBox, countBox;
    
    Text randomizeText, symbolText, frequencyText;
    PriorityQueue pq;
    Node *huffmanTreeRootNode;

public:
    Huffman();

    Huffman(int count);

    void handleEvent();

    Node *createHuffmanTree();

    void displayHuffmanTree();

    void encode(Node *node, std::string encodedText);

private:
    // Generates a random string of 'count' characters
    std::string generateRandomText(int count);

    // Creates and renders the hashmap of keys along with their frequencies
    std::unordered_map<std::string, int> Hashmap(std::string randomText);

    // Creates priority queue from the hashmap
    PriorityQueue createPriorityQueue(std::unordered_map<std::string, int> fMap);

    //Gets key and frequency of the nodes into separate strings for rendering
    void generateCountText(PriorityQueue pq);

    // Creates Huffman Tree from the priority queue
};