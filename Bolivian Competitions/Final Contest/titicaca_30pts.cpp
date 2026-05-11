#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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

vector<vl> conexiones;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, A, B;
	cin >> n >> m >> A >> B;
	vector<pll> coords(n);
	vb occid(n, false), orient(n, false);
	ff(i, 0, n){
		ll x, y;
		cin >> x >> y;
		coords[i] = {x, y};
		if(x == 0) occid[i] = true;
		if(x == A) orient[i] = true;
	}
	conexiones = vector<vl>(n);
	ff(i, 0, m){
		ll c, d, k;
		cin >> c >> d >> k;
		c--;
		d--;
		if(k == 1){
			conexiones[c].pb(d);
		}
		else{
			conexiones[c].pb(d);
			conexiones[d].pb(c);
		}
	}
	vector<pll> ans; //coord y, ans;
	vb visited(n, false);
	ff(i, 0, n){
		if(!occid[i]) continue;
		//cout << "I " << i << ed;
		ll coun = 0;
		visited.assign(n, 0);
		queue<ll> q;
		q.push(i);
		while(!q.empty()){
			ll cur = q.front();
			q.pop();
			if(visited[cur]) continue;
			//cout << cur << ed;
			visited[cur] = true;
			if(orient[cur]) coun++;
			for(auto son : conexiones[cur]){
				if(!visited[son]) q.push(son);
			}
		}
		//cout << ed;
		ans.pb({coords[i].se, coun});
	}
	sort(rall(ans));
	ff(i, 0, ans.size()) cout << ans[i].se << ed;
}

//hacerlo al reves
