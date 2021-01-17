// inverso modular
inv[1] = 1;
for (ll a = 2; a < MN; a++) inv[a] = MD - (ll)(MD / a) * inv[MD % a] % MD;

// ¿Cuántas formas hay de partir un conjunto de n elementos en k conjuntos?
fori(i, 1, MN) Stirling[i][1] = 1;
fori(i, 2, MN) Stirling[1][i] = 0;
fori(i, 2, MN) fori(j, 2, MN)
	Stirling[i][j] = (Stirling[i - 1][j - 1] + j * Stirling[i - 1][j] % MD) % MD;