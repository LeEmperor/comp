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

VI factorSets(int input) {
    VI output = {1, input};
    if(input == 2 || input == 3) {
        return output;
    }

    if(input % 2 == 0) {
        // even
        output.push_back(input / 2);
        output.push_back(2);
        return output;
    }

    // need a list of primes
    VI primes;

    for(int i : primes) {
        if(input % i == 0) {
            output.push_back(i);
            output.push_back(input / i);
        }
    }

}

int solve(VI input) {
    int a = 0;

    VVI factorizaiton;

    
    
    return a;
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

        cout << solve(input) << nL;
	}	
}

