//6 de Julio 2026 12:23
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
		string sa, sb;
		cin >> sa >> sb;
		ll n = sa.size(), m = sb.size();
		vl a(n, 0), b(m, 0);	
		ff(i, 0, n){
			ll cur = sa[i]-'0';
			a[i] = cur;
			if(i != 0 ) a[i] += a[i-1];
			a[i] %= 10;
		}
		ff(i, 0, m){
			ll cur = sb[i]-'0';
			b[i] = cur;
			if(i != 0) b[i] += b[i-1];
			b[i] %= 10;
		}
		
		/*ff(i, 0, n) cout << a[i] << ' ';
		cout << ed;
		ff(i, 0, m) cout << b[i] << ' ';
		cout << ed << ed;*/
		if(a[n-1] != b[m-1]){
			cout << -1 << ed;
			continue;
		}
		
		vl dp(m+1, 0);
		ff(i, 1, n+1){
			ll prev = 0;
			ff(j, 1, m+1){
				ll temp = dp[j];
				if(a[i-1] == b[j-1]) dp[j] = prev + 1;
				else dp[j] = max(dp[j], dp[j-1]);
				prev = temp;
			}
		}

		cout << dp[m] << ed;
		
	}
}
