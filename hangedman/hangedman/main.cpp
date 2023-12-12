#include <iostream>
#include <SFML/Graphics.hpp>
#include  "button.h"
#include "player.h"
#include "theHangedMan.h"


void reset(gamestate& player1, std::vector<Button>& buttons, std::vector<Button>& letterBoxes, sf::Font& arial) {
    for ( auto& button : buttons) {
        button.press(false);
        button.setTextColor(sf::Color::White);
    }

    std::vector<Button>letters;

    float xposLetter = (1920 - static_cast<float>(55 * player1.getWord().length())) / 2;
    for (char letter : player1.getWord()) {
        letters.emplace_back(std::string(1, letter), sf::Vector2f(40.f, 40.f), 40);
        letters.back().setFont(arial);
        letters.back().setPosition(sf::Vector2f(xposLetter, 800.f));
        letters.back().setTextColor(sf::Color::Transparent);
        xposLetter += 55;
    }

    letterBoxes.clear();

    letterBoxes = letters;

}

int main()
{
    float x = 0.0F, y = 0.0F;
    float playerw = 100.0f, playerh = 100.0f;
    int index;
    int level;
    John Johny(100, 100);
    gamestate player1("name");


    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML hanged man", sf::Style::Close | sf::Style::Resize);


    sf::Font arial;
    arial.loadFromFile("arial.ttf");


//============== CREATING AND POSSITIONING BUTTONS ===========================================================
//============================================================================================================

    std::vector<Button> buttons;
    char currentLetter = 'A';
    //1400 101
    sf::Vector2f currentPos(1200.0f, 65.0f);

    for (int row = 0; row < 7; row++) {
        for (int col = 0; col < 4; col++)
        {
            if ((row) * (4) + col > 25)
                break;
            else {
            buttons.emplace_back(std::string(1, currentLetter++), sf::Vector2f(80.0f, 80.0f));
            currentPos.x += 130.0f;
            buttons.back().setFont(arial);
            buttons.back().setPosition(currentPos);
            }
        }
        currentPos.x = 1200.0f;
        currentPos.y += 130.0f;
    }

    Button score("score: " + std::to_string(player1.getScore()), sf::Vector2f(400.0f,80.0f));
    std::cout <<player1.getScore();
    score.setFont(arial);
    score.setPosition(sf::Vector2f(100.0f, 820.0f));



    std::vector<Button>letters;

    float xposLetter = (1920 - static_cast<float>(55 * player1.getWord().length())) / 2;
    for (char letter : player1.getWord()) {
        letters.emplace_back(std::string(1, letter), sf::Vector2f(40.f, 40.f), 40);
        letters.back().setFont(arial);
        letters.back().setPosition(sf::Vector2f(xposLetter, 800.f));
        letters.back().setTextColor(sf::Color::Transparent);
        xposLetter += 55;
    }




//============================ WINDOW LOOP ===================================================================
//============================================================================================================

    while (window.isOpen()){


        sf::Event events;
        while (window.pollEvent(events)){

            switch (events.type){

            case sf::Event::Closed:
                window.close();

            case sf::Event::Resized:
                printf("New window width: %i New window height: %i\n", events.size.height, events.size.width);
                break;

            case sf::Event::TextEntered:
                if (events.text.unicode < 128) {printf("%c", events.text.unicode);}
                
                break;


            case sf::Event::MouseButtonPressed:
                if (events.mouseButton.button == sf::Mouse::Left) {
                    for (int row = 0; row < 7; row++){
                    for (int col = 0; col < 4; col++){
                        if ((row) * (4) + col > 25)
                            break;
                        else {
                            index = (row) * 4 + col;
                            if (buttons[index].isMouseOver(window)) 
                            if(!buttons[index].wasPressed())
                            {
                                bool found = player1.findLetter(buttons[index].getLetter());
                                std::cout << "you pressed " << buttons[index].getLetter()<<std::endl;
                                
                                buttons[index].changeC(found);
                                buttons[index].press(true);
                                


                                if (found){
                                    std::cout << "the letter " + buttons[index].getLetter() + " was found " << std::endl;
                                    score.setText("score: " + std::to_string(player1.getScore()));
                                    for (Button& letterBox : letters) {
                                        if (letterBox.getLetter() == buttons[index].getLetter())
                                            letterBox.setTextColor(sf::Color::White);
                                    }

                                    
                                }else {
                                    std::cout << "the letter " + buttons[index].getLetter() + " was not found " << std::endl;
                                }

                                Johny.updateColor(player1);

                            }
                        }
                    }}

                }

                break;

            default:
                break;
            }

        }



//=================== TO MOUSE MOVEMENT ======================================================================
//============================================================================================================

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        }

//================= Drawing on screen ========================================================================
//============================================================================================================
        window.clear();
        
        if (player1.getStage() <= 7) {
            for (const auto& button : buttons) {
                button.drawTo(window);
            }
        }
        else {
            sf::Text youLost;
            youLost.setString("YOU LOST");
            youLost.setCharacterSize(120);
            youLost.setFillColor(sf::Color::Black);
            youLost.setFont(arial);
            youLost.setPosition(sf::Vector2f(670.0f, 400.0f));

            sf::RectangleShape YouLostScreen;
            YouLostScreen.setFillColor(sf::Color::Red);
            YouLostScreen.setSize(sf::Vector2f(1920, 1080));
            Johny.youLose();
            Johny.draw(window);

            window.draw(YouLostScreen);

            window.draw(youLost); 

        }

        if (player1.getProgress() == player1.getWord().length()) {
            if(player1.getLevel() < 5){
                std::cout << "level up!!!" << std::endl;
                player1.levelUp();
            }
            else {
                    sf::Text youWon;
                    youWon.setString("YOU WON");
                    youWon.setCharacterSize(120);
                    youWon.setFillColor(sf::Color::Black);
                    youWon.setFont(arial);
                    youWon.setPosition(sf::Vector2f(670.0f, 400.0f));

                    sf::RectangleShape YouWonScreen;
                    YouWonScreen.setFillColor(sf::Color::Green);
                    YouWonScreen.setSize(sf::Vector2f(1920, 1080));
                    Johny.youWin();

                    window.draw(YouWonScreen);

                    window.draw(youWon);


                
            }
            
            reset(player1, buttons, letters, arial);
        }


        
        for (const auto& letterBox : letters) 
            letterBox.drawTo(window);
            
        Johny.draw(window);
        score.setTextPos(sf::Vector2f(110.0f, 820.0f));
        score.drawTo(window);
        window.display();

    }


    return 0;
}


