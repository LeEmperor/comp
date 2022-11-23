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

int BS(ll bruh, vector<long long> monotonic, ll LB, ll UB) {

        ll M = ((UB - LB + 1) / 2) + LB;
        if(UB == LB) {
                return UB;
        }

        if(bruh >=  monotonic[M]) {
                // in the upper half, LB becomes M
                return BS(bruh, monotonic, M, UB);
                
        } else if(bruh < monotonic[M]) {
                // in the lower half, UB becomes M
                // the step is too large
                return BS(bruh, monotonic, LB, M-1);
        }

        cout << "we are at the end for some reason" << nL;
        return -1;
}

void wombo_combo(vector<ll> steps, vector<ll> questions) {
        vector<long long> maxSeen(steps.size(), 0);
        maxSeen[0] = steps[0];
        for(int i = 1; i < steps.size(); i++) {
                maxSeen[i] = max(steps[i], maxSeen[i-1]);
        }

        for(ll i = 0; i < questions.size(); i++) {
                ll ans = 0;
                ll stoppingPoint = BS(questions[i], maxSeen, -1, steps.size()-1);
                // being very fucky when the k is less than all of the things

                for(long long j = 0; j < stoppingPoint + 1; j++) {
                        ans += steps[j];
                }

                cout << ans << " ";
        }
        cout << nL;
        
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int testcases;
	cin >> testcases;

	while(testcases--) {
		ll n, q;
		cin >> n >> q;
		
                vector<ll> steps;
                vector<ll> questions;
                while(n--) {
                        ll i;
                        cin >> i;
                        steps.push_back(i);
                }

                while(q--) {
                        ll j;
                        cin >> j;
                        questions.push_back(j);
                }

                wombo_combo(steps, questions);
	}	
}

