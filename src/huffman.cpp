#include "huffman.hpp"

Huffman::Huffman()
{
    randomizeButton.loadFromFile(window, "resources/DesignedElements/Randomizebutton.png");
    countButton.loadFromFile(window, "resources/DesignedElements/CountButton.png");
}

Huffman::Huffman(int len)
{
    this->originalSize = len * 8;
    randomizeButton.loadFromFile(window, "resources/DesignedElements/Randomizebutton.png");
    countButton.loadFromFile(window, "resources/DesignedElements/CountButton.png");
    buildButton.loadFromFile(window, "resources/DesignedElements/BuildButton.png");
    encodeButton.loadFromFile(window, "resources/DesignedElements/EncodeButton.png");
    compressButton.loadFromFile(window, "resources/DesignedElements/CompressButton.png");

    randomText = generateRandomText(len);
    randomizeText = Text(randomText, {100, 220}, {102, 178, 255, 255}, 20);
}

void Huffman::handleEvent()
{
    while (SDL_PollEvent(&this->e) != 0)
    {
        // *Yo section ma Scroll event handle huncah hai ra

        if (e.type == SDL_QUIT ||
            e.type == SDL_MOUSEMOTION ||
            e.type == SDL_MOUSEBUTTONDOWN ||
            e.type == SDL_MOUSEBUTTONUP ||
            e.type == SDL_KEYDOWN)
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
                if (randomizeButton.isMouseClicked(window, clickedPosition))
                {
                    std::cout << "Randomized button is clicked." << std::endl;
                    randomText = generateRandomText((this->originalSize) / 8);
                    randomizeText = Text(randomText, {100, 220}, {102, 178, 255, 255}, 20);
                }

                else if (countButton.isMouseClicked(window, clickedPosition))
                {
                    std::cout << "Count button is clicked" << std::endl;
                    fMap = Hashmap(randomText);
                    pq = createPriorityQueue(fMap);
                    generateCountText(pq);
                    symbolText = Text(this->symText, {1010, 220}, {255, 102, 102, 255}, 20);
                    frequencyText = Text(this->freqText, {1200, 220}, {255, 178, 255, 255}, 20);
                }

                else if (buildButton.isMouseClicked(window, clickedPosition))
                {
                    std::cout << "Build button is clicked" << std::endl;

                    huffmanTreeRootNode = createHuffmanTree();
                    std::cout << huffmanTreeRootNode->getKey() << std::endl;
                    pq.display();
                    depthOfHuffmanTree = findDepthOfHuffmanTree(huffmanTreeRootNode);
                    treeWidth = 40 * pow(2, depthOfHuffmanTree);
                    generateHuffmanCode(huffmanTreeRootNode, "", {1500 + encodeButton.getWidth() + (treeWidth / 2), 200}, {-1, -1}, treeWidth / 2);
                    renderHuffmanTree();

                    encodeFlag = true;
                }

                else if (encodeButton.isMouseClicked(window, clickedPosition))
                {
                    std::cout << "Encode button is clicked" << std::endl;
                    generateEncodedText();
                    encodedText = Text(encText, {1500, 220}, {255, 255, 102}, 20);
                }

                else if (compressButton.isMouseClicked(window, clickedPosition))
                {
                    std::cout << "Compress button is clicked" << std::endl;
                    compressString();
                    compressedText = Text(cmprText, {50, 1150}, {153, 51, 255, 255}, 20, window.getWidth() - 100);

                    cmprBxtext = "Original string size: ";
                    cmprBxtext += std::to_string(originalSize);
                    cmprBxtext += " bits\n";
                    cmprBxtext += "Compressed string size: ";
                    cmprBxtext += std::to_string(compressedSize);
                    cmprBxtext += " bits\n";
                    cmprBxtext += "Size reduced:   ";
                    cmprBxtext += std::to_string(((float)(originalSize - compressedSize)/originalSize) * 100);
                    cmprBxtext += " %\n";
                    compressionBoxText = Text(cmprBxtext, {window.getWidth() + 20, 1600}, {255, 255, 255}, 20);
                }
            }
        }
    }
}

