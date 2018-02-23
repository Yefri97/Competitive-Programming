const int MX = 2e6;

bitset<MX> bs;
vector<int> primes;

void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < MX; i++) if (bs[i]) {
		for (ll j = i * i; j < MX; j += i)
			bs[j] = 0;
		primes.push_back(i);
	}
}