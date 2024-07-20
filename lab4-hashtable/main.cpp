#include "hashtable.h"

int main() {
    vector<vector<Player>> hashtable;
    int sizeHash[4]={997, 1999,3989, 7993};
    vector<string> exp={"experimento997.txt", "experimento1999.txt", "experimento3989.txt", "experimento7993.txt"};
    for(int i=0; i<4;i++){
        cout<< "Creating HashTable with size "<< sizeHash[i]<< "..." << endl;
        hashtable=create_hashtable("input/players.csv",sizeHash[i]);
        cout<< "Searching..." << endl;
        searchHashArq(hashtable, exp[i]);
    }
    return 0;
}