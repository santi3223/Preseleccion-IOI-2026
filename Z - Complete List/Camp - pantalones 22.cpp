#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

vector<vl> jefes;
vector<vl> tod;
ll M;
vector<vl> conexiones;
vl sz;
bool ok = true;
vb visited;

void recur(ll i, vl ord){
	if(i == M){
		tod.pb(ord);
		return;
	}
	vl cur = ord;
	cur.pb(i);
	recur(i+1, cur);
	recur(i+1, ord);
	
}

void dfs(ll cur){
	if(!ok) return;
	if(visited[cur]) return;
	visited[cur] = 1;
	sz[cur]++;
	for(auto &x : conexiones[cur]){
		dfs(x);
		sz[cur] += sz[x];
	}
}


int main(){
	ll n;
	cin >> n;
	jefes = vector<vl>(n);
	vector<pll> arr;
	ff(i, 0, n){
		ll x;
		cin >> x;
		ff(j, 0, x){
			ll p;
			cin >> p;
			p--;
			//cout << p << ' ' << i << ed;
			arr.pb({p, i});
			jefes[i].pb(p);
		}
	}
	M = arr.size();
	//cout << "M " << M << ed;
	recur(0, {});
	/*ff(i, 0, tod.size()-1){
		cout << i << "  ";
		ff(j, 0, tod[i].size()){
			cout << tod[i][j] << ' ';
		}
		cout << ed;
	}
	cout << "ok" << ed;*/
	ll minn = LLONG_MAX;
	ff(i, 0, tod.size()){
		if(tod[i].size() != n-1) continue;
		//cout << i << "  ";
		vl c2(n, 0);
		for(auto &x : tod[i]){
			//cout << arr[x].fi+1 << ' ' << arr[x].se+1 << "   ";
			c2[arr[x].se]++;
			
		}
		//cout << ed;
		ll q = 0, rt = -1;
		ff(poss, 0, n){
			if(c2[poss] > 0) continue;
			q++;
			rt = poss;
		}
		if(q > 1){ continue;}
		//cout << "OK " << rt+1 << ed;
		conexiones = vector<vl>(n);
		visited = vb(n, 0);
		for(auto &x : tod[i]){
			conexiones[arr[x].fi].pb(arr[x].se);
		}
		ok = true;
		sz = vl(n, 0);
		dfs(rt);
		ff(poss, 0, n){
			if(!ok) break;
			if(!visited[poss]){
				ok = false;
				break;
			}
		}
		if(!ok){ 
			//cout << "FAKE" << ed << ed;
			continue;}
		ll summ = 0;
		ff(i, 0, sz.size()){
			summ += sz[i];
		}
		/*if(i == 46){
			ff(i, 0, sz.size()){
				cout << sz[i] << ' ';
			}
			cout << ed;
		}*/
		//cout << "OKK " << summ << ed << ed;
		minn = min(minn, summ);
		
	}
	cout << minn;
}
