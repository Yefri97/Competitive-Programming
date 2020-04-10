typedef struct Item *pItem;

struct Item {
	int pr, key, cnt;
	pItem l, r;
	Item(int key) : key(key), pr(rand()), cnt(1), l(NULL), r(NULL) {}
};

int cnt(pItem t) { return t ? t->cnt : 0; }

void upd_cnt(pItem t) { if(t) t->cnt = cnt(t->l) + cnt(t->r) + 1; }

void split(pItem t, int key, pItem& l, pItem& r) { // l: < key, r: >= key
	if (!t) l = r = NULL;
	else if (key < t->key) split(t->l, key, l, t->l), r = t;
	else split(t->r, key, t->r, r), l = t;
	upd_cnt(t);
}

void insert(pItem& t, pItem it) {
	if (!t) t = it;
	else if(it->pr > t->pr) split(t, it->key, it->l, it->r), t = it;
	else insert(it->key < t->key ? t->l : t->r, it);
	upd_cnt(t);
}

void merge(pItem& t, pItem l, pItem r) {
	if (!l || !r) t = (l ? l : r);
	else if (l->pr > r->pr) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void erase(pItem& t, int key) {
	if (t->key == key) merge(t, t->l, t->r);
	else erase(key < t->key ? t->l : t->r, key);
	upd_cnt(t);
}

pItem kth(pItem t, int k) {
	if (!t) return NULL;
	if (k == cnt(t->l)) return t;
	return k < cnt(t->l) ? kth(t->l, k) : kth(t->r, k - cnt(t->l) - 1);
}

ii lb(pItem t, int key) { // position and value of lower_bound
	if (!t) return {0, 1 << 30}; // (special value)
	if (key > t->key) {
		ii w = lb(t->r, key); w.first += cnt(t->l) + 1;
		return w;
	}
	ii w = lb(t->l, key);
	if (w.first == cnt(t->l)) w.second = t->key;
	return w;
}

/* Implicit Treap with Reverse on Interval */
void pushdown(pItem it) {
	if (it && it->rev) {
		it->rev = false;
		swap(it->l, it->r);
		if (it->l) it->l->rev ^= true;
		if (it->r) it->r->rev ^= true;
	}
}

void merge(pItem& t, pItem l, pItem r) {
	pushdown(l); pushdown(r);
	if (!l || !r) t = (l ? l : r);
	else if (l->pr > r->pr) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void split(pItem t, int key, pItem& l, pItem& r, int add = 0) {
	pushdown(t);
	if (!t) l = r = NULL;
	else if (key <= add + cnt(t->l)) split(t->l, key, l, t->l, add),  r = t;
	else split (t->r, key, t->r, r, add + 1 + cnt(t->l)),  l = t;
	upd_cnt(t);
}

void reverse(pItem t, int l, int r) {
	pItem t1, t2, t3;
	split(t, l, t1, t2);
	split(t2, r - l + 1, t2, t3);
	t2->rev ^= true;
	merge(t, t1, t2);
	merge(t, t, t3);
}