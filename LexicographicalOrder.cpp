#include <bits/stdc++.h>

using namespace std;

int main () {
	string s, t;
  	cin >> s >> t;
  	long m = s.size(), n = t.size();
  	if (lexicographical_compare(s.begin(), s.end(), t.begin(), t.end())) {
  		cout << "Yes\n";
  	} else {
  		cout << "No\n";
  	}
}