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

list<char> get_guessed_word(string secretword, list<char> lettersguessed){
    list<char> word;
//    cout << "Initial word is: ";
//    for (char letter: word){
//        cout << letter;
//    }
//    cout << endl;
    cout << "secret word received is: " << secretword << endl;
    cout << "Letter guessed received is: ";
    for (char letter: lettersguessed){    //lettersguessed is a list of all letters user has guessed -> doesn't distinguish between right and wrong
        cout << letter;
    }
    cout << endl;



    for (char letter:secretword){
        int is_vowel = (letter== 'a' || letter== 'e' || letter== 'i' || letter== 'o' || letter== 'u');
        if (is_vowel == 1){
            word.push_back(letter);
            continue;
        }
        int temp = 0;
        for (char letter_1: lettersguessed) {
            temp = (letter == letter_1);
        }
        if (temp == 1){
            word.push_back(letter);
            for(char c:word)
                cout << c << "  ";
        }
        else{
            word.push_back('_');
            for(char c:word)
                cout << c << "  ";
        }
    }
    return word;
}

int main(){
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    int finalNum = rand() % (max - min + 1) + min;
    vector <string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);

    string chosenword = words[rand() % words.size()];
    cout << "Chosen word is " << chosenword << endl;
    transform(chosenword.begin(), chosenword.end(), chosenword.begin(), ::tolower);
    list<char> chosenwordlist(chosenword.begin(), chosenword.end());

    cout << "Welcome to the game 'Hangman'!" << endl;

    cout << "The word is: ";

    list<char> letters_guessed_till_now;

    int a = 0;
    for (char letter: chosenword){
        int is_vowel = (letter== 'a' || letter== 'e' || letter== 'i' || letter== 'o' || letter== 'u');
        if (is_vowel){
//            letters_guessed_till_now.push_back(letter);
            cout << letter<< " ";
        }
        else {
            cout << '_' << " ";
            a = a + 1;
        }
    }
    cout << endl;

    int no_guesses = (2 * a) - 1;
    cout << "The number of guesses are: " << no_guesses << endl;

    char guessed_letter_user;

    list<char> guessed_word;


    list<char> rightlettersguessed;
    list<char> wronglettersguessed;

    while (no_guesses > 0){
        cout << "Enter your guess: " << endl;
        cin >> guessed_letter_user;

        int flag = 0;

        for (char letters_guessed: letters_guessed_till_now){
            if (guessed_letter_user == letters_guessed){
                flag = 1;
            }
            else{}
        }
        if (flag == 1){
            cout << "Letter already guessed" << endl;
            continue;
        }
        else{
//            cout << "New word!" << endl;
            letters_guessed_till_now.push_back(guessed_letter_user);
        }


        int flag_1 = 0;

        for (char chosen_word: chosenwordlist){
            if (chosen_word == guessed_letter_user){
//                cout << "Yaye! Correct word!" << endl;
                flag_1 = 1;
                rightlettersguessed.push_back(chosen_word);
            }
            else{
//                cout << "Wrong guess." << endl;
                  wronglettersguessed.push_back(chosen_word);
            }
        }
        if (flag_1 == 1){
            cout << "Correct Guess!" << endl;
            //guessed_word = get_guessed_word(chosenword, letters_guessed_till_now);
            guessed_word = get_guessed_word(chosenword, rightlettersguessed);
            cout << "Good Guess: ";
            for (char letter: rightlettersguessed) {
                cout << letter;
            }

            cout << endl;
        }
        else{
            cout << "Wrong Guess." << endl;
            //guessed_word = get_guessed_word(chosenword, letters_guessed_till_now);
            guessed_word = get_guessed_word(chosenword, wronglettersguessed);
            for (char letter: wronglettersguessed){
                cout << letter;
            }

            cout << endl;
            no_guesses = no_guesses - 1;
        }


    }
}
