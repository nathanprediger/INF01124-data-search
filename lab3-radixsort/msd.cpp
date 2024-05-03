#include "msd.h"
#define M 10
#define R 256

using namespace std;

void swap(vector<string>& s, int i, int j) {
    string temp;
    temp = s[i];
    s[i] = s[j];
    s[j]=temp;
}

void swap_quick(vector<pair<int, string>>& v, int i, int j) {
    pair<int, string> temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

bool lessTest(string& v, string& w, int d) {
    int minSize = min(v.size(), w.size());
    for (int i = d; i < minSize; i++) {
        if (v[i] < w[i]) return true;
        if (v[i] > w[i]) return false;
    }

    return v.size() < w.size();
}

void insertion_sort(vector<string>& s, int l, int h, int d) {
    for (int i = l; i < h; i++) {
        for(int j = i;j > l && lessTest(s[j], s[j - 1], d); j--)
            swap(s, j, j-1);
    }
}

int returnChar(string& s, int d){
    if (d < s.size())
        return s[d];

    return -1;
}

int charAt(string& s, int d) {
    assert(d >= 0 && d <= s.size());
    if (d == s.size()) return -1;

    return s[d];
}

// 3 way partitioning quicksort: duplicate keys remain stable
void stable_quicksort(vector<pair<int, string>>& c, int lo, int hi) {
    pair<int, string> v = c[lo];
    int lt = lo, i = lo + 1, gt = hi;

    if (lo < hi) {
        while (i <= gt) {
            if (c[i].first > v.first)
                swap_quick(c, lt++, i++);
            else if (c[i].first < v.first)
                swap_quick(c, i, gt--);
            else {
                // same frequency, orders lexicographicly
                if (lessTest(v.second, c[i].second, 0)) {
                    swap_quick(c, i, gt--);
                } else {
                    swap_quick(c, lt++, i++);
                }
            }
        }

        stable_quicksort(c, lo, lt - 1);
        stable_quicksort(c, gt + 1, hi);
    }
}



void MSD_sort(vector<string>& s, int lo, int hi, int d, vector<string>& aux) {
    if (hi <= lo + M) {
        insertion_sort(s, lo, hi, d);
        return;
    }
    vector<int> count(R + 2);
    
    for (int i = lo; i < hi; i++) {
        int c = charAt(s[i], d);
        count[c + 2]++;
    }
    
    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];
    
    for (int i = lo; i < hi; i++) {
        int c = charAt(s[i], d);
        aux[count[c + 1]++] = s[i];
    }
    
    for (int i = lo; i < hi; i++)
         s[i] = (aux[i - lo]);
    
    for (int r = 0; r < R; r++)
        MSD_sort(s, lo + count[r], lo + count[r + 1], d + 1, aux);
}

void sortArq(string entrada, string saida) {
    ifstream input(entrada);
    ofstream output(saida);
    vector<string> s;
    vector<string> aux;
    string temp;

    while (input >> temp) s.push_back(temp);
    aux.resize(s.size());
    MSD_sort(s, 0, s.size(), 0, aux);

    for (int i = 0; i < s.size(); i++) {
        output << s[i] << endl;
    }

    input.close();
    output.close();
}

void sortCount(string entrada, string saida) {
    vector<pair<int, string>> s;
    ifstream input(entrada);
    ofstream output(saida);
    string temp;
    string tempAnt;
    int count = 0;

    while (input >> temp) {  
        if (temp == tempAnt) {
            count++;
        } else {
            if(count!=0) s.push_back(pair<int,string>(count, tempAnt));
            count = 1;
            tempAnt = temp;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        output << s[i].second << " " << s[i].first << endl;
    }

    input.close();
    output.close();
}

void sortFrq(string entrada, string saida) {
    vector<pair<int, string>> list;
    ifstream input(entrada);
    ofstream output(saida);
    string temp, word, delimiter = " ";
    int count;

    while (getline(input, temp)) {
        word = temp.substr(0, temp.find(delimiter));
        temp.erase(0, temp.find(" ") + delimiter.length());
        count = stoi(temp);
        list.push_back(pair<int,string>(count, word));
    }

    stable_quicksort(list, 0, list.size() - 1);

    for (int i = 0; i < 2000; i++) {
        output << list[i].second << ' ' << list[i].first << '\n';
    }

    input.close();
    output.close();
}