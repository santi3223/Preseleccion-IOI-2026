//27 de Febrero 2026 9:53
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
#define ed "\n"

int main(){
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	vl lef = arr, ri = arr;
	ff(i, 0, n-1){
		ll x = abs(lef[i]-lef[i+1]);
		if(x > k){
			if(lef[i] > lef[i+1]){
				lef[i+1] += x-k;
			}
			else{
				lef[i] += x-k;
			}
		}
	}
	for(ll i = n-1; i > 0; i--){
		ll x = abs(ri[i]-ri[i-1]);
		if(x > k){
			if(ri[i] > ri[i-1]){
				ri[i-1] += x-k;
			}
			else{
				ri[i] += x-k;
			}
		}
	}
	/*ff(i, 0, n){
		cout << lef[i] << " ";
	}
	cout << ed;
	ff(i, 0, n){
		cout << ri[i] << " ";
	}
	cout << ed;*/
	ff(i, 0, n){
		cout << max(lef[i], ri[i]) << " ";
	}
}
