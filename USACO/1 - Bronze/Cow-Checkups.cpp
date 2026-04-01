//5 de febrero 2026 16:12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>

int main(){
	ll n;
	cin >> n;
	vl a(n), b(n), ans(n+1, 0);
	ff(i, 0, n){
		cin >> a[i];
	}
	ll x = 0;
	ff(i, 0, n){
		cin >> b[i];
		if(b[i] == a[i])x++;
	}
	ans[x] += n;
	ff(i, 1, n){
		ll l = i-1, r = i, c = x;
		while(0 <= l && r < n){
			if(a[l] == b[l]) c--;
			if(a[r] == b[r]) c--;
			if(a[l] == b[r]) c++;
			if(a[r] == b[l]) c++;
			l--;
			r++;
			ans[c]++;
		}
		l = i-1;
		r = i+1;
		c = x;
		while(0 <= l && r < n){
			if(a[l] == b[l]) c--;
			if(a[r] == b[r]) c--;
			if(a[l] == b[r]) c++;
			if(a[r] == b[l]) c++;
			l--;
			r++;
			ans[c]++;
		}
	}
	ff(i, 0, n+1){
		cout << ans[i] << ed;
	}
	
}
