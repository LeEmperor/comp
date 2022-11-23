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

PI Euclid(PII p) {
        int bruh1 = p.first;
        int bruh2 = p.second;
        p.first = bruh2;
        p.second = bruh1 % bruh2;

        return p;
}

int wombo_combo(int a, int b) {
        // Euclidean Algorithm
        PII p;
        p.first = a;
        p.second = b;
        while(true) {
                if (p.second == 0) {
                        return p.first;
                } else {
                        p = Euclid(p); 
                }
        }

        return 4301761;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int a, b;
        cin >> a >> b;
        cout << wombo_combo(a, b) << nL;
}

