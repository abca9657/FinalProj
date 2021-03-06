
//hangman header file

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>



using namespace std;

#ifndef HANGMAN_H
#define HANGMAN_H

//these are the nodes to store the words and points
struct item
{
    std::string word;
    int score;
    bool usedWord;
    item* next;

    item(){};

    item(std::string in_word, int in_score, bool in_usedWord)
    {
        word = in_word;
        score = in_score;
        usedWord = in_usedWord;
    }
};


class Hangman
{
public:
	Hangman();
	void drawHangman(int count);
	int Hash(std::string key);           //This returns a hash number for a word
	void addItem(std::string word, int score);      //This adds a word and score to a node and puts it in the hashtable
	void readFileIn(std::string filename);
	int randIndex();
	string checkIfGuessed(std::string word, char guess, std::string trackGuess);
	void addScore(std::string word);
	int prompt_YN(std::string reply);
	std::string getWord(int index);
private:
	static const int tableSize = 10;
	item* HashTable[tableSize];     //This is the hashtable with all of our nodes in it
	std::string words[350];
	std::string stringScore[350];
	int guessTracker;
	int score = 0;
	int fullIndex[tableSize];
	int trkFullIndex = 0;
	int checkRandNum(int numToCheck);

};


#endif
