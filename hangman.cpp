//hangman class file

#include <iostream>
#include <cstdlib>
#include <string>
#include "hangman.h"


using namespace std;

Hangman::Hangman()
{
    for(int i=0; i<tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->word = "empty";
        HashTable[i]->score = 0;
        HashTable[i]->next = NULL;
    }
}


//This function changes a word (key) to a number for the hash table
int Hangman::Hash(string key)
{
    //key is a word like "Paul" to add to the table
    int hsh = 0;
    int index;


    //add all the characters up to get a number
    for(int i=0; i<key.length(); i++)
    {
        hsh = hsh+(int)key[i]; //multiply this number to get a new way of storing
    }

    index = hsh % tableSize;
        // taking hsh value divided by 100 (result = remainder)
    return index;
    //Divide given number by table size and use
    //remainder as index for hash table
}


//This function adds a given word and score to the hash table
void Hangman::addItem(string word, int score)
{
    //stores index of name
    int index = Hash(word);

    if(HashTable[index]->word == "empty")
    {
        HashTable[index]->word = word;
        HashTable[index]->score = score;
        HashTable[index]->next = NULL;
    }
    else
    {   //store item in the node
        item* ptr = HashTable[index];
        item* n = new item;
        n->word = word;
        n->score = score;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        //ptr now pointing to last item in list
        ptr->next = n;
    }
}


//This will draw the hangman based on what guess they're on (ie, first, second, third, etc.)
void Hangman::drawHangman(int count)
{
	//Declarations
	string one;
	string two;
	string three;
	string four;
	string five;
	string six;
	string seven;


	one = " ----------|\n |         |\n |         |\n           |\n           |\n           |\n           |\n           |\n       --------- \n";
	two = " ----------|\n |         |\n |         |\n O         |\n           |\n           |\n           |\n           |\n       --------- \n";
	three = " ----------|\n |         |\n |         |\n O         |\n |         |\n           |\n           |\n           |\n       --------- \n";
	four = " ----------|\n |         |\n |         |\n O         |\n-|         |\n           |\n           |\n           |\n       --------- \n";
	five = " ----------|\n |         |\n |         |\n O         |\n-|-        |\n           |\n           |\n           |\n       --------- \n";
	six = " ----------|\n |         |\n |         |\n O         |\n-|-        |\n/          |\n           |\n           |\n       --------- \n";
	seven = " ----------|\n |         |\n |         |\n O         |\n-|-        |\n/ \\        |\n           |\n           |\n       --------- \n";


	//Process
	if(count == 1)
		cout << one;
	else if(count == 2)
		cout << two;
	else if(count == 3)
		cout << three;
	else if(count == 4)
		cout << four;
	else if(count == 5)
		cout << five;
	else if(count == 6)
		cout << six;
	else if(count == 7)
		cout << seven;
	else
		count = 7;
}

