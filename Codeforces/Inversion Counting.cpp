//6 de Mayo 2026 14:16
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	ll par = 0;
	ff(i, 0, n){
		ff(j, 0, i){
			if(arr[i] < arr[j]) par ^= 1;
		}
	}
	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		ll dif = r-l+1;
		ll tot = dif*(dif-1)/2;
		if(tot % 2 != 0) par ^= 1;
		if(par == 0) cout << "even";
		else cout << "odd";
		cout << ed;
	}
}
