//
// Created by JP on 2019-06-02.
//

//
// Created by JP on 2019-05-30.
//

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>
#include <cctype>
#include <algorithm>

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
    cout << "Welcome to the game! You will be given a word and you have to guess other possible words from it.\n " << endl;
    cout << "Your word is: " << chosenword << endl;


    list<char> chosenwordlist(chosenword.begin(), chosenword.end());
    for (char c:chosenwordlist)
        cout << c << "\n";

    list<string> possiblewords;

    for(string word: words)
        list<char> word_list_temp(word_list_temp.begin(), word_list_temp.end());
        bool flag = true;
        for(char letter: word_list_temp)
            bool found = (std::find(chosenwordlist.begin(), chosenwordlist.end(), letter) != chosenwordlist.end());
            if (found && flag)
                flag = true;
            else
                flag = false;
        if (flag)
            possiblewords.push_back(word);


    return 0;
}


