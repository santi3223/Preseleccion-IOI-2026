//22 de Abril 2026 19:19
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

vl prims;

void sieve(){
	vb arr(sqrt(1e9)+100, 0);
	ff(i, 2, sqrt(1e9)+100){
		if(arr[i] == 1) continue;
		prims.pb(i);
		for(ll j = i*i; j <= sqrt(1e9)+100; j += i){
			arr[j] = 1;
		}
	}
}

int main(){
	sieve();
	/*cout << sqrt(1e9) << ' ' << prims.size() << ed;
	ff(i, 0, prims.size()){
		cout << prims[i] << ' ';
	}*/
	ll t;
	cin >> t;
	while(t--){
		ll l, r;
		cin >> l >> r;
		vb arr(r-l+1, 0);
		for(auto p : prims){
			if(p*p > r) break;
			ll st = ((l+p-1)/p)*p;
			st = max(st, p*p);
			for(ll j = st; j <= r; j += p){
				arr[j-l] = 1;
			}
		}
		if(l == 1) arr[0] = 1;
		ff(i, 0, r-l+1){
			if(arr[i] == 1) continue;
			cout << i+l << ed;
		}
		cout << ed;
	}
}
