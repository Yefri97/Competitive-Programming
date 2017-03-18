/*
ID: yefri.g1
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
int cont_id, arr[MAX_N + 10];
vector<string> names;
map<string, int> mapId;

int getId(string name) {
	if (mapId.count(name) == 0) {
		mapId[name] = cont_id++;
		names.push_back(name);
	}
	return mapId[name];
}

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    int np; fin >> np;
    cont_id = 0;
    for (int i = 0; i < np; i++) {
    	string name; fin >> name;
    	arr[getId(name)] = 0;
    }
    for (int i = 0; i < np; i++) {
    	string name; fin >> name;
    	int m, n; fin >> m >> n;
    	arr[getId(name)] -= m;
    	if (n) arr[getId(name)] += m % n;
    	for (int j = 0; j < n; j++) {
    		string gift; fin >> gift;
    		arr[getId(gift)] += m / n;
    	}
    }
    for (int i = 0; i < names.size(); i++)
    	fout << names[i] << " " << arr[i] << endl;
    return 0;
}