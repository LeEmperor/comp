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

string solve(VI input) {
    set<int> s;

    for(int i = 0; i < input.size(); i++) {
        if(s.find(input[i]) != s.end()) {
            return "NO";
        } else {
            s.insert(input[i]);
        }
    }

    return "YES";
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
           int a;
           cin >> a;
           input.push_back(a);
       }
       cout << solve(input) << nL;
    }
}

