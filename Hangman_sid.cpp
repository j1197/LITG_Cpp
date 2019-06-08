//
// Created by Siddhant Bansal on 2019-06-08.
//

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
    list<string> word;
    for(char letter:secretword){
        if(std::find(lettersguessed.begin() ,lettersguessed.end() ,letter != lettersguessed.end()))
            word.push_back(letter);
        else
            word.push_back("_");
    }
    return word;
}

int main(){
    string chosen_word;
    chosen_word = getGuessedWord()
}
