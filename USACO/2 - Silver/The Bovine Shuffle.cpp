//28 de Abril 2026 16:29
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
const ll MOD = 1e9+7;

int main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	
	ll n;
	cin >> n;
	vl c(n, 0);
	vl arr(n, 0);
	ff(i, 0, n){
		ll a;
		cin >> a;
		c[a-1]++;
		arr[i] = a-1;
	}
	ll ans = n;
	queue<ll> cows;
	ff(i, 0, n){
		if(c[i] == 0){
			ans--;
			cows.push(i);
		}
	}
	while(!cows.empty()){
		ll cur = cows.front();
		cows.pop();
		if(--c[arr[cur]] == 0){
			cows.push(arr[cur]);
			ans--;
		}
	}
	cout << ans;
}
