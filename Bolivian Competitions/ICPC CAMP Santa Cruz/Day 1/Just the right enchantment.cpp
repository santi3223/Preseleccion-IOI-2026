//25 de Mayo 2026 16:24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
const ll MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll pares = n/2;
		ll imp = n-pares;
		ll v1 = imp*(imp-1)/2;
		v1 %= MOD;
		v1 *= pares;
		v1 %= MOD;
		
		ll v2 = pares*(pares-1)*(pares-2);
		v2 /= 6;
		v2 %= MOD;
		cout << (v1+v2)%MOD << ed;
	}
}
