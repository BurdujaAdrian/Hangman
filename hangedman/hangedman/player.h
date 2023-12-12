#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

const int defaultscore = 0;
const int defaultstage = 0;
const int defaultlvl = 1;
int k = 0;




class gamestate {

public:
    gamestate () {}

    gamestate(std::string input) : lvl(defaultlvl), stage(defaultstage), guessed(0) {
        name = input;
        currentWord = chooseWord(lvl);
        std::cout << "the chosen word is " << currentWord;
        scoreIncrement = 1000;
        score = 0;
    }

    gamestate(std::string input, int lvl) {
        name = input;
        currentWord = chooseWord(lvl);
        std::cout << "the chosen word is " << currentWord;
        scoreIncrement = 1000;
        score = 0;
    }

    std::string chooseWord(int level) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 4);

        int randomIndex = dis(gen);
        return words[level - 1][randomIndex];
    }

    void levelUp() {
        lvl++;
        currentWord = chooseWord(lvl);
        std::cout << "current word is " << currentWord << std::endl;
        guessed = 0;
        scoreIncrement = 1000;

    }
    int getLevel() const{
        return lvl;
    }

    bool findLetter(std::string letter) {
        
        char guess = letter.front();
        bool rezult = false;
        for (int i = 0; i <= currentWord.length(); i++)
        {
            
            std::cout << " index is " << k << std::endl;
            if (currentWord[i] == guess) {
                score += scoreIncrement;
                guessed++;
                std::cout << "the guess is " << guess << " the letter found is " << currentWord[i] << " at possition " << i << " current score: " << score << std::endl;
                std::cout << " you have guessed " << guessed << " letters " << std::endl;
                rezult = true;
            }
        } 
        if (scoreIncrement > 100 && !rezult)
        {
            scoreIncrement -= 100;
            stage++;
        }
        std::cout << "current increment is " << scoreIncrement <<" the game stage is "<< stage << std::endl;

        return  rezult;
    }

    int getProgress() {
        return guessed;
    }

    int getScore() {
        return score;
    }

    std::string getWord() {
        return currentWord;
    }

    int getStage() {
        return stage;
    }
private:
	std::string words[5][5] = {
        {"HOUSE", "HAPPY", "TABLE", "RIVER", "MUSIC"},
        {"ELEPHANT", "SYMPHONY", "SUNSHINE", "ADVENTURE", "MYSTERY"},
        {"SERENDIPITY", "BELLIGERENT", "MELLIFLUOUS", "PONDER", "INEFFABLE"},
        {"ALGORITHM", "QUANTUM", "GENOME", "METAMORPHOSIS", "BIOINFORMATICS"},
        {"QUASIPARTICLE", "XENOPHYOPHOREA", "ZWITTERION", "PHOTOLITHOGRAPHY", "SPIROCHAETACEAE"}
    };

    std::string name;

    std::string currentWord;
    int guessed;

    int score;
    int scoreIncrement;

    int stage;

    int lvl;
    
};
