#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll N = 305, quant = 0;
vl T;
void build(){
	ll n = N;
	T[0+N] = quant;
	for(ll i = n-1; i > 0; i--) T[i] = T[i<<1]+T[i<<1|1];
}

void update(ll p, ll v){
	ll n= N;
	for(T[p+=n] += v; p > 1; p >>= 1){
		T[p>>1] = T[p]+T[p^1];
	}
}

ll query(ll l, ll r){
	ll n = N;
	ll ans = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) ans += T[l++];
		if(r & 1) ans += T[--r];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	T = vl(2*N);
	ll n;
	cin >> n;
	quant = n;
	vl v1(n), v2(n), v3(n);
	ff(i, 0, n){
		cin >> v1[i] >> v2[i] >> v3[i];
	}
	ll m;
	cin >> m;
	vb boost(305, false);
	ff(i, 0, m){
		ll x;
		cin >> x;
		boost[x] = 1;
	}
	vector<vector<pll>> sec(15000+5); //id, pos
	ff(i, 0, n){
		sec[0].pb({i, 0});
	}
	vl ans(n);
	vl carboosted(n, 0);
	
	//vl posofcar(n, 0);
	ff(cur, 0, 15000+5){ //tiempo actual
		if(sec[cur].empty()) continue;
		//cout << "TIEMPO " << cur << ed;
		vector<pair<ll, pll>> upd; //id, tiempo de next position, posicion actual
		for(auto [id, pos] : sec[cur]){
			//posofcar[id] = pos;
			//cout << "ID" << ' ' << "POS" << ed;
			//cout << id << ' ' << pos << ed;
			if(pos >= 300){
				ans[id] = cur;
				continue;
			}
			if(carboosted[id] > 0){
				carboosted[id]--;
				upd.pb({id, {cur+1, pos}});
			}
			else if(boost[pos]){
				ll x = query(pos+1, 300);
				/*if(id == 0){
					ff(i, 0, 301){
						cout << query(i, i) << ' ';
					}
					cout << ed;
				}*/
				carboosted[id] = x%20;
				//cout << id << ' ' << "BOOST " << x << ' ' << carboosted[id] << ed;
				/*ff(i, 0, n){
					cout << posofcar[i] << ' ';
				}
				cout << ed;*/
				if(carboosted[id] > 0){
					carboosted[id]--;
					upd.pb({id, {cur+1, pos}});
				}
				else{
					ll nxt = v1[id];
					ll hun = 100, dos = 200, tr = 300;
					if(hun <= pos && pos < dos) nxt = v2[id];
					if(dos <= pos && pos < tr) nxt = v3[id];
					upd.pb({id, {cur+nxt, pos}});
				}
			}
			else{
				ll nxt = v1[id];
				ll hun = 100, dos = 200, tr = 300;
				if(hun <= pos && pos < dos) nxt = v2[id];
				if(dos <= pos && pos < tr) nxt = v3[id];
				upd.pb({id, {cur+nxt, pos}});
			}
		}
		//cout << ed << "UPDATE" << ed;
		ff(i, 0, upd.size()){
			ll id = upd[i].fi, nw = upd[i].se.fi, actual = upd[i].se.se;
			//cout << "ID" << ' ' << "NW" << ' ' << "AC" << ed;
			//cout << id << "  " << nw << "  " << actual << ed;
			ll totalenpos = query(actual, actual);
			update(actual, -1);
			sec[nw].pb({id, actual+1});
			ll totalennext = query(actual+1, actual+1);
			update(actual+1, 1);
			//cout << "CHECK" << totalenpos << ' ' << query(actual, actual) << " | " << totalennext << ' ' << query(actual+1, actual+1) << ed;
			
		}
		//cout << "=======================" << ed;
	}
	
	for(auto x : ans) cout << x << ed;
	
}
