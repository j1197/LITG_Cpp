string str1 = chosenword;
string str2 = "a";
int result = strncmp(str1.c_str(), str2.c_str(), str1.size());
if (result == 0)
cout << "a" << "  ";
str2 = "e";
result = strncmp(str1.c_str(), str2.c_str(), str1.size());
if (result == 0)
cout << "e"<< "  ";
str2 = "i";
result = strncmp(str1.c_str(), str2.c_str(), str1.size());
if (result == 0)
cout << "i"<< "  ";

str2 = "o";
result = strncmp(str1.c_str(), str2.c_str(), str1.size());
if (result == 0)
cout << "o"<< "  ";
str2 = "u";
result = strncmp(str1.c_str(), str2.c_str(), str1.size());
if (result == 0)
cout << "u" << "  ";//
// Created by JP on 2019-06-08.
//

