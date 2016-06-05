#include <bits/stdc++.h>
using namespace std;

deque<int> heap;
vector< deque<int> > v_deck(5);
map<char, int> value = {{'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4}};

void take_heap(int player) {

	deque<int> &deck = v_deck[player];

	while (!heap.empty()) {
		deck.push_back(heap.back()); heap.pop_back();
	}
	
}

int cover(int player, int num_cover, bool face_card) {

	deque<int> &deck = v_deck[player];

	while (num_cover--) {
		if (deck.empty()) return !player;

		int card_front = deck.front();
		heap.push_front(card_front); deck.pop_front();
		if (card_front) return cover(!player, card_front, true);
	}
		
	if (face_card) {
		take_heap(!player);
	}

	return cover(!player, 1, false);
	
}

int main() {
	string card;
	while(cin>>card && card != "#") {
		v_deck[0].push_front(value[card[1]]);
		for (int i = 1; i < 52; ++i) {
			cin>>card;
			v_deck[i & 1].push_front(value[card[1]]);
		}

		int target = cover(0, 1, false);
		printf("%d%3d\n", ((target == 0)? 2 : 1), v_deck[target].size());

		v_deck[0].clear(); v_deck[1].clear(); heap.clear();
	}
	return 0;
}