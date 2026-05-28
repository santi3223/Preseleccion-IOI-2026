//27 de Mayo 2026 16:00
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
const ll MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll sum = n*(n+1)/2;
		for(ll i = 0; (1 << i) <= n; i++){
			sum -= 2*(1 << i);
		}
		cout << sum << ed;
	}
}
