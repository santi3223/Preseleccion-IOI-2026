//25 de Enero 2026 21:23
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


int main(){
	ll n;
	cin >> n;
	vl arr(n);
	map<ll, ll> a, b;
	ll x = 0, y = 0;
	ff(i, 0, n){
		cin >> arr[i];
		b[arr[i]]++;
		if(b[arr[i]] == 1) y++;
	}
	ll maxx = y;
	ff(i, 0, n){
		ll p = arr[i];
		b[p]--;
		if(b[p] == 0) y--;
		a[p]++;
		if(a[p] == 1) x++;
		maxx = max(maxx, x+y);
	}
	cout << maxx;
	
		
}
