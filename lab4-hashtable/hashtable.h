#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include <fstream>

using namespace std;

typedef struct player {
    int sofifa_id;
    string name, positions;
} Player;

void create_hashtable(string file);