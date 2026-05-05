//5 de Mayo 2026 16:03
#include <bits/stdc++.h>
using namespace std;
#define ll int
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

ll LOG = 30;

vector<vl> successor;
vl conexiones;

ll ksucc(ll x, ll k){
	ff(i, 0, LOG){
		if(k & (1 << i)){
			x = successor[x][i];
		}
	}
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	conexiones = vl(n);
	successor = vector<vl>(n, vl(LOG));
	ff(i, 0, n){
		cin >> conexiones[i];
		conexiones[i]--;
		successor[i][0] = conexiones[i];
	}
	ff(i, 1, LOG){
		ff(cur, 0, n){
			successor[cur][i] = successor[successor[cur][i-1]][i-1];
		}
	}
	while(q--){
		ll a, k;
		cin >> a >> k;
		cout << ksucc(a-1, k)+1 << ed;
	}
}
