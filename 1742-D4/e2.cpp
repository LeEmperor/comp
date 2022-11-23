#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <bitset> 
#include <cmath> 
#include <algorithm> 
#include <set>
using namespace std;

#define nL "\n"
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;

VLL monotonic_converter(VLL raw) {
        VLL max_seen(raw.size(), 0);
        max_seen[0] = raw[0];

        for(int i = 1; i < raw.size(); i++) {
                max_seen[i] = max(raw[i], max_seen[i-1]);
        }

        return max_seen;
}

ll BS(VLL input, ll legSize) {
        ll low = 0;
        ll high = input.size() - 1;

        while(low <= high) {
                ll m = ((high - low + 1) / 2) + low;

                if(high == low) {
                        break;
                }

                if(legSize >= input[m]) {
                        low = m;
                } else if(legSize < input[m]) {
                        high = m-1;
                } 
        }

        cout << "low: " << low << " high: " << high << nL;
        return low;
}

void solve(VLL input, VLL questions) {
        VLL monotonic = monotonic_converter(input);
        VLL ans(questions.size(), 0);

        for(int i = 0; i < questions.size(); i++) {
                ans[i] = BS(input, questions[i]);


        }

        for(ll i : ans) {
                cout << i << nL;
        }

        return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases;
	cin >> testcases;

	while(testcases--) {
                ll n, q;
                cin >> n >> q;

                VLL input;
                while(n--) {
                        ll i;
                        cin >> i;
                        input.push_back(i);
                }

                VLL questions;
                while(q--) {
                        ll j;
                        cin >> j;
                        questions.push_back(j);
                }

                solve(input, questions);
	}	
}

