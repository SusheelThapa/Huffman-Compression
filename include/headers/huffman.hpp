#include "window.hpp"
#include "texture.hpp"
#include "button.old.hpp"
#include "queue.hpp"
#include "stack.hpp"

#include <unordered_map>

class Huffman
{

private:
    SDL_Point clickedPosition;
    SDL_Event e;

    std::string randomText;
    std::unordered_map<std::string, int> fMap;

public:
    Window window;
    Texture randomize, count;
    PriorityQueue pq;

public:
    Huffman();

    Huffman(int count);

    void handleEvent();

    void createHuffmanTree();

    void displayHuffmanTree();

private:
    // Generates a random string of 'count' characters
    std::string generateRandomText(int count);

    // Creates and renders the hashmap of keys along with their frequencies
    std::unordered_map<std::string, int> Hashmap(std::string randomText);

    // Creates priority queue from the hashmap
    PriorityQueue createPriorityQueue(std::unordered_map<std::string, int> fMap);

    // Creates Huffman Tree from the priority queue
};