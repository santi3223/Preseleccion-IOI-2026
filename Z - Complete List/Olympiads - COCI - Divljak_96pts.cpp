//29 de Marzo 2026 21:37
//This problems has a max of 176 pts
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

int main(){
	ll n;
	cin >> n;
	vs arr(n);
	vl ans(n, 0);
	ff(i, 0, n) cin >> arr[i];
	ll q;cin>>q;
	while(q--){
		ll t;
		cin >> t;
		if(t == 1){
			string s;
			cin >> s;
			ff(i, 0, n){
				if(s.find(arr[i]) != string::npos) ans[i]++;
			}
		}
		else{
			ll id;
			cin >> id;
			cout << ans[id-1] << ed;
		}
	}
	
}
