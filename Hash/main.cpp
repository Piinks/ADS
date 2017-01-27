// Kate Archer
// main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include "hash.h"
using namespace std;

int main(){
    string filename, word;
    int tableSize;
    vector<Item> hashTable;
    cout << "What input file would you like to use? ";
    cin >> filename;
    cout << "Please enter the table size: ";
    cin >> tableSize;

    hashTable.resize(tableSize);
    Hash myHash(tableSize);

    double startTime = clock();
    ifstream inFile;
    inFile.open(filename.c_str());
    while(inFile){
        Item newItem;
        inFile >> word;
        newItem.word = word;

        myHash.insert(hashTable, newItem);
    }
    double endTime = clock();
    double totalTime = (endTime - startTime) / CLOCKS_PER_SEC;

    cout << "It took "<< totalTime << " seconds to build frequency table" << endl;
    cout << "Load factor: " << myHash.getLoadFactor() << endl;
    cout << "There are " << myHash.getPositionsFilled() << " unique words." << endl;


    Item searchItem;
    searchItem.word = " ";
    cout << "Enter the word to search for frequency or press q to quit: ";
    cin >> searchItem.word;
    while(searchItem.word != "q"){
        cout << searchItem.word << " appeared " << myHash.getFreqCount(hashTable, searchItem) << " times." << endl;
        cout << "Enter the word to search for frequency or press q to quit: ";
        cin >> searchItem.word;
    }

    return 0;
}
