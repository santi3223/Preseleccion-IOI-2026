//29 de Mayo 2026 23:51
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

const long double PI = acos(-1.0);

int main(){
	ll n;
	cin >> n;
	vl ok(1e6+5, 0);
	ff(i, 0, n){
		ll x;
		cin >> x;
		ok[x]++;
	}
	for(ll g = 1e6+1; g >= 0; g--){
		ll c = 0;
		for(ll i = g; i < 1e6+1; i += g){
			c += ok[i];
			if(c >= 2){
				cout << g;
				return 0;
			}
		}
	}
	
}
