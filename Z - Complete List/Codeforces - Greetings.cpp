#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

vl T;
ll n;

void update(ll p, ll v){
	for(T[p+=n] += v; p > 1; p >>= 1){
		T[p >> 1] = T[p]+T[p^1];
	}
}

ll query(ll l, ll r){
	ll c = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) c += T[l++];
		if(r & 1) c += T[--r];
	}
	return c;
}

bool comp(pll a, pll b){
	if(a.fi == b.fi) return a.se > b.se;
	return a.fi < b.fi;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		cin >> n;
		vl lis;
		vector<pll> arr(n);
		ff(i, 0, n){
			ll a, b;
			cin >> a >> b;
			arr[i] = {a, b};
			lis.pb(b);
		}
		sort(all(lis));
		ff(i, 0, n){
			arr[i].se = lower_bound(all(lis), arr[i].se) - lis.begin();
		}
		n = lis.size();
		T = vl(2*n);
		ll c = 0;
		sort(all(arr), comp);
		reverse(all(arr));
		for(auto [l, r] : arr){
			c += query(0, r);
			update(r, 1);
		}
		cout << c << ed;
	}
}
