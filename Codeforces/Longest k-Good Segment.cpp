//31 de Marzo 2026 23:57
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
	ll n, m;
	cin >> n >> m;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	ll cur = 0;
	vl count(1e6+5, 0);
	ll l = 0, r = -1, p = 0;
	ff(i, 0, n){
		while(p < n){
			if(++count[arr[p]] == 1) cur++;
			if(cur > m){
				if(--count[arr[p]] == 0) cur--;
				break;
			}
			p++;
		}
		if(r-l < p-i){
			l = i;
			r = p;
		}
		if(--count[arr[i]] == 0) cur--;
	}
	cout << l+1 << ' ' << r;
	
}
