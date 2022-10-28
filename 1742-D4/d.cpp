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

int GCD(int ina, int inb) {
    // a = 1071
    // b = 462

    int t = 0;
    int b = inb;
    int a = ina;

    while(b != 0) {
        t = b;
        b = a % b;
        a = t;
    }

    return a;

}

int solve(VI input) {

    VI bruh;

    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < input.size(); j++) {
            if(GCD(input[i], input[j]) == 1) {
                bruh.push_back(i + j);
            }
        }
    }

    if(bruh.begin() == bruh.end()) {
        return -1;
    }

    return *max_element(all(bruh)) + 2;
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
            int bruh2;
            cin >> bruh2;
            input.push_back(bruh2);
        }

        cout << solve(input) << nL;
	}	
}

