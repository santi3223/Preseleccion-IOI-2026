//25 de Marzo 2026 14:06
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>
 
int main(){
	ll n, q;
	cin >> n >> q;
	vl arr(n), pref(n+5, 0);
	ff (i, 0, n) cin >> arr[i];
	ff(i, 1, n+1){
		pref[i] = arr[i-1]^pref[i-1];
	}
	while(q--){
		ll l, r;
		cin >> l >> r;
		cout << (pref[r]^pref[l-1]) << ed;
	}
	
}
