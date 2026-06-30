//28 de Junio 2026 12:16
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

struct Query{
	ll id, a, b;
};

ll N;
vl T;

void build(vl &a){
	ff(i, 0, N) T[i+N] = a[i];
	for(ll i = N-1; i > 0; i--) T[i] = T[i << 1] + T[i << 1 | 1];
}

void update(ll p, ll v){
	for(T[p += N] += v; p > 1; p >>= 1){
		T[p >> 1] = T[p]+T[p^1];
	}
}

ll ask(ll l, ll r){
	ll c = 0;
	for(l += N, r += N+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) c += T[l++];
		if(r & 1) c += T[--r];
	}
	return c;
}

int main(){
	ll n, q;
	cin >> n >> q;
	vl lis;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
		lis.pb(arr[i]);
	}
	
	vector<Query> query(q);
	ff(i, 0, q){
		char c;
		ll a, b;
		cin >> c >> a >> b;
		query[i] = {1, a, b};
		if(c == '?') query[i].id = 2;
		lis.pb(b);
		if(c == '?') lis.pb(a);
	}
	sort(all(lis));
	lis.erase(unique(all(lis)), lis.end());
	N = lis.size();
	vl base(N, 0);
	ff(i, 0, n){
		arr[i] = lower_bound(all(lis), arr[i]) - lis.begin();
		base[arr[i]]++;
	}
	
	T = vl(2*N);
	build(base);
	ff(i, 0, q){
		ll id = query[i].id;
		ll a = query[i].a-1;
		ll b = lower_bound(all(lis), query[i].b) - lis.begin();
		if(id == 1){ //!
			update(arr[a], -1);
			arr[a] = b;
			update(b, 1);
		}
		else{
			a = lower_bound(all(lis), query[i].a) - lis.begin();
			cout << ask(a, b) << ed;
		}
	}
}
