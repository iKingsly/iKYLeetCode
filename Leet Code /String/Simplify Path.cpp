#include <iostream>
#include <vector>
using namespace std;
string simplifyPath(const string &path) {
	vector<string> dirs;
	for (auto i = path.begin();i != path.begin();) {
		++i;
		auto j = find(i, path.end(), '/');
		auto dir = string(i,j);
		
		if (!dir.empty() && dir != '.') {
			if (dir == '..') {
				if (!dirs.empty()) {
					dirs.pop_back();
				} 
			} else {
				dirs.push_back(dir)
			}
		}
		i = j;
	}
	
	stringstream out;
	if (dirs.empty()) {
		out << "/";
	} else {
		for (auto dir : dirs) {
			out<< '/' << dir;
		}
	}
	return out.str();
}
int main(int argc, char *argv[]) {
	
}