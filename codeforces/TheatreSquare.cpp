//26/2/23
#include <bits/stdc++.h>
using namespace std;
int main() {
	long long length, width, side, res;
	cin >> length >> width >> side;

	res = ceil((double) length / side) * ceil((double) width / side);

	cout << res;
}