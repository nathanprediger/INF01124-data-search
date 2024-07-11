#include "hashtable.h"

using namespace std;

bool isPrime(int num) {
    if (num <= 1 || num % 2 == 0) return false;
    if (num == 2) return true;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }

    return true;
}

int nextPrime(int n) {
    while (!isPrime(n)) n++;

    return n;
}

int calculate_hash(int id, int M) {
    return id % nextPrime(floor(M * 1.2));
}



int get_nlines(string file) {
    int number_of_lines = 0;
    string line;
    ifstream input(file);

    while (getline(input, line))
        ++number_of_lines;
    
    input.close();
    return number_of_lines;
}

// vector<vector<pair<int, Player>>>
void create_hashtable(string file) {
    int nlines=get_nlines(file);
    int s_vector=nextPrime(floor(nlines * 1.2));
    vector<vector<pair<int, Player>>> hashtable(s_vector);
    ifstream input (file);
    string temp;
    while(input>>temp){
        
    }
}

