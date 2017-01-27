// Kate Archer
// hash.cpp

#include "hash.h"
#include <vector>
#include <iostream>
using namespace std;

Hash::Hash(int tS){
    tableSize = tS;
    positionsFilled = 0;
}

void Hash::insert(vector<Item> &hashVector, Item newItem){
    bool done = false;
    unsigned long index = hashing(newItem.word) % tableSize;
    while(hashVector[index].assigned){
        if(hashVector[index].word == newItem.word){
            hashVector[index].count+= 1;
            done = true;
            break;
        }
        else
            if(index < tableSize-1)
                index++;
            else
                index = (index+1)-tableSize;
    }
    if(!done){
        newItem.assigned = true;
        newItem.count = 1;
        hashVector[index] = newItem;
        positionsFilled += 1;
    }
}

int Hash::getFreqCount(vector<Item> &hashVector, Item searchItem){
    unsigned long index = hashing(searchItem.word) % tableSize;
    while(hashVector[index].word != searchItem.word && hashVector[index].assigned){
        if(index < tableSize-1)
            index++;
        else
            index = (index+1)-tableSize;
    }
    return hashVector[index].count;
}

float Hash::getLoadFactor(){
    float loadF = ((float)positionsFilled / (float)tableSize);
    return loadF;
}

void Hash::printTable(vector<Item> &hashVector){
    for(int i = 0; i < tableSize; i++){
        cout << hashVector[i].word << ", ";
    }
    cout << endl;
}

unsigned long Hash::hashing(string word){
    unsigned long hash = 5381;

    for(string::iterator it = word.begin(); it != word.end(); it++)
        hash = ((hash << 5) + hash ) + *it; /* hash * 33 + character */
    return hash;
}

int Hash::getPositionsFilled(){
    return positionsFilled;
}