std::string Huffman::generateRandomText(int len)
{
    std::string alphanum = "A0B1C2D3E4F5G6H7I8J9K0L1M2N3O4P5Q6R7S8T9U0V1W2X3Y4Z5A6B7C8D9E0F1G2H3I4J5K6L7M8N9O0P1Q2R3S4T5U6V7W8X9Y0Z1A2B3C4D5E6F7G8H9I0J1K2L3M4N5O6P7Q8R9S0T1U2V3W4X5Y6Z7A8B9C0D1E2F3G4H5I6J7K8L9M0N1O2P3Q4R5S6T7U8V9W0X1Y2Z3A4B5C6D7E8F9G0H1I2";
    // std::string alphanum = "1xb2";
    std::string s;
    s.reserve(len);

    while (len--)
        s += alphanum[rand() % (alphanum.size() - 1)];
    // std::cout << s << std::endl;
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
        Node *p = copy.pop();

        // Append the key and frequency to respective text
        symText += "'";
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

        cpq.push(nodeOne->getKey() + nodeTwo->getKey(), nodeOne->getPriority() + nodeTwo->getPriority(), nodeOne, nodeTwo);
        pq.push(nodeOne->getKey() + nodeTwo->getKey(), nodeOne->getPriority() + nodeTwo->getPriority());
    }

    return cpq.pop();
}

int Huffman::findDepthOfHuffmanTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight = findDepthOfHuffmanTree(root->getLeftChild());
        int rightHeight = findDepthOfHuffmanTree(root->getRightChild());

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
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
        pq.getRenderPosition(root->getKey());
        root = S.pop();

        if (root == nullptr)
        {
            break;
        }
    }
}

void Huffman::generateHuffmanCode(Node *node, std::string encText, SDL_Point position, SDL_Point parentPosition, int treeWidth)
{

    if (node == nullptr)
    {
        return;
    }
    std::cout << node->getKey() << std::endl;

    pq.setHuffmanCodeAndRenderPosition(
        node->getKey(),
        encText, position, parentPosition);

    // Visiting left sub-tree
    if (node->getLeftChild())
    {
        generateHuffmanCode(node->getLeftChild(), encText + "0", {position.x - treeWidth / 2, position.y + 150}, position, treeWidth / 2);
    }

    // Visiting right sub tree
    if (node->getRightChild())
    {
        generateHuffmanCode(node->getRightChild(), encText + "1", {position.x + treeWidth / 2, position.y + 150}, position, treeWidth / 2);
    }
}

void Huffman::generateEncodedText()
{
    this->encText = "";
    PriorityQueue copy = pq;
    while (!copy.empty())
    {
        std::string temp = pq.getHuffmanCode(copy.pop()->getKey());
        encText += temp;
        encText += '\n';
    }
}

void Huffman::compressString()
{
    cmprText = "";
    std::string temp = "";

    for (int i = 0; i < randomText.length(); i++)
    {
        temp = "";
        temp += randomText[i];
        cmprText += pq.getHuffmanCode(temp);
        compressedSize += pq.getHuffmanCode(temp).length();
    }
}

void Huffman::renderHuffmanTree()
{

    Stack<Node *> S;
    Node *root = huffmanTreeRootNode;

    while (true)
    {
        // std::cout << root->getKey() << std::endl;
        pq.renderNode(window, root->getKey());

        if (root->getRightChild())
        {
            S.push(root->getRightChild());
        }
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

void Huffman::render()
{
    randomizeButton.render(window, 400, 71);
    countButton.render(window, 1000, 71);

    if (!randomizeText.isNull)
    {
        randomizeText.render(window);
        randomizeText.free();
    }

    if (!symbolText.isNull)
    {
        symbolText.render(window);
        symbolText.free();
    }

    if (!frequencyText.isNull)
    {
        frequencyText.render(window);
        frequencyText.free();
        buildButton.render(window, 1400, 71);
    }

    if (encodeFlag)
    {
        renderHuffmanTree();
        buildButton.free();
        encodeButton.render(window, 1400, 71);
    }

    if (!encodedText.isNull)
    {
        encodedText.render(window);
        encodedText.free();
        compressButton.render(window, 77, 1000);
    }

    if (!compressedText.isNull)
    {
        compressedText.render(window);
        compressedText.free();

        compressionBoxText.render(window);
        compressionBoxText.free();
    }
}
