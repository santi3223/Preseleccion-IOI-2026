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
#define vb vector<bool>
#define ed endl
#define vs vector<string>

vl par;

ll find(ll x){
	return par[x] == x ? x : par[x] = find(par[x]);
}

int main(){
	ll n, a, b;
	cin >> n >> a >> b;
	vl arr(n);
	map<ll, ll> mp;
	par = vl(n);
	vl st(n, 0), state(n);
	ff(i, 0, n){
		cin >> arr[i];
		mp[arr[i]] = i;
		par[i] = i;
	}
	ff(i, 0, n){
		if(mp.count(a-arr[i]) != 0){
			par[find(mp[a-arr[i]])] = find(i);
			st[i] |= 1;
		}
		if(mp.count(b-arr[i]) != 0){
			par[find(mp[b-arr[i]])] = find(i);
			st[i] |= 2;
		}
	}
	ff(i, 0, n) state[i] = 3;
	ff(i, 0, n) state[find(i)] &= st[i];
	ff(i, 0, n){
		if(state[i] == 0){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << ed;
	ff(i, 0, n){
		ll q = state[find(i)];
		cout << (q%2 == 0) << ' ';
	}
	
}
