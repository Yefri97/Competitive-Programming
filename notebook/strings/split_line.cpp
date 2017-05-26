vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}