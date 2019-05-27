//
// Created by Siddhant Bansal on 2019-05-26.
//

/*
 * This file contains code for game Unscramble
 */

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <list>

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

    ifstream myfile ("/Users/siddhantbansal/Desktop/Hitler_CPP/words.txt");
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
    showlist(list_words);
    return 0;
}
