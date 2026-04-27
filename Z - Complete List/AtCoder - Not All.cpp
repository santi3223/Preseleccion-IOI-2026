//26 de Enero 2026 12:46
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>
ll MOD = 1e9;

int main(){
	ll n, m;
	cin >> n >> m;
	vl arr(n);
	map<ll, ll> mp;
	ff(i, 0, n){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	ll c = 0;
	ff(i, 1, m+1){
		if(mp[i] == 0){
			cout << c;
			return 0;
		}
	}
	for(ll i = n-1; i >= 0; i--){
		c++;
		mp[arr[i]]--;
		if(mp[arr[i]] == 0){
			cout << c;
			return 0;
		}
	}
	cout << c;
	
}
