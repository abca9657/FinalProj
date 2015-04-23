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
  cout<<"test"<<endl;
}

