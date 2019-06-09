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

list<char> getGuessedWord(string secretword,string lettersguessed){
    list<char> word;
    for(char letter:secretword){
        if(std::find(lettersguessed.begin() ,lettersguessed.end() ,letter) != lettersguessed.end())
            word.push_back(letter);
        else
            word.push_back('_');
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
    ifstream file("/Users/siddhantbansal/Desktop/Hitler_CPP/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);

    string chosenword = words[rand() % words.size()];
    transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
    list<char> chosenwordlist(chosenword.begin(), chosenword.end());

    cout << "Welcome to the game 'Hangman'!" << endl;
    cout
            << "The rules of the game are to guess the letters to replace the blanks. You will get a certain number of tries to guess the word in."
            << endl;

    cout << chosenword << endl;

    cout << "The word you have to guess is: ";

    int a = 0;
    for (char c:chosenword) {
        int isavowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

        if (isavowel)
            cout << c << " " ;
        else {
            cout << '_' << " ";
            a = a + 1;
        }
    }


    int no_of_guesses = (2 * a) - 1;
    cout << "The number of guesses are: " << no_of_guesses << endl;


    string guessedletter;
//    cout << "Please enter your guess: " << endl;
//    getline(cin, guessedletter);

    list <string> lettersguessed;

    list<char> guessedword;

    string str1 = chosenword;
    string str2 = guessedletter;
    int result = strncmp(str1.c_str(), str2.c_str(), str1.size());

    while (no_of_guesses > 0)
    {
        cout << "Please enter your guess: " << endl;
        getline(cin, guessedletter);
        cout << "Running loop number " << no_of_guesses << endl;
        if (std::find(lettersguessed.begin(), lettersguessed.end(), guessedletter) == lettersguessed.end()) {
            lettersguessed.push_back(guessedletter);
            cout << "Pushing the letter in lettersguessed" << endl;
        }
        else {
            if (std::find(lettersguessed.begin(), lettersguessed.end(), guessedletter) != lettersguessed.end()) {
                guessedword = getGuessedWord(chosenword, lettersguessed);
                cout << "Oops! You've already guessed that letter:" << endl;
            }
        }
        if (result == 0) {
            guessedword = getGuessedWord(chosenword, lettersguessed);
            cout << "Good guess! ";
        }
        else{
            guessedword = getGuessedWord(chosenword, lettersguessed);
            cout << "Oops! That letter is not in the word!" << endl;
            no_of_guesses = no_of_guesses - 1;
        }

        if (std::find(guessedword.begin(), guessedword.end(), '_') != guessedword.end()) {
            cout << "Congrats! You won!" << endl;
        exit(0);
            }

        if ((no_of_guesses == 0) &&
            (std::find(guessedword.begin(), guessedword.end(), '_') == guessedword.end())) {
            cout << "Sorry, you have run out of guesses, the word was: " << chosenword << endl;
            exit(0);
        }

        }
    return 0;
    }