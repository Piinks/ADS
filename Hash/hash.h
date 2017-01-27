// Kate Archer
// hash.h

#ifndef HASH
#define HASH

#include <string>
#include <vector>
using namespace std;

struct Item{
    string word;
    int count = 0;
    bool assigned = false;
};

class Hash{
    public:
        Hash(int tS);
        void insert(vector<Item> &hashVector, Item newItem);
        int getFreqCount(vector<Item> &hashVector, Item newItem);
        float getLoadFactor();
        void printTable(vector<Item> &hashVector);
        int getPositionsFilled();
    private:
        int tableSize;
        int positionsFilled;
        unsigned long hashing(string word);

};

#endif
