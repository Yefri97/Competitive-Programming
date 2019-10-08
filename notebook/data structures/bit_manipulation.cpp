#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

#define modulo(S, N) ((S) & (N - 1))
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

void printSet(int vS) {
	cout << "S = " << vS << " = ";
	stack<int> st;
	while (vS)
		st.push(vS % 2), vS /= 2;
	while (!st.empty())
		cout << st.top(), st.pop();
	cout << endl;
}

// O(3 ^ N)
void genSubmasks(int mask) {
	for (int submask = mask; true; submask = (submask - 1) & mask) {
		/* Do something */
		if (submask == 0) break;
	}
}