//31 de Enero 2026 08:24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vb vector<bool>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define vl vector<ll>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
constexpr ll MOD = 1e9+7;
 
int main(){
	ll n, t;
	cin >> n >> t;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	if(n == 0){
		cout << t;
		return 0;
	}
	ll c = arr[0];
	ll last = arr[0];
	ff(i, 1, n){
		ll x = arr[i];
		if(last+100 < x){
			c += x-(last+100);
			last = x;
		}
	}
	if(last+100 < t){
		c += t-(last+100);
	}
	cout << c;
}
