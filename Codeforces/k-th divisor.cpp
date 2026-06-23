//22 de Junio 2026 23:19
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vl small, big;
	for(ll i = 1; i*i <= n; i++){
		if(n % i == 0){
			small.pb(i);
			if(i != n/i) big.pb(n/i);
		}
	}
	reverse(all(big));
	for(auto x : big) small.pb(x);
	if(small.size() < k) cout << -1;
	else cout << small[k-1];
	
}
