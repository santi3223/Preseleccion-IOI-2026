//18 de Abril 2026 8:19
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

int main(){
	ll n, m;
	cin >> n >> m;
	vl arr(n);
	map<ll, ll> mp;
	ff(i, 0, n){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	bool v1 = true, v2 = false;
	ll q = 0;
	ff(i, 1, m+1){
		if(mp[i] == 2)v1 = false;
		if(mp[i] != 0) q++;
	}
	if(q == m) v2 = true;
	if(v1) cout << "Yes";
	else cout << "No";
	cout << ed;
	if(v2) cout << "Yes";
	else cout << "No";
	cout << ed;
}

