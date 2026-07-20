//19 de Julio 2026 22:18
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

struct coord{
	ll a, b, c, d;
};

vl T;
ll sz;

void update(ll p, ll v){
	for(T[p += sz] += v; p > 1; p >>= 1){
		T[p >> 1] = T[p]+T[p^1];
	}
}

ll ask(ll l, ll r){
	ll c = 0;
	for(l += sz, r += sz+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) c += T[l++];
		if(r & 1) c += T[--r];
	}
	return c;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<coord> arr;
	vl lx, ly;
	ff(i, 0, n){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		arr.pb({a, b, c, d});
		lx.pb(a);
		ly.pb(b);
		lx.pb(c);
		ly.pb(d);
	}
	sort(all(lx));
	sort(all(ly));
	ly.erase(unique(all(ly)), ly.end());
	lx.erase(unique(all(lx)), lx.end());
	ff(i, 0, n){
		arr[i].a = lower_bound(all(lx), arr[i].a)-lx.begin();
		arr[i].b = lower_bound(all(ly), arr[i].b)-ly.begin();
		arr[i].c = lower_bound(all(lx), arr[i].c)-lx.begin();
		arr[i].d = lower_bound(all(ly), arr[i].d)-ly.begin();
	}
	ll szy = ly.size();
	sz = lx.size();
	
	vector<vl> add(szy), rem(szy);
	vector<vector<pll>> query(szy);
	ff(i, 0, n){
		if(arr[i].a == arr[i].c){
			ll l = arr[i].b+1, r = arr[i].d-1;
			if(l <= r){
				add[l].pb(arr[i].a);
				rem[r].pb(arr[i].a);
			}
		}
		if(arr[i].b == arr[i].d){
			ll l = arr[i].a+1, r = arr[i].c-1;
			if(l <= r){
				query[arr[i].b].pb({l, r});
			}
		}
	}
	
	T = vl(2*sz);
	//add query rem
	ll c = 0;
	ff(i, 0, szy){
		for(auto x : add[i]){
			update(x, 1);
		}
		for(auto [l, r] : query[i]){
			c += ask(l, r);
		}
		for(auto x : rem[i]){
			update(x, -1);
		}
	}
	cout << c;
	
}
