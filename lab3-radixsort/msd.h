#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <assert.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void swap(vector<string>& s, int i, int j);
bool lessTest(string& v, string& w, int d);
void insertion_sort(vector<string>& s, int l, int h, int d);
int returnChar(string& s, int d);
int charAt(string& s, int d);
void MSD_sort(vector<string>& s, int lo, int hi, int d, vector<string>& aux);
void sortArq(string entrada, string saida);
void sortCount(string entrada, string saida);
void sortFrq(string entrada, string saida);
void swap_quick(vector<pair<int, string>>& v, int i, int j);

