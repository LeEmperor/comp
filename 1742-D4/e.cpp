#include <iostream>
#include <vector>
#include <string>
#include <bitset> 
#include <cmath> 
#include <numeric>
#include <algorithm> 
#include <set>
using namespace std;

#define nL "\n"
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;

ll last_true(Vll data, ll findThis) {
	int low = 0;
	int high = data.size() - 1;

	while(low < high) {
		int mid = low + (high - low + 1) / 2;

		if(data[mid] > findThis) {
			high = mid - 1;
		} else if(data[mid] == findThis) {
			low = mid;
		} else {
			low = mid;
		}

	}

	return low + 1;
}

Vll monotonic_converter(Vll raw) {
	Vll out(raw.size(), 0);
	out[0] = raw[0];
	
	for(int i = 1; i < raw.size(); i++) {
		out[i] = max(raw[i], out[i-1]);
	}

	return out;
}

Vll solve(Vll a, Vll b) {
	Vll ans;
	Vll monotonic = monotonic_converter(a); 
	monotonic.push_back(0);
	int bruh2 = monotonic.size();

	for(int i = 0; i < b.size(); i++) {
		ll farthest = last_true(monotonic, b[i]);
		ll bruh = 0;

		if(b[i] < a[0]) {
			ans.push_back(0);
			continue;
		}

		for(ll j = 0; j < farthest; j++) {
			bruh += a[j];
		}

		ans.push_back(bruh);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases;
	cin >> testcases;

	while(testcases--) {
		int n, q;
		cin >> n >> q;

		Vll input;
		Vll questions;

		while(n--) {
			ll i;
			cin >> i;
			input.push_back(i);
		}

		while(q--) {
			ll j;
			cin >> j;
			questions.push_back(j);
		}

		Vll ans = solve(input, questions);

		for(ll i : ans) {
			cout << i << " ";
		}

		cout << nL;
	}
}

