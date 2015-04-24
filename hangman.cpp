//hangman class file

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
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
    int guessTracker=0;
}


//This function changes a word (key) to a number for the hash table
int Hangman::Hash(std::string key)
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
void Hangman::addItem(std::string word, int score)
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
	std::string one;
	std::string two;
	std::string three;
	std::string four;
	std::string five;
	std::string six;
	std::string seven;


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



void Hangman::readFileIn(std::string filename){
    std::string line;
    //std::string words[350];
    //std::string stringScore[350];
    int wordCount=0;
    ifstream myfile;
    myfile.open(filename.c_str());   //opens the file
    if (myfile.is_open())   //goes through this code since file is open
    {
        while(getline(myfile, line)) {    //get each line in the file and puts them in array.
            int index = line.find(",");
            words[wordCount] = line.substr(0,index);
            line = line.substr(index+1);
            stringScore[wordCount]=line.substr();
            wordCount++;
        }
    }
    int scoreArray[350];
    for(int i=0; i<wordCount; i++){ //changes strings to int
      scoreArray[i] = atoi(stringScore[i].c_str());
    }
    Hangman h;
    for(int i=0;i<wordCount; i++){  //puts items into hashtable
    h.addItem(words[i], scoreArray[i]);
    }
}


int Hangman::randIndex()
{
    int index = rand() % 10;
    return index;
}

bool Hangman::checkIfGuessed(string word, char guess){
    int tracker=0;
    for(int i=0; i<word.length(); i++){         //loop through word checking each letter
        if(guess == word[i]){
            cout<<guess;
            tracker++;
        }
        else{
            cout<<"_";
        }
    }
    if(tracker==0){         //check if any letters were found
            cout<<endl;
        cout<<"Letter was not in the word"<<endl;
        guessTracker++;
        drawHangman(guessTracker);
    }
}
