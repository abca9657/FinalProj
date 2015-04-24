#include <iostream>
#include <fstream>
#include "hangman.h"
#include <stdlib.h>

using namespace std;

int main()
{
      Hangman obj;
    string file="words.txt";
  obj.readFileIn(file);

  char guess;
  cin>>guess;
    string trackGuess = obj.checkIfGuessed("banana", guess,"ba_a_a");
cout<<trackGuess;
}

