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
    countBox = Rectangle({1000, 203}, 300, 700);

    randomText = generateRandomText(len);
    randomizeText = Text(randomText, {100, 220},{255, 255, 255, 255}, 20);

    fMap = Hashmap(randomText);
    pq = createPriorityQueue(fMap);
    huffmanTreeRootNode = createHuffmanTree();
    depthOfHuffmanTree = findDepthOfHuffmanTree(huffmanTreeRootNode);
    treeWidth = 20 * pow(2, depthOfHuffmanTree);

    generateHuffmanCode(huffmanTreeRootNode, "", {1500 + (treeWidth / 2), 200}, treeWidth / 2);

    encodeString();
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

            std::cout << clickedPosition.x << " " << clickedPosition.y << std::endl;
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
    std::string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

void Huffman::generateHuffmanCode(Node *node, std::string encodedText, SDL_Point position, int treeWidth)
// std::cout << encodedText << std::endl;
{

    if (node == nullptr)
    {
        return;
    }

    // Calculating the depth of the Tree
    if (depthOfHuffmanTree < encodedText.length())
    {
        depthOfHuffmanTree = encodedText.length();
    }

    // Setting the Huffman code for the give Key
    if (node->getKey() != " ")
    {
        pq.setHuffmanCodeAndRenderPosition(
            node->getKey(),
            encodedText, position);
    }

    // Visiting left sub-tree
    if (node->getLeftChild())
    {
        generateHuffmanCode(node->getLeftChild(), encodedText + "0", {position.x - treeWidth / 2, position.y + 10}, treeWidth / 2);
    }

    // Visiting right sub tree
    if (node->getRightChild())
    {
        generateHuffmanCode(node->getRightChild(), encodedText + "1", {position.x + treeWidth / 2, position.y + 10}, treeWidth / 2);
    }
}

void Huffman::encodeString()
{

    encodedText = "";
    std::string temp = "";

    for (int i = 0; i < randomText.length(); i++)
    {
        temp = "";
        temp += randomText[i];
        encodedText += pq.getHuffmanCode(temp);
    }
}

void Huffman::renderHuffmanTree()
{

    Stack<Node *> S;
    Node *root = huffmanTreeRootNode;

    Text *nodeValue;
    while (true)
    {
        // std::cout << pq.getRenderPosition(root->getKey()).x << " " << pq.getRenderPosition(root->getKey()).y << std::endl;

        nodeValue = new Text(
            root->getKey(),
            pq.getRenderPosition(root->getKey()),
            {rand() % 255, rand() % 255, rand() % 255, 255}, 20);

        nodeValue->render(window);

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

        nodeValue->free();
    }
}

void Huffman::render()
{
    randomizeButton.render(window, 400, 71);
    countButton.render(window, 1000, 71);

    randomizeText.render(window);

    randomizeText.free();

    renderHuffmanTree();
}