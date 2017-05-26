// O(2^N * N)
int n;
int g[MAXN];
int dp[1 << (MAXN-1)];

void hamiltonianDP() {
	dp[0] = 1;
	fori(bitmask, 0, 1 << (n-1)) {
		fori(u, 1, n) {
			int bit = 1 << (u-1);
			if ((bitmask & bit) == 0)
				continue;
			int prev = bitmask ^ bit;
			if ((g[u] & dp[prev]) != 0)
				dp[bitmask] |= 1 << u;
		}
	}
}