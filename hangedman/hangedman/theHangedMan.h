#pragma once
#include "SFML/Graphics.hpp"

class John {
public:
    John(float x, float y) {

        base.setFillColor(sf::Color::White);
        baseStep.setFillColor(sf::Color::White);

        verticalPole.setFillColor(sf::Color::White);
        horizontalPole.setFillColor(sf::Color::White);

        rope.setFillColor(sf::Color::Transparent);
        head.setFillColor(sf::Color::Transparent);
        torso.setFillColor(sf::Color::Transparent);
        leftArm.setFillColor(sf::Color::Transparent);
        rightArm.setFillColor(sf::Color::Transparent);
        leftLeg.setFillColor(sf::Color::Transparent);
        rightLeg.setFillColor(sf::Color::Transparent);

        base.setSize(sf::Vector2f(260.f, 20.f));
        base.setPosition(x+190, y+630);

        baseStep.setSize(sf::Vector2f(160.0f, 20.0f));
        baseStep.setPosition(x + 240, y + 610);

        verticalPole.setSize(sf::Vector2f(20.f, 650.f));
        verticalPole.setPosition(x + 100.f, y);

        horizontalPole.setSize(sf::Vector2f(400.f, 20.f));
        horizontalPole.setPosition(x + 100.f, y);

        rope.setSize(sf::Vector2f(10.0f, 180.0f));
        rope.setPosition(x + 315.f, y + 30.f);

        head.setRadius(40.f);
        head.setPosition(x + 280.f, y + 170.f);

        torso.setSize(sf::Vector2f(60.f, 180.f));
        torso.setPosition(x + 290.f, y + 260.f);

        leftArm.setSize(sf::Vector2f(15.f, 170.f));
        leftArm.setPosition(x + 260.f, y + 260.f);

        rightArm.setSize(sf::Vector2f(15.f, 170.f));
        rightArm.setPosition(x + 370.f, y + 260.f);

        leftLeg.setSize(sf::Vector2f(20.f, 150.f));
        leftLeg.setPosition(x + 290.0f, y + 450.f);

        rightLeg.setSize(sf::Vector2f(20.f, 150.f));
        rightLeg.setPosition(x + 330.0f, y + 450.f);
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(base);
        window.draw(baseStep);
        window.draw(verticalPole);
        window.draw(horizontalPole);
        window.draw(rope);
        window.draw(head);
        window.draw(torso);
        window.draw(leftArm);
        window.draw(rightArm);
        window.draw(leftLeg);
        window.draw(rightLeg);
    }

    void youLose() {
        base.setFillColor(sf::Color::Transparent);
        baseStep.setFillColor(sf::Color::Transparent);

        verticalPole.setFillColor(sf::Color::Black);
        horizontalPole.setFillColor(sf::Color::Black);

        rope.setFillColor(sf::Color::Black);
        head.setFillColor(sf::Color::Black);
        torso.setFillColor(sf::Color::Black);
        leftArm.setFillColor(sf::Color::Black);
        rightArm.setFillColor(sf::Color::Black);
        leftLeg.setFillColor(sf::Color::Black);
        rightLeg.setFillColor(sf::Color::Black);


        rope.setSize(sf::Vector2f(10.0f, 180.0f));
        rope.setPosition( 415.f, 130.f);

        head.setRadius(40.f);
        head.setPosition( 370.f, 300.f);

        torso.setSize(sf::Vector2f(60.f, 180.f));
        torso.setPosition( 390.f, 370.f);

        leftArm.setSize(sf::Vector2f(15.f, 170.f));
        leftArm.setPosition( 370.f, 375.f);

        rightArm.setSize(sf::Vector2f(15.f, 170.f));
        rightArm.setPosition( 455.f, 375.f);

        leftLeg.setSize(sf::Vector2f(20.f, 150.f));
        leftLeg.setPosition( 390.0f, 560.f);

        rightLeg.setSize(sf::Vector2f(20.f, 150.f));
        rightLeg.setPosition( 430.0f, 560.f);
    }

    void youWin() {
        base.setFillColor(sf::Color::Transparent);
        baseStep.setFillColor(sf::Color::Transparent);

        verticalPole.setFillColor(sf::Color::Black);
        horizontalPole.setFillColor(sf::Color::Black);

        rope.setFillColor(sf::Color::Transparent);
        head.setFillColor(sf::Color::Black);
        torso.setFillColor(sf::Color::Black);
        leftArm.setFillColor(sf::Color::Black);
        rightArm.setFillColor(sf::Color::Black);
        leftLeg.setFillColor(sf::Color::Black);
        rightLeg.setFillColor(sf::Color::Black);


        rope.setSize(sf::Vector2f(10.0f, 180.0f));
        rope.setPosition(415.f, 130.f);

        head.setRadius(40.f);
        head.setPosition( 380.f, 320.f);

        torso.setSize(sf::Vector2f(60.f, 180.f));
        torso.setPosition(390.f, 410.f);

        leftArm.setSize(sf::Vector2f(15.f, 170.f));
        leftArm.setPosition(380.f, 410.f);
        leftArm.setRotation(135.0f);

        rightArm.setSize(sf::Vector2f(15.f, 170.f));
        rightArm.setPosition(470.f, 420.f);
        rightArm.setRotation(-135.0f);

        leftLeg.setSize(sf::Vector2f(20.f, 150.f));
        leftLeg.setPosition(390.0f, 600.f);

        rightLeg.setSize(sf::Vector2f(20.f, 150.f));
        rightLeg.setPosition(430.0f, 600.f);
    }

    void updateColor(gamestate state) {
        int stage = state.getStage();

        base.setFillColor(sf::Color::White);
        baseStep.setFillColor(sf::Color::White);
        verticalPole.setFillColor(sf::Color::White);
        horizontalPole.setFillColor(sf::Color::White);

        if (stage < 1)
            rope.setFillColor(sf::Color::Transparent);
        else
            rope.setFillColor(sf::Color::White);

        if (stage < 2)
            head.setFillColor(sf::Color::Transparent);
        else
            head.setFillColor(sf::Color::White);
        
        if (stage < 3)
            torso.setFillColor(sf::Color::Transparent);
        else
            torso.setFillColor(sf::Color::White);

        if (stage < 4)
            leftArm.setFillColor(sf::Color::Transparent);
        else
            leftArm.setFillColor(sf::Color::White);

        if (stage < 5)
            rightArm.setFillColor(sf::Color::Transparent);
        else
            rightArm.setFillColor(sf::Color::White); 
        
        if (stage < 6)
            leftLeg.setFillColor(sf::Color::Transparent);
        else
            leftLeg.setFillColor(sf::Color::White);

        if (stage < 7)
            rightLeg.setFillColor(sf::Color::Transparent);
        else
            rightLeg.setFillColor(sf::Color::White);

        if (stage < 8){
            base.setFillColor(sf::Color::White);
            baseStep.setFillColor(sf::Color::White);
        }
        else{
            base.setFillColor(sf::Color::Transparent);
            baseStep.setFillColor(sf::Color::Transparent);
        }

        verticalPole.setFillColor(sf::Color::White);
        horizontalPole.setFillColor(sf::Color::White);
        
    }


private:
    sf::RectangleShape base;
    sf::RectangleShape baseStep;
    sf::RectangleShape verticalPole;
    sf::RectangleShape horizontalPole;
    sf::RectangleShape rope;
    sf::CircleShape head;
    sf::RectangleShape torso;
    sf::RectangleShape leftArm;
    sf::RectangleShape rightArm;
    sf::RectangleShape leftLeg;
    sf::RectangleShape rightLeg;
};
