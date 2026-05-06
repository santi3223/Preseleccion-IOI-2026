#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

vector<vl> conexiones;
map<ll, bool> leaf;
vl dist;
ll maxx;
ll posm;

void dfs(ll cur, ll par){
	bool ok = true;
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		ok = false;
		dfs(x, cur);
	}
	if(ok) leaf[cur] = 1;
}

void dfs2(ll cur, ll par){
	if(leaf[cur] == 1){
		if(dist[cur] > maxx){
			maxx = dist[cur];
			posm = cur;
		}
	}
	//cout << "DFS " << cur+1 << ' ' << par+1 << ed;
	//cout << "SZ " << conexiones[cur].size() << ed;
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		//cout << "Son "<< x << ed;
		dist[x] = dist[cur]+1;
		dfs2(x, cur);
	}
}

int main(){	
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	
	/*ff(i, 0, n){
		cout << i+1 << "  ";
		for(auto &x : conexiones[i]){
			cout << x+1 << ' ';
		}
		cout << ed;
	}
	cout << ed << ed;*/
	
	if(conexiones[0].size() == 1) leaf[0] = 1;
	dfs(0, -1);
	ll ind1 = -1, ind2 = -1, ii = 0;
	for(auto &x : leaf){
		if(ii == 2) break;
		if(ind1 == -1) ind1 = x.fi;
		else ind2 = x.fi;
		ii++;
	}
	
	ll ind3 = 0;
	vl leaff;
	for(auto &x : leaf){
		leaff.pb(x.fi);
	}
	
	ll q = leaff.size();
	ll pppp = q;
	if(pppp % 2 != 0) pppp++;
	cout << pppp/2 << ed;
	ll p = 0;
	while(p < n);
		pll x = {p, leaf[p]};
		if(x.se == 0) continue;
		if(q == 1){
			ind3 = x.fi;
			break;
		}
		dist = vl(n, 0);
		maxx = -1;
		posm = -1;
		dfs2(x.fi, -1);
		ll pos1 = posm;
		cout << posm+1 << ' ';
		posm = -1;
		maxx = -1;
		dfs(pos1, -1);
		ll pos2 = posm;
		//cout << ed << "ANS ";
		cout << x.fi+1 << ' ' << posm+1 << ed;
		leaf[x.fi] = 0;
		leaf[posm] = 0;
		q-=2;
		if(leaf[])
	}
	if(q == 1){
		if(ind3 == ind1){
			cout << ind3+1 << ' ' << ind2+1 << ed;
		}
		else{
			cout << ind3+1 << ' ' << ind1+1 << ed;
		}
	}
	
}

