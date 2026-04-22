//29 de Marzo 2026 14:32
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n;
	cin >> n;
	ll m = 2*n;
	vl a(n), b(n), par(m), str(m);
	unordered_map<ll, vl> odd;
	ff(i, 0, n){
		cin >> a[i] >> b[i];
		par[a[i]] = b[i];
		par[b[i]] = a[i];
		str[a[i]] = i;
		str[b[i]] = i;
		
		ll s = (a[i]+b[i])%m;
		if(s % 2 != 0){
			odd[s].pb(i);
		}
	}
	ll sz = 0, best = 1;
	for(auto &x : odd){
		if(x.se.size() > sz){
			sz = x.se.size();
			best = x.fi;
		}
	}
	
	vb isok(n, false);
	if(odd[best].size() > 0){
		for(auto &x : odd[best]){
			isok[x] = true;
		}
	}
	vl keep(n, -1);
	vb vis(m, false);
	ff(i, 0, m){
		if(isok[str[i]] || vis[i]) continue;
		ll p = i;
		while(!vis[p]){
			vis[p] = true;
			keep[str[p]] = p;
			ll q = par[p];
			vis[q] = true;
			
			p = (best-q)%m;
			if(p < 0) p += m;
		}
	}
	
	cout << n-sz << ed;
	ff(i, 0, n){
		if(isok[i]) continue;
		ll k = keep[i];
		ll d = (best-k)%m;
		if(d < 0) d += m;
		cout << i << ' ' << par[k] << ' ' << d << ed;
	}
}
