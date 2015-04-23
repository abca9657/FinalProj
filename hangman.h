
//hangman header file

#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

#ifndef HANGMAN_H
#define HANGMAN_H

//these are the nodes to store the words and points
struct item
{
    string word;
    int score;
    item* next;

    item(){};

    item(string in_word, int in_score)
    {
        word = in_word;
        score = in_score;
    }
};


class Hangman
{
public:
    Hangman();
	void drawHangman(int count);
	int Hash(string key);           //This returns a hash number for a word
	void addItem(string word, int score);      //This adds a word and score to a node and puts it in the hashtable

private:
    static const int tableSize = 10;
    item* HashTable[tableSize];     //This is the hashtable with all of our nodes in it

};


#endif
