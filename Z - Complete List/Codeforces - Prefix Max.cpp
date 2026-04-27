//18 de Enero 2026 10:40
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


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ll maxx = 0;
		ff(i, 0, n){
			cin >> arr[i];
			maxx = max(maxx, arr[i]);
		}
		cout << maxx*n << ed;
	}
}
