# FinalProj
Final project for data structures created by Abby Caballero and Alejandro Alvarez
Project	Summary:
A hangman game that chooses it's words randomly from a hash table. We read in words and their associated points from a file and store them into a hash table with chaining. In order to choose a word for the game, we will choose an index at random and use the word from that index (in order). After a word has been used in the game, it is marked in the hash table as used and will not be used again. 

How to Run:
Include "words.txt" when running program. It will start up and ask if you want to play. Type yes, y, sure, or ok to play. To quit, type n, no, quit, stop, or terminate. The program will then choose a word at random from a hash table and prompt you to guess a letter. If the correct word is guessed, you will get some points that are stored in the hash table. 

Dependencies:
Requires "words.txt" file.

System Requirements:
Linux

Group Members:
Abbigail Caballero
Alejandro Alvarez

Contributors:
lamc8684

Open issues/bugs:
This program does not take into account the letters that have already been guessed, but it does not harm you if you guess them again. It also does not penalize you if you get the word wrong. 
