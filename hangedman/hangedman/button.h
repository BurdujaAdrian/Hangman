#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>




class Button {

public:

    sf::Text text;

    //=================== CONSTRUCTORS ================================================================
    //=================================================================================================
    Button() {  }

    Button(std::string t, sf::Vector2f size)
    {
        text.setString(t);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(64);


        button.setSize(size);
        button.setFillColor(sf::Color::Transparent);
        button.setOutlineColor(sf::Color::White);
        button.setOutlineThickness(5.0f);

        button.setPosition(DefPos);

    }

    Button(std::string t, sf::Vector2f size, int CharSize)
    {
        text.setString(t);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(CharSize);


        button.setSize(size);
        button.setFillColor(sf::Color::Transparent);
        button.setOutlineColor(sf::Color::White);
        button.setOutlineThickness(5.0f);

        button.setPosition(DefPos);

    }

    void resetButton(std::string t, sf::Vector2f size, int CharSize) {
        text.setString(t);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(CharSize);


        button.setSize(size);
        button.setFillColor(sf::Color::Transparent);
        button.setOutlineColor(sf::Color::White);
        button.setOutlineThickness(5.0f);

        button.setPosition(DefPos);
    }

    //=================== Modifiers ===================================================================
    //=================================================================================================
    void setFont(sf::Font& font) {
        text.setFont(font);
    }

    void setPosition(sf::Vector2f pos) {
        button.setPosition(pos);

        float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
        float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height);

        text.setPosition({ xPos, yPos });
    }

    void changeC(bool choice) {
        if (pressed) { return; }
        else {
            if (choice)
            {
                text.setFillColor(sf::Color::Green);
                std::cout << "the color was changed to green" << std::endl;
            }
            else
            {
                text.setFillColor(sf::Color::Red);
                std::cout << "the color was changed to green" << std::endl;
            }

        }
    }

    void press(bool state) {
        pressed = state;
    }

    void setText(std::string newText) {
        text.setString(newText);
    }

    void setTextColor(sf::Color color) {
        text.setFillColor(color);
    }

    void setTextPos(sf::Vector2f newpos) {
        text.setPosition(newpos);
    }

    //=================== draw to  ====================================================================
    //=================================================================================================

    void drawTo(sf::RenderWindow& window) const {
        window.draw(button);
        window.draw(text);
    }



    //=================== Info getters ================================================================
    //=================================================================================================

    bool isMouseOver(sf::RenderWindow& window) {
        float mouseX = static_cast<float>(sf::Mouse::getPosition(window).x);
        float mouseY = static_cast<float>(sf::Mouse::getPosition(window).y);

        float btnPosX = static_cast<float>(button.getPosition().x);
        float btnPosY = static_cast<float>(button.getPosition().y);

        float btnxPosWidth = button.getLocalBounds().width + button.getPosition().x;
        float btnyPosHeight = button.getLocalBounds().height + button.getPosition().y;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;

    }

    std::string getLetter() {
        return text.getString();
    }

    sf::FloatRect getBounds() {
        return button.getLocalBounds();
    }

    bool wasPressed() {

        return pressed;

    }

private:
    sf::RectangleShape button;


    bool pressed = false;

    static sf::Vector2f DefPos;
};

sf::Vector2f Button::DefPos = sf::Vector2f(0.0f, 0.0f);