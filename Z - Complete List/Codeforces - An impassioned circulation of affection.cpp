//1 de Marzo 2026 22:06
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
#define vb vector<bool>

int main(){
	string str;
	ll n, q;
	cin >> n >> str >> q;
	vector<vl> ans(31, vl(n+5, 0));
	for(char c = 'a'; c <= 'z'; c++){
		ff(i, 0, n){
			ll count = 0;
			ff(j, i, n){
				if(str[j] != c) count++;
				ans[c-'a'][count] = max(ans[c-'a'][count], j-i+1);
			}
		}
		ff(i, 1, n+5) ans[c-'a'][i] = max(ans[c-'a'][i], ans[c-'a'][i-1]);
	}
	while(q--){
		ll x;
		char c;
		cin >> x >> c;
		cout << ans[c-'a'][x] << ed;
	}
}
