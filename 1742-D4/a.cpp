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

string solve(int a, int b, int c) {
    if(a+b==c) {
        return "YES";
    }
    if(b+c==a) {
        return "YES";
    }
    if(a+c==b) {
        return "YES";
    }
    return "NO";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases;
	cin >> testcases;

	while(testcases--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << nL;
	}	
}

