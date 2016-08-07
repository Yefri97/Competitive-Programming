#include <bits/stdc++.h>
using namespace std;

string s = "NESW";
map<char, int> deal = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

string s_suit = "CDSH";
map<char, int> suit = {{'C', 0}, {'D', 1}, {'S', 2}, {'H', 3}};

string s_value = "23456789TJQKA";
map<char, int> value = {{'2', 0}, {'3', 1}, {'4', 2}, {'5', 3},
						{'6', 4}, {'7', 5}, {'8', 6}, {'9', 7}, {'T', 8}, 
						{'J', 9}, {'Q', 10}, {'K', 11}, {'A', 12}};

int main() {
	char c;
	while (cin>>c && c != '#') {
		vector < vector< pair<int, int> > > v(5);
		for (int n = 0, player = deal[c]+1; n < 2; ++n) {
			string line; cin>>line;
			for (int i = 0; i < line.size(); i += 2, player++) {
				v[player%4].push_back(make_pair(suit[line[i]], value[line[i+1]]));
			}
		}

		for (int j = 2; j < 6; ++j) {
			sort(v[j%4].begin(), v[j%4].end()); 
		}

		for (int j = 2; j < 6; ++j) {
			cout<<s[j%4]<<":";
			for (int i = 0; i < 13; ++i) {
				pair<int, int> p = v[j%4][i];
				cout<<" "<<s_suit[p.first]<<s_value[p.second];
			}
			cout<<endl;
		}
	}
	return 0;
}