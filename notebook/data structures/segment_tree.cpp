const int oo = 1e9, MX = 400000;

int A[MX], st[MX];

void build(int p, int L, int R) {
    if (L == R) {
        st[p] = A[L];
    } else {
        int mid = (L + R) / 2;
        build(2 * p, L, mid);
        build(2 * p + 1, mid + 1, R);
        st[p] = min(st[2 * p], st[2 * p + 1]);
    }
}

int query(int p, int L, int R, int i, int j) {
    if (R < i || L > j) return oo;
    if (i <= L && R <= j) return st[p];
    int mid = (L + R) / 2;
    int q1 = query(2 * p, L, mid, i, j);
    int q2 = query(2 * p + 1, mid + 1, R, i, j);
    return min(q1, q2);
}

void update(int p, int L, int R, int idx, int new_value) {
    if (R < idx || L > idx) return;
    if (L == R) {
        A[idx] = new_value;
        st[p] = new_value;
        return;
    }
    int mid = (L + R) / 2;
    update(2 * p, L, mid, idx, new_value);
    update(2 * p + 1, mid + 1, R, idx, new_value);
    st[p] = min(st[2 * p], st[2 * p + 1]);
}
