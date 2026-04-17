//24 de Enero 2026 16:37
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
	vl arr;
	ll x;
	while(cin >> x){
		arr.pb(x);
		if(x == 0) break;
	}
	reverse(all(arr));
	ff(i, 0, arr.size()){
		cout << arr[i] << ed;
	}
	
	
	
}
