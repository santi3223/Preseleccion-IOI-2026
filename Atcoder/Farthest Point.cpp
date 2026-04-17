//23 de Enero 2026 10:56
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

int main(){
	ll n;
	cin >> n;
	vector<pll> arr(n);
	ff(i, 0, n){
		cin >> arr[i].fi >> arr[i].se;
	}
	ff(i, 0, n){
		ll maxx = 0, id = 0;
		ll x1 = arr[i].fi, y1 = arr[i].se;
		ff(j, 0, n){
			if(i == j) continue;
			ll x2 = arr[j].fi, y2 = arr[j].se;
			ll t = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
			if(t > maxx){
				id = j;
				maxx = t;
			}
		}
		cout << id+1 << ed;
	}
	
	
}
