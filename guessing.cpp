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

using namespace std;

int dictionaryContains(string word)
{

    vector <string> words;
    ifstream file("/Users/jp/Desktop/words.txt");
    string line;
    while (getline(file, line)) words.push_back(line);
    string dictionary[] = words;
    int size = sizeof(dictionary)/ sizeof(dictionary[0]);
    for( int i = 0; i < size; i++)
        if(dictionary[i].compare(word) == 0)
            return true;
    return false;

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
    cout << chosenword << endl;
    list<char> chosenwordlist(chosenword.begin(), chosenword.end());
    for (char c:chosenwordlist)
        cout << c << "\n";
    list<string> possiblewords;
    list<string>::iterator it;




    //for (string word:words)
        //bool Flag = true;
        //list<char> words_list_temp(words.begin(), words.end());
        //for (char letter: words_list_temp)
            //it = find(chosenwordlist.begin(), chosenwordlist.end(), letter);
            //if(it != chosenwordlist.end())
               //bool check = true;
            //else
               //bool check = false;
            //if ((check == true) && (Flag == true))
                //Flag = true;
                //possiblewords.push_back(word);
                //for (string c:possiblewords)
                //cout << c << "\n";
            //else
               // Flag = false;
        //if (Flag == true)
            //possiblewords.push_back(word);
            //for (string c:possiblewords)
                //cout << c << "\n";











    //for (list<int>::iterator i = strtolist.begin(); i != strtolist.end(); ++i)
        //cout << *i << endl;
    return 0;
}


