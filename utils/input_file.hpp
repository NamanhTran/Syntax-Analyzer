#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string inputFile(string fileName) {
    std::string outputstring;
    std::string buffer;
    ifstream fin(fileName);

    //file doesnt exist
    if(!fin.is_open()) {
         cout<<"Could not open file."<<fileName;
         exit(0);
    }
    //file has no contents
    if (fin.peek() == ifstream::traits_type::eof() ) {
        cout<<"File had no contents.";
        exit(0);
    }
    //read file contents into the output string
    while (getline(fin, buffer))
        outputstring += (buffer + '\n');

    return outputstring;
}