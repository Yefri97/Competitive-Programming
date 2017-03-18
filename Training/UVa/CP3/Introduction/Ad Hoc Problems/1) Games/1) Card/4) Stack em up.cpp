#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

map<int, string> toValue = {{1, "Ace"}, {11, "Jack"}, {12, "Queen"}, {13, "King"}};
map<int, string> toSuit = {{0, "Clubs"}, {1, "Diamonds"}, {2, "Hearts"}, {3, "Spades"}};

string card(int n) {
	int v = (n%13)+1;
	string value = (v > 1 && v < 11)? to_string(v) : toValue[v];
	string suit = toSuit[ceil(double(n)/13)-1];
	string target = value + " of " + suit;
	return target;
}

vector<int> shuff(vector<int> t, vector<int> s) {
	vector <int> temp;
	for (int i = 0; i < 52; ++i) {
		temp.push_back(t[s[i]-1]);
	}
	return temp;
}

vector<int> init() {
	vector <int> v;
	for (int i = 0; i < 52; ++i) {
		v.push_back(i+1);
	}
	return v;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T; cin>>T;
	while (T--) {
		int N; cin>>N;
		vector< vector <int> > shuffles(N, vector<int>(52));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 52; ++j) {
				cin>>shuffles[i][j];
			}
		}
		vector< vector <int> > deck;
		deck.push_back(init());
		
		string b; getline(cin, b);
		
		string k;
		while (getline(cin, k) && k.size()) {
			deck.push_back(shuff(deck.back(), shuffles[atoi(k.c_str())-1]));
		}

		vector<int> target = deck.back();
		for (int i = 0; i < 52; ++i) {
			string s = card(target[i]);
			cout<<s<<endl;
		}
		
		if (T>0) cout<<endl;

	}
	
}