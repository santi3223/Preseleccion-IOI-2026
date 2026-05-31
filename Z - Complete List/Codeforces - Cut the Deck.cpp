//29 de Mayo 2026 15:24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

const long double PI = acos(-1.0);


int main(){
	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll n = s.size();
		ll id = 0, c = 0;
		ff(i, 0, n){
			if(s[i] == 'B') c++;
			else c--;
			if(c < 0) id = i+1, c = 0;
		}
		bool ok = true;
		ff(i, 0, id){
			if(s[i] == 'B') c++;
			else c--;
			if(c < 0){
				ok = false;
				break;
			}
		}
		if(ok) cout << id << ed;
		else cout << -1 << ed;
	}
	
}
