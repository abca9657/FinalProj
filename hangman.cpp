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
        HashTable[i]->usedWord = false;
        HashTable[i]->next = NULL;
    }
    guessTracker=1;
    score=0;
    for(int j=0; j<tableSize; j++)
    {
        fullIndex[j] = tableSize+5;
    }
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

/*
Function prototype:
void Hangman::readFileIn(string);

Function description:
This function reads in the words and score values into arrays and then calls the addItem fucntion to put them into hashtables.

Example:
Hangman obj;
obj.readFileIn("words.txt");

Pre-conditions: filename is a string with the filename already coded in.  The file is words.txt
*/

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
    //Hangman h;
    for(int i=0;i<wordCount; i++){  //puts items into hashtable
        //cout<<words[i]<<", "<<scoreArray[i]<<endl;;
        addItem(words[i], scoreArray[i]);
    }

    //Test the table:
    /*for(int j=0; j<tableSize; j++)
    {
        cout<<"index: "<<j<<" info: "<<HashTable[j]->word<<endl;;
    }*/
}


int Hangman::checkRandNum(int numToCheck)
{
    int tst = 0;
    int x=0;
    while(fullIndex[x] != numToCheck)
    {
        if(x == tableSize-1)
        {
            tst = 1;   //No found number
            break;
        }
        x++;
    }

    if(fullIndex[x] == numToCheck && tst != 1)   //This index is full, try a new one
    {
        tst = 2;
    }
    return tst;
}

std::string Hangman::getWord(int index)
{
    std::string useMe = "empty";
    //int index = randIndex();
    item* nxt = HashTable[index];
    int tst = checkRandNum(index);

    if(tst == 0)
    {
        cout<<"error, fix the checkRandNum function"<<endl;
    }
    else if(tst == 2)
    {
        cout<<"There are no more words to guess from. Your score is "<<score<<endl;
        cout<<"Lies. Here's the index and info: "<<index<<":"<<HashTable[index]->word<<endl;
    }
    else //rand number good to use:
    {
        while(nxt != NULL)
        {
            if(!nxt->usedWord)  //false, use the word
            {
                nxt->usedWord = true;
                useMe = nxt->word;
                break;
            }
            else //try the next entry in that bucket
            {
                nxt = nxt->next;
            }
        }

        if(useMe == "empty")   //move on to next index
        {
            fullIndex[trkFullIndex] = index;
            trkFullIndex++;
            index = 0;
            useMe = getWord(index);
        }
    }


    return useMe;
}

/*
Function prototype:
int Hangman::randIndex();

Function description:
This function gets a random index from the hashtable that we have made so we can get a random word.

Example:
Hangman obj;
int index= obj.randIndex();

Post-conditions: returns a positive integer
*/

int Hangman::randIndex()
{
    int index = rand() % 10;	//obtains random index
    return index;
}

/*
Function prototype:
string Hangman::checkIfGuessed(string, char, string);

Function description:
This function checks if the guessed letter is in the word for hangman.  
It also keeps track of what letters of the word have been guessed.
It also returns a string to keep inputing the trackGuess string so that it keeps track of the letters guessed.
Once the word is completely guessed then the addScore fucntion is called.

Example:
Hangman obj;
string trackGuess = obj.checkIfGuessed("banana", 'a', "______")

Pre-conditions: word is a random word from the words.txt file.  guess is a char and takes user input. trackGuess is a string of underscores or a string of underscores and letters.
Post-conditions: returns a string
*/
string Hangman::checkIfGuessed(std::string word, char guess, std::string trackGuess){
    int tracker=0;
    for(int i=0; i<word.length(); i++){   //loop through word checking each letter
        if(guess == word[i]){
            trackGuess[i]=guess;
            tracker++;
        }
        if(guess != '_'){
            trackGuess[i]=trackGuess[i];
        }
        else{
            trackGuess[i]= '_';

        }
    }
    if(tracker==0){         //check if any letters were found
        cout<<endl;
        cout<<"Letter was not in the word"<<endl;
        guessTracker++;
        drawHangman(guessTracker);
    }
    else /*if(tracker > 0)*/{         //check if any letters were found
        drawHangman(guessTracker);
    }
    if(trackGuess == word){
    	cout<<"You got the word right!  The word was: "<<word<<endl;
        addScore(word);
    }
    if(guessTracker==7){
        cout<<"You got the word incorrect.  The word was: "<<word<<endl;
        trackGuess=word;
    }
    return trackGuess;
}

/*
Function prototype:
void Hangman::addScore(string);

Function description:
This function adds the score once the word has been guessed.  The score has already been read in and the score is being tracked as well.
The Hash function is called so we can get the index of the word.
Example:
Hangman obj;
obj.addScore("add");

Pre-conditions: string word is the word the user is trying to guess and is randomly picked.
*/

void Hangman::addScore(std::string word){
    int chk = Hash(word);

    item* nxt = HashTable[chk]->next;
    if(HashTable[chk]->word == "empty")
    {
        //cout<<"chk val: "<<chk<<"\n Further info: "<<HashTable[chk]->word<<endl;
        cout<<"error, no word found"<<endl;
    }
    else
    {
        while(nxt != NULL)
        {
            if(nxt->word == word)
            {
                score = score + nxt->score;
                break;
            }
            nxt = nxt->next;
        }
    }
    cout<<"Your score is now: "<<score<<endl;
}

/*
Function prototype:
int Hangman::prompt_YN(string);

Function description:
This function finds out what the user input was for whether the user wants to play or not and it returns an integer.

Example:
Hangman obj;
int answer = obj.prompt_YN("Yes");

Pre-conditions: string reply is the user input of whethe the user wants to play the game
Post-conditions: returns integer that is 0, 1, or -1
*/

int Hangman::prompt_YN(std::string reply)
{
    guessTracker = 1;		//reinitializes guessTracker
	int answer = 0;
	std::string word = reply;


	for(int i = 0; i < reply.length(); i++)		//checks the reply to see if user wants to play
		word[i] = toupper(reply[i]);


	if(word == "YES" || word == "SURE" || word == "OK" || word == "Y")
		//PLAY
		answer = 1;
	else if(word == "NO" || word == "QUIT" || word == "STOP" || word == "TERMINATE" || word == "N")
		//STOP
		answer = 0;
	else
		//ERROR
		answer = -1;


	return(answer);		//returns int to see what the user said
}
