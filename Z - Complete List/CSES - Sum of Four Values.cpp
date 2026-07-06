//4 de Julio 2026 22:51
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	map<ll, pll> mp;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	ff(i, 0, n){
		ff(j, i+1, n){
			ll x = arr[i]+arr[j];
			if(mp.count(k-x)){
				auto [a, b] = mp[k-x];
				cout << a+1 << ' ' << b+1 << ' ' << i+1 << ' ' << j+1;
				return 0;
			}
		}
		ff(k, 0, i){
			mp[arr[i]+arr[k]] = {k, i};
		}
	}
	cout << "IMPOSSIBLE";
}
