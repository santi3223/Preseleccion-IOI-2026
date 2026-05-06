//6 de Mayo 2026 11:47
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

struct fenwick{
	private:
		ll n;
		vl bit;
	public:
		fenwick(ll sz){
			n = sz;
			bit = vl(n+1, 0);
		}
		void update(ll i, ll val){
			for(++i; i <= n; i += i & -i){
				bit[i] += val;
			}
		}
		ll query(ll i){
			ll res = 0;
			for(++i; i > 0; i -= i & -i){
				res += bit[i];
			}
			return res;
		}
		ll range(ll l, ll r){
			return query(r)-query(l-1);
		}
};

vector<vl> conexiones;
vl tin, tout;
ll tim = 0;

void dfs(ll cur, ll par){
	tin[cur] = tim++;
	for(auto x : conexiones[cur]) if(x != par) dfs(x, cur);
	tout[cur] = tim-1;
}

int main(){
	ll n, q;
	cin >> n >> q;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	conexiones = vector<vl>(n);
	tin = vl(n);
	tout = vl(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	dfs(0, -1);
	fenwick ft(n);
	ff(i, 0, n){
		ft.update(tin[i], arr[i]);
	}
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll s, x;
			cin >> s >> x;
			s--;
			ll dif = x-arr[s];
			arr[s] = x;
			ft.update(tin[s], dif);
		}
		else{
			ll s;
			cin >> s;
			s--;
			cout << ft.range(tin[s], tout[s]) << ed;
		}
	}
}
