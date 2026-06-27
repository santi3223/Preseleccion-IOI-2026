//26 de Junio 2026 22:40
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

string s;

ll solve(ll x, ll y){
	ll cc = 0;
	for(auto c : s){
		if(c-'0' == x){
			cc++;
			swap(x, y);
		}
	}
	if(x != y && cc % 2 != 0){
		cc--;
	}
	return cc;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		cin >> s;
		ll maxx = 0;
		ff(i, 0, 10) ff(j, 0, 10) maxx = max(maxx, solve(i, j));
		cout << s.size()-maxx << ed;
	}
}
