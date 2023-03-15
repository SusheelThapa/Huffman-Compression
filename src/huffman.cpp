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

	randomizeText = Text(randomText, {100, 220}, {255, 255, 255, 255});

    fMap = Hashmap(randomText);
    pq = createPriorityQueue(fMap);
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
        s += alphanum[rand() % alphanum.size() - 1];
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
