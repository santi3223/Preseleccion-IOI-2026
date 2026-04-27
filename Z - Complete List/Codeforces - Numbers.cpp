//1 de Abril 2026 16:47
//april fools contest upsolve
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a, b, c;
		cin >> a >> b >> c;
		vl arr = {a, b, c};
		sort(all(arr));
		cout << (a^b^c)-arr[1] << ed;
	}
	
}
