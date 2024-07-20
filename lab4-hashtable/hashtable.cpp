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


  vector<vector<Player>> create_hashtable(string file, int sizeHash) {
    //int nlines=get_nlines(file);
    //int size_vector=nextPrime(floor(nlines * 1.2));
    vector<vector< Player>> hashtable(sizeHash);
    ifstream input (file);
    string temp;

    getline(input, temp);
    while(getline(input, temp)){
       insertHash(temp, hashtable, sizeHash);
    }
    input.close();
    return hashtable;
}

void insertHash(string stats_player, vector<vector<Player>> &hashtable, int sizeHash)
{
    stringstream ss(stats_player);
    string temp;
    Player auxPlayer;
    vector<string> dados;
    for(int i=0; i<2;i++){
        (getline(ss, temp, ','));
        dados.push_back(temp);
    }
    getline(ss, temp);
    dados.push_back(temp);
    auxPlayer.sofifa_id=stoi(dados[0]);
    auxPlayer.name=dados[1];
    auxPlayer.positions=dados[2];
    hashtable[auxPlayer.sofifa_id % sizeHash].push_back(auxPlayer); 
}

Player searchHash(int fifa_id, vector<vector<Player>> hashtable, int &tests, int &found)
{
    int i=0;
    int key=fifa_id % hashtable.size();
    Player auxPlayer;
    auxPlayer.sofifa_id=fifa_id;
    auxPlayer.name="NAO ENCONTRADO";
    auxPlayer.positions="";
    if(!hashtable[fifa_id % hashtable.size()].empty()){
        while((i<hashtable[key].size())&&hashtable[key][i].sofifa_id!=fifa_id) i++;
        if(hashtable[key][i].sofifa_id==fifa_id){
            tests+=i;
            found++;
            auxPlayer.name=hashtable[key][i].name;
            auxPlayer.positions=hashtable[key][i].positions;
        }
    }
    return auxPlayer;
}

void searchHashArq(vector<vector<Player>> hashtable, string file_output)
{
    ifstream input ("input/consultas.csv");
    ofstream output (file_output);
    string temp;
    Player auxPlayer;
    int n_test=0;
    int deltaTest=0;;
    int maxTest=0;
    int found=0;
    output << "PARTE 2: ESTATISTICAS DAS CONSULTAS" << endl;
    auto start = chrono::high_resolution_clock::now();
    while(getline(input, temp)){
        deltaTest=n_test;
        auxPlayer=searchHash(stoi(temp), hashtable, n_test, found);
        deltaTest=n_test-deltaTest;
        if(deltaTest>=maxTest) maxTest=deltaTest;
        output << auxPlayer.sofifa_id << " " << auxPlayer.name << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    output << "TEMPO DE REALIZACAO DE TODAS AS CONSULTAS: " << duration << "ms"<< endl;
    output << "MAXIMO DE NUMERO DE TESTES POR NOME ENCONTRADO: " << maxTest << endl;
    output << "MEDIA NUMERO DE TESTES POR NOME ENCONTRADO: " << n_test/found << endl;
    input.close();
    output.close();
}
