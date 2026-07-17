//10 de Julio 2026 17:08
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
const ll MOD = 1e9+7;
 
int main(){
	string s;
	cin >> s;
	vl c(26, 0);
	ll n = s.size();
	ff(i, 0, n) c[s[i]-'A']++;
	ll last = -1;
	string ans(n, 'a');
	ff(i, 0, n){
		bool ok = false;
		ff(j, 0, 26){
			if(c[j] == 0 || last == j) continue;
			c[j]--;
			ll maxx = 0;
			ff(k, 0, 26) maxx = max(maxx, c[k]);
			if(maxx <= (n-i)/2){
				last = j;
				ans[i] = j+'A';
				ok = true;
				break;
			}
			c[j]++;
		}
		if(!ok){
			cout << -1;
			return 0;
		}
	}
	cout << ans;
}
