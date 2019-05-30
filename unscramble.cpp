//
// Created by Siddhant Bansal on 2019-05-26.
//

/*
 * This file contains code for game Unscramble
 */


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include<cstdlib>
#include<ctime>
#include <vector>

using namespace std;

void showlist(list <string> g)
{
    list <string> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}



list <string> create_list(){
    string line;
    list <string> main_list;

    ifstream myfile ("/Users/jp/Desktop/words.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            main_list.push_front(line);
        }
        myfile.close();
        return main_list;
    }

    else cout << "Unable to open file";
    return main_list;
}



int main () {
    list <string> list_words;
    list_words = create_list();
    //showlist(list_words);
    srand(time(0));
    int random = rand();
    int min = 0;
    int max = 44000;
    cout << "Seed = " << time(0) << endl;
    int finalNum = rand()%(max-min+1)+min;
    cout << "Random number = " << finalNum << endl;
    vector<string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);
    string a = words[rand() % words.size()];
    string b = a;
    //cout << b << endl;
    cout << a << endl;
    random_shuffle(a.begin(), a.end());
    cout << a << '\n';

    cout << b << endl;
    cout << "Enter your answer: " << endl;
    string guessedword;

    getline( cin, guessedword);

    //std::transform(guessedword.begin(), guessedword.end(), guessedword.begin(), ::tolower);

    if (b == guessedword)
        cout << "You are right! " << endl;
    else
        cout << " Wrong answer, the word was: " << b << endl;

    return 0;

}
