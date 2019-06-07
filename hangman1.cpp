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

    //string wordtobeguessed = hideword(chosenword);

    //cout << "The word for you to guess is: " << wordtobeguessed << endl;}

    for (char c:chosenword) {
        string str1 = chosenword;
        string str2 = "a";
        int result = strncmp(str1.c_str(), str2.c_str(), str1.size());
        if (result == 0)
            cout << "a" << endl;
        else
            cout << "_" << endl;
    }
}