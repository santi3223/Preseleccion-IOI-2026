//12 de Marzo 2026 22:08
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
vector<vl> pref;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n+1);
		ff(i, 1, n+1){
			ll x;
			cin >> x;
			arr[x] = i;
		}
		ll l = arr[0], r = arr[0], re = 1, me = 1;
		ff(i, 2, n+1){
			me = (i-1)/2;
			l = min({l, arr[me], n+1-i});
			r = max({r, arr[me], i});
			re += max(0LL, i-r+l);
		}
		cout << re << ed;
	}	
	
}
