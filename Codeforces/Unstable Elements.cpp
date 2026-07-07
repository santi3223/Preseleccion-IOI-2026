//6 de Julio 2026 11:54
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		vl cou(n+5, 0);
		ff(i, 0, n){
			ll a;
			cin >> a;
			cou[a]++;
		}
		vl freq;
		ff(i, 1, n+1){
			if(cou[i] != 0) freq.pb(cou[i]);
		}
		sort(all(freq));
		ll m = freq.size();
		vl suf(m+1, 0);
		for(ll i = m-1; i >= 0; i--){
			suf[i] = suf[i+1]+freq[i];
		}
		ll c = 0;
		ff(i, 0, m){
			if(i > 0 && freq[i] == freq[i-1]) continue;
			ll surv = m-i, v = freq[i], sum = suf[i];
			ll dif = k-sum;
			if(dif % surv == 0){
				ll x = dif/surv;
				if(x >= -v+1){
					c++;
				}
			}
		}
		cout << c << ed;
		
	}
}
