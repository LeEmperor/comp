#include <iostream>
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
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<string> VS;
typedef vector<VS> VSS;
typedef pair<int, int> PII;
typedef pair<int, string> PIS;

int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
}

void solve(VI input) {
        vector<vector<int>> bruh(1001, vector<int> ());

        for(int i = 0; i < input.size(); i++) {
                bruh[input[i]].push_back(i);
        }

        int ans = -1;

        for(int i = 1; i <= 1000; i++) {
                if(bruh[i].size() == 0) {
                        continue;
                }
                for(int j = i; j <= 1000; j++) {
                        if(bruh[j].size() == 0) {
                                continue;
                        }

                        if(gcd(i, j) == 1) {
                                ans = max(ans, 2 + bruh[i][bruh[i].size()-1] + bruh[j][(int)bruh[j].size()-1]);
                        }
                }
        }

        cout << ans << nL;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases;
	cin >> testcases;

	while(testcases--) {
		int n;
		cin >> n;

                VI input;

                while(n--) {
                        int i;
                        cin >> i;
                        input.push_back(i);
                }

                solve(input);
	}	
}

