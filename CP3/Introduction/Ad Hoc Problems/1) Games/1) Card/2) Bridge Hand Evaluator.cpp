#include <bits/stdc++.h>
using namespace std;

/*NOTA IMPORTANTE: LEER BIEN LOS PROBLEMAS :C*/

string n_suit = "SHDC";
map<char, int> numb = { {'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4} };
map<char, int> suit = { {'S', 0}, {'H', 1}, {'D', 2}, {'C', 3} };

int main() {
	string line;
	while (getline(cin, line)) {
		vector< vector<int> > m(10, vector<int>(10));
		vector<int> count_numb(10), count_suit(10);
		
		for (int i = 0; i < line.size(); i+=3) {
			string card = line.substr(i, 2);

			int numb_card = numb[card[0]], suit_card = suit[card[1]];
			
			count_numb[numb_card]++;
			count_suit[suit_card]++;

			m[numb_card][suit_card]++;
		}
		
		int points = 0, stopped = 0;

		for (int i = 0; i < 5; ++i) {
			/* Rule 1 */
			points += i*count_numb[i];
		}

		for (int i = 0; i < 4; ++i) {
			/* Rules 2, 3 and 4*/
			points -= (m[3][i] && count_suit[i] < 2)? 1 : 0;
			points -= (m[2][i] && count_suit[i] < 3)? 1 : 0;
			points -= (m[1][i] && count_suit[i] < 4)? 1 : 0;

			stopped += (m[4][i] || (m[3][i] && count_suit[i] > 1) || (m[2][i] && count_suit[i] > 2))? 1 : 0;
		}

		if (points >= 16 && stopped == 4) {
			cout<<"BID NO-TRUMP"<<endl;
		} else {

			int max_suit = 0, i_max_suit;
			for (int i = 0; i < 4; ++i) {

				/* Rules 5, 6 and 7*/
				points += (count_suit[i] < 2)? 2 : (count_suit[i] == 2)? 1 : 0;

				if (count_suit[i] > max_suit) {
					max_suit = count_suit[i];
					i_max_suit = i;
				}
			}

			if (points >= 14) {
				cout<<"BID "<<n_suit[i_max_suit]<<endl;
			} else {
				cout<<"PASS"<<endl;
			}

		}

	}
	return 0;
}