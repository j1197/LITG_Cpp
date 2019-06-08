#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <cctype>
#include<stdio.h>

using namespace std;

string getGuessedWord(string secretword,char lettersguessed){
    list<char> word;
    for(char letter:secretword){
        if(std::find(lettersguessed.begin() ,lettersguessed.end() ,letter != lettersguessed.end()))
            word.push_back(letter);
        else
            word.push_back("_");
    }
    return word;
}

int main () {
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    //cout << "Seed = " << time(0) << endl;
    int finalNum = rand() % (max - min + 1) + min;
    //cout << "Random number = " << finalNum << endl;
    vector <string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);

    string chosenword = words[rand() % words.size()];
    transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
    list<char> chosenwordlist(chosenword.begin(), chosenword.end());

    cout << "Welcome to the game 'Hangman'!" << endl;
    cout << "The rules of the game are to guess the letters to replace the blanks. You will get a certain number of tries to guess the word in."<< endl;

    cout << chosenword << endl;

    cout << "The word you have to guess is: ";

    int a = 0;
    for (char c:chosenword) {
        int isavowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

        if (isavowel)
            cout << c << "  ";
        else {
            cout << "_" << "  ";
            a = a + 1;
        }
    }


    int no_of_guesses = (2*a) - 1;
    cout << "The number of guesses are: " << no_of_guesses << endl;


    string guessedletter;
    cout << "Please enter your guess: " << endl;
    getline(cin, guessedletter);

    list<string> lettersguessed;

    string guessedword;

    while (no_of_guesses > 0){
            if(std::find(lettersguessed.begin(), lettersguessed.end(), guessedletter) == lettersguessed.end())
                lettersguessed.push_back(guessedletter);
            else{
                guessedword = getGuessedWord(chosenword,guessedletter);
                cout << "Oops! You've already guessed that letter:" << guessedword << endl;}

            if(std::find(chosenword.begin(), chosenword.end(), guessedletter) != chosenword.end())
            {guessedword = getGuessedWord(chosenword,guessedletter);
                cout << "Good guess! " << guessedword;}
            else{
                guessedword = getGuessedWord(chosenword,guessedletter);
                cout << "Oops! That letter is not in the word!" << guessedword;
                no_of_guesses = no_of_guesses - 1;}

            if(std::find(guessedword.begin(), guessedword.end(), "_") != guessedword.end()){
                cout << "Congrats! You won!" << endl;
                exit(0);}

            if((no_of_guesses == 0) && (std::find(guessedword.begin(), guessedword.end(), "_") == guessedword.end())){
                cout << "Sorry, you have run out of guesses, the word was: " << chosenword << endl;
                exit(0);
            }
        }

        return 0;





}