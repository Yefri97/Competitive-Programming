#include <bits/stdc++.h>

using namespace std;

typedef vector< char > vc;
typedef vector< vc > vvc;
typedef pair<int, int> ii;

vvc board;

int mi[10] = {0, 1, 0, -1};
int mj[10] = {-1, 0, 1, 0};

void flood_fill(ii u) {
	for (int i = 0; i < 8; i++) {
		ii v = ii(u.first + mi[i], u.second + mj[i]);
		if (board[v.first][v.second] == ' ') {
			board[v.first][v.second] = '#';
			flood_fill(v);
		}
	}
}

int next_int() {
	string line;
	getline(cin, line);
	return atoi(line.c_str());
}

int main() {
	int t = next_int();
	while (t--) {
		board.clear();
		ii ini;
		string line;
		for (int i = 0; getline(cin, line) && line[0] != '_'; i++) {
			vc temp;
			for (int j = 0; j < line.size(); j++) {
				if (line[j] == '*') ini = ii(i, j);
				temp.push_back(line[j]);
			}
			board.push_back(temp);
		}
		board[ini.first][ini.second] = '#';
		flood_fill(ini);
		for (int i = 0; i < board.size(); i++) { 
			for (int j = 0; j < board[i].size(); j++) 
				cout << board[i][j]; 
			cout << endl; 
		}
		cout << line << endl;
	}
	return 0;
}