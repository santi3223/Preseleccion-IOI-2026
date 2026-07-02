//1 de Julio 2026 23:59
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

vector<vl> conexiones;
vl fir, sec;
bool ok = true;
vl color;

void dfs(ll cur){
	if(!ok) return;
	if(color[cur] == 1) fir.pb(cur);
	else sec.pb(cur);
	for(auto x : conexiones[cur]){
		if(color[x] == color[cur]){
			ok = false;
			return;
		}
		if(color[x] == -1){
			color[x] = (color[cur]+1)%2;
			dfs(x);
		}
	}
}


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		conexiones = vector<vl>(n);
		ff(i, 0, m){
			ll a, b;
			cin >> a >> b;
			conexiones[--a].pb(--b);
			conexiones[b].pb(a);
		}
		color = vl(n, -1);
		ok = true;
		color[0] = 0;
		fir.clear();
		sec.clear();
		dfs(0);
		if(!ok){
			cout << "Alice" << endl;
			ff(i, 0, n){
				cout << "1 2" << endl;
				ll a, b;
				cin >> a >> b;
			}
		}
		else{
			cout << "Bob" << endl;
			ff(i, 0, n){
				ll a, b;
				cin >> a >> b;
				bool has1 = (a == 1 || b == 1);
				bool has2 = (a == 2 || b == 2);
				if(has1 && fir.size()){
					cout << fir.back()+1 << ' ' << 1 << endl;
					fir.pop_back();
				}
				else if(has2 && sec.size()){
					cout << sec.back()+1 << ' ' << 2 << endl;
					sec.pop_back();
				}
				else if(fir.size()){
					cout << fir.back()+1 << ' ' << 3 << endl;
					fir.pop_back();
				}
				else{
					cout << sec.back()+1 << ' ' << 3 << endl;
					sec.pop_back();
				}
			}
		}
	}
}
