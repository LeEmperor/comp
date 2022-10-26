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

char solve(VS input) {
    for(string s : input) {
        if(s == "RRRRRRRR") {
            return 'R';
        } else {
        }
    }

    return 'B';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases;
	cin >> testcases;

	while(testcases--) {
        VS input;
        for(int i = 0; i < 8; i++) {
            string line;
            cin >> line;
            input.push_back(line);
        }
        cout << solve(input) << nL;
	}	
}

