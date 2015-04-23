//hangman class file

#include <iostream>
#include <cstdlib>
#include <string>
#include "hangman.h"


using namespace std;

/*Hangman::Hangman()
{

}*/

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
