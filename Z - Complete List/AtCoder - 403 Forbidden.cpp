//26 de Enero 2026 09:28
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
	ll n, m, q;
	cin >> n >> m >> q;
	vector<bool> todos(n, false);
	map<pair<ll, ll>, ll> mp;
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll x, y;
			cin >> x >> y;
			x--;
			y--;
			mp[{x, y}]++;
		}
		if(o == 2){
			ll x;
			cin >> x;
			x--;
			todos[x] = true;
		} 
		if(o == 3){
			ll x, y;
			cin >> x >> y;
			x--;
			y--;
			if(mp[{x, y}] || todos[x]) cout << "Yes";
			else cout << "No";
			cout << ed;
		}
	}
}
