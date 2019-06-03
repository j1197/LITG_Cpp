//
// Created by JP on 2019-06-02.
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
#include<stdlib.h>
#include <iterator>
#include <map>

using namespace std;


string removespaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int countxx(string s, char x){
    int count = 0;
    for (int i=0;i<s.length();i++){
        if (s[i] == x)
            count++;}
    return count;
}


int actualword( string g){
    vector <string> words;
    ifstream file("/Users/siddhantbansal/Desktop/Hitler/listofanagrams.txt");
    string line;
    while (getline(file, line)) words.push_back(line);
    if (std::find(words.begin(), words.end(), g) != words.end()){
        cout<<"You are correct.";
        exit(0);}
    else{
        cout<<"You are wrong.";
        exit(0);}
    return 0;
}

int norepeats(string e,string f){
    //int freq[128];
    //for(int k = 0; k<128;k++){
    //freq[k] = 0;
    //for (char letter: e)
        //freq[letter]++;
    string myKey;
    map<string,int> countsques;
    for (char letterx: e){
        myKey = letterx;
        int myVal = countxx(e,letterx);
        countsques.insert(pair<string,int>(myKey, myVal));
    }
    //cout << countsques << endl;
    string myKey1;
    map<string,int> countsana;
    for (char letter1: f){
        myKey1 = letter1;
        int myVal1 = countxx(f,letter1);
        countsana.insert(pair<string,int>(myKey1, myVal1));
    }

    if (countsques == countsana)
        actualword(f);
    else
        cout<<"Wrong answer.";
        exit(0);


    return 0;
}


int noextra(string c, string d){
    for(char letter: d){
        if (std::find(c.begin(), c.end(), letter) == c.end()){
            cout<<"Wrong answer."<<endl;
            exit(0);}
        else
            norepeats(c,d);
    }
    return 0;

}

int letterspresent ( string a, string b){
    removespaces(a);
    removespaces(b);
    list<char> a_list(a.begin(), a.end());
    list<char> b_list(b.begin(), b.end());
    int x = 0;
    for(char letter:a_list){
        if (std::find(b_list.begin(), b_list.end(), letter) != b_list.end())
            x = x + 1;
        else{
            cout << "Sorry, wrong answer.";
            exit(0);}
    }
    if (x==a.size())
        noextra(a,b);
    else{
        cout <<"Noo";
        exit(0);}
    return 0;
    }


int main () {
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 370349;
    //cout << "Seed = " << time(0) << endl;
    int finalNum = rand() % (max - min + 1) + min;
    //cout << "Random number = " << finalNum << endl;
    vector <string> words;
    ifstream file("/Users/siddhantbansal/Desktop/Hitler/listofanagrams.txt");
    string line;
    while (getline(file, line)) words.push_back(line);


    string question = words[rand() % words.size()];
    transform(question.begin(), question.end(), question.begin(), ::tolower);
    cout << "Welcome to the game! Find anagrams for the word:  " << question<< endl;
    cout << "All the letters given in the word must be present the exact number of times as they appear in the word and no extra letters must be used." << endl;

    //list<char> questionlist(question.begin(), question.end());
    //for (char c:questionlist)
        //cout << c << "\n"

    string anagram;
    cout<<"Enter your anagram: "<<endl;
    getline(cin,anagram);
    transform(anagram.begin(), anagram.end(), anagram.begin(), ::tolower);
    if (anagram == question)
        cout << "Invalid answer" << endl;

    else if (anagram == "q"){
        cout << "Thank you for playing!" << endl;
        exit(0);}

    else
        letterspresent(question,anagram);
}


