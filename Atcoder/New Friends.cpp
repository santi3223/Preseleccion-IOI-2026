//27 de Enero 2026 20:33
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>
ll MOD = 1e9;

int main(){
	ll n, m;
	cin >> n >> m;
	vector<vl> conexiones(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	vb visited(n, false);
	ll c = 0;
	ff(i, 0, n){
		if(!visited[i] && conexiones[i].size() > 0){
			visited[i] = true;
			queue<ll> q;
			q.push(i);
			ll con = 0, p = 0;
			while(!q.empty()){
				p++;
				ll a = q.front();
				q.pop();
				con += conexiones[a].size();
				for(auto &x : conexiones[a]){
					if(!visited[x]){
						visited[x] = true;
						q.push(x);
					}
				}
			}
			con /= 2;
			c += (p*(p-1)/2)-con;
		}
	}
	cout << c;
	
}
