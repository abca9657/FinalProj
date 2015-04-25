#include <iostream>
#include <fstream>
#include <string>
#include "hangman.h"
#include <stdlib.h>

using namespace std;

int main()
{
    Hangman obj;

    string file="words.txt";
    obj.readFileIn(file);
    int ans;
    int index;
    string reply;
    string wordToGuess;
    bool stopPlay = false;
    char guess;
    int checkIfWin = 0;

    //Start game:
    while(!stopPlay)
    {
        cout<<"\n-------------  HANGMAN GAME ------------\n"<<endl;

        cout << "\n\nDo you want to play hangman? (y or n) ";
        cin >> reply;
        ans = obj.prompt_YN(reply);

        //check answer:
        if(ans == 0)  //STOP GAMEPLAY
        {
            stopPlay = true;
        }
        else if(ans == -1)   //ERROR IN GAMEPLAY
        {
            cout << "\nError, please enter (y or n): \n";
            continue;
        }
        else  //PLAY THE GAME
        {
            cout<<"Let's Play!\n"<<endl;
            obj.drawHangman(0);
            index = obj.randIndex();
            wordToGuess = obj.getWord(index);

            string maskedWord;
            string tmpStr = "_";
            for(int l = 0; l < wordToGuess.length(); l++)
            {
                maskedWord.append(tmpStr);
            }
            cout << maskedWord << endl;
            string trackGuess=maskedWord;
            int playTheGame = 0;
            while(playTheGame != 1)
            {
                cout<<"Type a guess"<<endl;
                cin>>guess;

                trackGuess = obj.checkIfGuessed(wordToGuess, guess,trackGuess);
                cout<<trackGuess<<endl;


            }

        } //end PLAY else statement
    }//end stopPlay

}

