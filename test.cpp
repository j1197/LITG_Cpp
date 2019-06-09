//
// Created by Siddhant Bansal on 2019-06-09.
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

list<char> get_guessed_word(string secretword, list<char> lettersguessed){
    list<char> word;
    for (char letter:secretword){
        cout << letter << endl;
        for (char letter_1: lettersguessed){
            int temp = (letter == letter_1);
            if (temp == 1){
                word.push_back(letter);
            }
            else{
                word.push_back('_');
            }
        }
    }
}

int main(){
    string secretword = "Siddhant";
    list<char> lettersguessed;
    lettersguessed.push_back('i');
    get_guessed_word(secretword, lettersguessed);
    return 0;
}
