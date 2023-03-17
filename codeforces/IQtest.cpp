//26/1/23
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll size, number;
	vector< pair <ll, ll> > evens;
	vector< pair <ll, ll> > odds;

	cin >> size;

	for (ll i = 0; i < size; i++) {
		cin >> number;
		if (number % 2 == 0) evens.push_back(make_pair(number, i + 1));
		else odds.push_back(make_pair(number, i + 1));
	}

	if (evens.size() == 1) cout << evens[0].second;
	else cout << odds[0].second;
}