struct MinQueue {
	int minIn;
	stack<int> input, smin;
	MinQueue() : minIn(oo) {}
	void push(int x) {
		minIn = min(minIn, x);
		input.push(x);
	}
	void update() {
		while (!input.empty()) {
			int x = input.top(); input.pop();
			if (smin.empty() or x < smin.top())
				smin.push(x);
			else
				smin.push(smin.top());
		}
		minIn = oo;
	}
	void pop() {
		if (smin.empty())
			update();
		smin.pop();
	}
	int qmin() {
		if (smin.empty())
			update();
		return min(minIn, smin.top());
	}
};
