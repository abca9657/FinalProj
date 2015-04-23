#include <iostream>
#include <fstream>
#include "hangman.h"
#include <stdlib.h>

using namespace std;

int Hangman::main()
{
  readFileIn();
  cout<<"test"<<endl;
}


void Hangman::readFileIn(){
    std::string line;
    std::string words[350];
    std::string stringScore[350];
    int wordCount=0;
    std::ifstream myfile;
    myfile.open("words.txt");   //opens the file
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
    int scoreArray[350]   
    for(int i=0; i<wordCount; i++){ //changes strings to int
      scoreArray[i] = atoi(stringScore[i].c_str());
    }
    Hangman h;
    for(int i=0;i<wordCount; i++){  //puts items into hashtable
    h.addItem(words[i], scoreArray[i])
    }
}
