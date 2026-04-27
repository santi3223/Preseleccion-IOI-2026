//24 de Enero 2026 16:42
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	ll n;
	cin >> n;
	vl a(n);
	ff(i, 0, n){
		cin >> a[i];
	}
	ll m;
	cin >> m;
	vl b(m);
	ff(i, 0, m){
		cin >> b[i];
	}
	ll l;
	cin >> l;
	vl c(l);
	ff(i, 0, l){
		cin >> c[i];
	}
	map<ll, ll> mp;
	ff(i, 0, n){
		ff(j, 0, m){
			ff(k, 0, l){
				mp[a[i]+b[j]+c[k]]++;
			}
		}
	}
	ll q;
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		if(mp[x] > 0) cout << "Yes" << ed;
		else cout << "No" << ed;
	}
	
	
}
