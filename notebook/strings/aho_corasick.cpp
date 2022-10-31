const int Mxe = 53;

struct AhoCorasick {
	struct Node {   
		vi edge, id;
		Node() {}
		Node(int n) { edge.assign(n, -1); }
	};
	vector<Node> t; 
	vi fail;
	AhoCorasick() { t.eb(Mxe), fail.eb(0); }
	void add(string & s, int id) {
		int cur = 0;
		for(auto & c : s) {
			int x = to_int(c);
			if(t[cur].edge[x] == -1) {
				t[cur].edge[x] = sz(t);
				t.eb(Mxe);
				fail.eb(0);
			}
			cur = t[cur].edge[x];
		}
		t[cur].id.eb(id);
	}
	void build() {
		fori(i, 0, Mxe) {
			if(t[0].edge[i] == -1) {
				t[0].edge[i] = 0;
			}
		}
		queue<int> q;
		fori(i, 0, Mxe) {
			if(t[0].edge[i] != 0) {
				q.push(t[0].edge[i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			fori(i, 0, Mxe) {
				if(t[u].edge[i] != -1) {
					int v = t[u].edge[i];
					q.push(v);
					int tmp = fail[u];
					while(t[tmp].edge[i] == -1) {
						tmp = fail[tmp];
					}
					fail[v] = t[tmp].edge[i];
				}
			}
		}
	}
	void match(string & text, vb & ans) {
		int cur = 0;
		for(auto & c : text) {
			int x = to_int(c);
			while(t[cur].edge[x] == -1) cur = fail[cur];
			cur = t[cur].edge[x];
			for(auto & i : t[cur].id) {
				ans[i] = 1;
			}
		}
	}
};