//4 de Marzo 2026 20:23
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>

int main(){
	ll n;
	cin >> n;
	map<ll, ll> mp;
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		mp[a]++;
		mp[b+1]--;
	}
	vl count(n+1, 0);
	ll c = 0, prev = -1;
	for(auto &x : mp){
		if(prev != -1 && c != 0) count[c] += x.fi-prev;
		c += x.se;
		prev = x.fi;
	}
	ff(i, 1, n+1){
		cout << count[i] << " ";
	}
}
