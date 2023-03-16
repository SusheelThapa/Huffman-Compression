#include "huffman.hpp"

Huffman::Huffman()
{
    randomizeButton.loadFromFile(window, "resources/DesignedElements/Randomizebutton.png");
    countButton.loadFromFile(window, "resources/DesignedElements/CountButton.png");
}

Huffman::Huffman(int len)
{
    randomizeButton.loadFromFile(window, "resources/DesignedElements/Randomizebutton.png");
    countButton.loadFromFile(window, "resources/DesignedElements/CountButton.png");
    buildButton.loadFromFile(window, "resources/DesignedElements/BuildButton.png");
    encodeButton.loadFromFile(window, "resources/DesignedElements/EncodeButton.png");

    randomizeBox = Rectangle({77, 203}, 800, 400);
    randomText = generateRandomText(len);
    randomizeText = Text(randomText, {100, 220}, {255, 255, 255, 255});

    fMap = Hashmap(randomText);
    pq = createPriorityQueue(fMap);

    countBox = Rectangle({1000, 203}, 300, 700);
    generateCountText(pq);
    symbolText = Text(this->symText, {1010, 220}, {255, 255, 255, 255}, 13, true);
    frequencyText = Text(this->freqText, {1200, 220}, {255, 255, 255, 255});

    huffmanTreeRootNode = createHuffmanTree();

   std::cout << "Encoding" << std::endl;
    encode(huffmanTreeRootNode, "");
}

void Huffman::handleEvent()
{
    while (SDL_PollEvent(&this->e) != 0)
    {
        // *Yo section ma Scroll event handle huncah hai ra

        if (e.type == SDL_QUIT ||
            e.type == SDL_MOUSEMOTION ||
            e.type == SDL_MOUSEBUTTONDOWN ||
            e.type == SDL_MOUSEBUTTONUP)
        {
            window.handleEvent(e);
        }

        // * Aba malai yo section ma button click handle garna xa

        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_GetMouseState(&clickedPosition.x, &clickedPosition.y);
        }

        if (e.type == SDL_MOUSEBUTTONUP)
        {
            SDL_Point currentClickedPosition;

            SDL_GetMouseState(&currentClickedPosition.x, &currentClickedPosition.y);

            if (currentClickedPosition.x == clickedPosition.x && currentClickedPosition.y == clickedPosition.y)
            {

                std::cout << "Button is clicked";

                /**
                 * TODO: Logic to identify which button is clicked
                 */
            }
        }
    }
}

std::string Huffman::generateRandomText(int len)
{
    std::string alphanum = "016789ABRSXYZaeflmn!@#$>`~.";
    std::string s;
    s.reserve(len);

    while (len--)
        s += alphanum[rand() % (alphanum.size() - 1)];
    return s;
}

std::unordered_map<std::string, int> Huffman::Hashmap(std::string randomText)
{
    std::unordered_map<std::string, int> fMap;
    std::unordered_map<std::string, int>::iterator it;
    for (int i = 0; i < randomText.length(); ++i)
    {
        fMap[std::string(1, randomText[i])]++;
    }
    return fMap;
}

PriorityQueue Huffman::createPriorityQueue(std::unordered_map<std::string, int> fMap)
{
    PriorityQueue pq;

    std::unordered_map<std::string, int>::iterator it;

    for (it = fMap.begin(); it != fMap.end(); it++)
    {
        pq.push(it->first, it->second);
    }

    return pq;
}

void Huffman::generateCountText(PriorityQueue pq)
{
    PriorityQueue copy = pq;
    this->symText = "";
    this->freqText = "";
    int cnt = 0;

    while (!copy.empty())
    {
        // Get the first element of queue
        Node* p = copy.pop();

        // Append the key and frequency to respective text
        symText += "' ";
        symText += p->getKey();
        symText += "' \n";
        freqText += std::to_string(p->getPriority());
        freqText += '\n';
        cnt++;
    }
}

Node *Huffman::createHuffmanTree()
{
    // Creating copy of the priority queue we have created
    PriorityQueue cpq = pq;

    // Generation of Huffman Tree
    Node *nodeOne;
    Node *nodeTwo;

    while (1)
    {
        nodeOne = cpq.pop();
        nodeTwo = cpq.pop();

        if (nodeTwo == nullptr)
        {
            cpq.push(nodeOne->getKey(), nodeOne->getPriority(), nodeOne->getLeftChild(), nodeOne->getRightChild());
            break;
        }

        cpq.push(" ", nodeOne->getPriority() + nodeTwo->getPriority(), nodeOne, nodeTwo);
    }

    return cpq.pop();
}

void Huffman::displayHuffmanTree()
{

    std::cout << "Preorder Traversal" << std::endl;
    Stack<Node *> S;

    Node *root = huffmanTreeRootNode;

    while (true)
    {
        cout << root->getKey() << " " << root->getPriority() << std::endl;
        if (root->getRightChild())
        {
            S.push(root->getRightChild());
        };
        if (root->getLeftChild())
        {
            S.push(root->getLeftChild());
        }

        root = S.pop();

        if (root == nullptr)
        {
            break;
        }
    }
}

void Huffman::encode(Node *node, std::string encodedText)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->getKey() != " ")
    {
        pq.setHuffmanCode(node->getKey(), encodedText);
        std::cout << node->getKey() << "   " << encodedText << std::endl;
    }

    if (node->getLeftChild())
    {
        encode(node->getLeftChild(), encodedText + "0");
    }

    if (node->getRightChild())
    {
        encode(node->getRightChild(), encodedText + "1");
    }
}
