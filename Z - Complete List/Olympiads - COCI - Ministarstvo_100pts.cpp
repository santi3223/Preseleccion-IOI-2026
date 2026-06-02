//1 de Junio 2026 19:53
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
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ll n;
	cin >> n;
	vector<vl> adj(n, vl(n));
	vl conexiones(n, 0);
	ff(i, 0, n){
		ff(j, 0, n){
			cin >> adj[i][j];
			if(adj[i][j]) conexiones[i]++;
		}
	}
	ll maxx = 0;
	ff(i, 0, n) if(conexiones[i] > conexiones[maxx]) maxx = i;
	if(conexiones[maxx] == n-1){
		cout << -1;
		return 0;
	}
	cout << 3 << ed;
	ff(i, 0, n){
		if(i == maxx) continue;
		if(adj[maxx][i] == 0){
			ff(j, 0, n){
				if(adj[maxx][j] == 0)adj[i][j] *= 2;
			}
		}
		else{
			ff(j, 0, n){
				adj[i][j] *= 3;
			}
		}
	}
	ff(i, 0, n){
		ff(j, 0, n){
			cout << adj[i][j] << ' ';
		}
		cout << ed;
	}
}
