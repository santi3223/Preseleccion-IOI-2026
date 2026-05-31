//29 de Mayo 2026 14:38
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

const long double PI = acos(-1.0);

/*ll calc(ll n){
	return n/(log(n));
}*/



int main(){
	
	vb vis(1e6+5, 1);
	ll N = 1e6+5;
	for(ll i = 2; i*i <= N; i++){
		if(!vis[i]) continue;
		for(ll j = i*i; j <= N; j += i){
			vis[j] = 0;
		}
	}
	
	vl sieve(N, 0);
	sieve[2] = 1;
	ff(i, 3, N){
		sieve[i] = sieve[i-1]+vis[i];
	}
	/*ff(i, 0, 20){
		cout << sieve[i] << ' ';
	}
	cout << ed;*/
	ll t;
	cin >> t;
	while(t--){
		ll i, j;
		cin >> i >> j;
		cout << sieve[j]-sieve[i-1] << ed;
	}
	
}
