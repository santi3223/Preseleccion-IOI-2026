//14 de Marzo 2026 22:51	
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
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n) cin >> arr[i];
		string str;
		cin >> str;
		ll v0 = 0, v1 = 0;
		vl pref(n+5);
		ff(i, 1, n+1){
			pref[i] = pref[i-1]^arr[i-1];
			if(str[i-1] == '1') v1 ^= arr[i-1];
			else v0 ^= arr[i-1];
		}
		
		ll q;
		cin >> q;
		while(q--){
			ll o;
			cin >> o;
			if(o == 1){
				ll l, r;
				cin >> l >> r;
				v0 = v0^(pref[r]^pref[l-1]);
				v1 = v1^(pref[r]^pref[l-1]);
			}
			else{
				ll x;
				cin >> x;
				cout << (x == 0 ? v0 : v1) << " ";
			}
		}
		cout << ed;
	}
}
