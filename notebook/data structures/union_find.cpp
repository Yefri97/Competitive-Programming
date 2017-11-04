struct UnionFind {
	vi p;
	UnionFind(int n) {
		p.assign(n, 0);
		fori(i, 0, n) p[ i ] = i;
	}
	int findSet( int i ) { return ( p[ i ] == i ) ? i : ( p[ i ] = findSet(p[ i ]) ); }
	void unionSet(int i, int j) { p[ findSet(j) ] = findSet(i); }
};