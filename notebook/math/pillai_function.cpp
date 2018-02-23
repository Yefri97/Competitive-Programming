/* Native solution

	int pillai(int x) {
		int ans = 0;
		for (int i = 1; i <= x; i++)
			ans += gcd(i, x);
		return ans;
	}

*/

int main() {
    sieve();
    for (int i = 1; i < MX; i++) {
        int phi = euler_phi(i);
        for (int j = 1; j * i < MX; j++)
            F[j * i] += j * phi;
    }
    return 0;
}