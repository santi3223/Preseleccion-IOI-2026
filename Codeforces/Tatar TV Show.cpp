//12 de Junio 2026 10:58
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		vl div(k);
		string arr;
		cin >> arr;
		ff(i, 0, n){
			div[i%k] += arr[i]-'0';
			div[i%k] %= 2;
		}
		ll c = 0;
		ff(i, 0, div.size()){
			c += div[i];
		}
		if(c == 0) cout << "YES";
		else cout << "NO";
		cout << ed;
	}
}
