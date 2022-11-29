#include <iostream>
#include <vector>
#include <string>
#include <bitset> 
#include <cmath> 
#include <algorithm> 
using namespace std;

#define nL "\n"
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;

int last_true(vector<long long> data, ll findThis) {
	int low = 0;
	int high = data.size() - 1;

	while(low < high) {
		int mid = low + (high - low + 1) / 2;

		if(data[mid] > findThis) {
			high = mid - 1;
		} else if(data[mid] == findThis) {
			low = mid;
		} else {
			// data[mid] < findThis
			low = mid;
		}


	}

	return low + 1;
}

Vll solve(vector<ll> input, vector<ll> questions) {
	Vll maxSeen(input.size(), 0);
	maxSeen[0] = input[0];
	Vll ans(input.size(), 0);

	for(int i = 1; i < input.size(); i++) {
		maxSeen[i] = max(maxSeen[i], input[i-1]);
	}

	for(int i = 0; i < questions.size(); i++) {
		ans[i] = input[last_true(maxSeen, questions[i])];
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

		Vll raw;
		Vll questions;

		while(n--) {
			ll i;
			cin >> i;
			raw.push_back(i);
		}

		while(q--) {
			ll j;
			cin >> j;
			questions.push_back(j);
		}

		Vll ans = solve(raw, questions);

		for(ll i : ans) {
			cout << i << " ";
		}

		cout << nL;

	}
}

