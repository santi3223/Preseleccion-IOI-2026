//28 de Junio 2026 16:44
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

ll MOD = 1e9+7;

vl T;
ll N;

void update(ll p, ll v){
	for(T[p+=N] += v;p > 1; p >>= 1){
		T[p >> 1] = T[p]+T[p^1];
	}
}

ll query(ll l, ll r){
	ll c = 0;
	for(l += N, r += N+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) c += T[l++];
		if(r & 1) c += T[--r];
		if(c >= MOD) c %= MOD;
	}
	return c % MOD;
}

int main(){
	ll n;
	cin >> n;
	vl arr(n), lis;
	ff(i, 0, n){
		cin >> arr[i];
		lis.pb(arr[i]);
	}
	
	sort(all(lis));
	lis.erase(unique(all(lis)), lis.end());
	N = lis.size();
	ff(i, 0, n){
		arr[i] = lower_bound(all(lis), arr[i]) - lis.begin();
	}
	T = vl(2*N, 0);
	ll c = 0;
	ff(i, 0, n){
		ll q = query(0, arr[i]-1)+1;
		c += q;
		update(arr[i], q);
		if(c >= MOD) c %= MOD;
	}
	cout << c;
	
}
