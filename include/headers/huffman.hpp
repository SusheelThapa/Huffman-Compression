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
    std::string encText = "";

public:
    Window window;
    Texture randomizeButton, countButton, buildButton, encodeButton;
    Rectangle randomizeBox, countBox;
    Text randomizeText, symbolText, frequencyText, encodedText;
    PriorityQueue pq;
    Node *huffmanTreeRootNode;

    // Const Required for Tree Display
    int treeWidth;

public:
    int depthOfHuffmanTree = 0;

    Huffman();

    Huffman(int count);

    void handleEvent();

    void render();

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
    void renderHuffmanTree();

    Node *createHuffmanTree();

    void displayHuffmanTree();
    int findDepthOfHuffmanTree(Node *);

    void generateHuffmanCode(Node *node, std::string encText, SDL_Point, int);

    void encodeString();
};