//7 de Junio 2026 16:35
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		string a, b;
		cin >> a >> b;
		ll c1 = 0, c2 = 0, c3 = 0;
		ff(i, 0, n){
			ll x = a[i]-'0';
			ll y = b[i]-'0';
			c1 += x;
			c2 += y;
			c3 += x^y;
		}
		c1 = c1*(n-c1);
		c2 = c2*(n-c2);
		c3 = c3*(n-c3);	
		if(k % 2 != 0){
			ll pot = (1LL << k)+1;
			pot /= 3;
			ll x = c1*pot+c2*pot+c3*pot;
			cout << x << ed;
		}
		else{
			ll pot = (1LL << (k))+2;
			pot /= 3;
			//cout << "POT " << pot << ed;
			ll x = c1*pot+c2*pot+c3*(pot-1);
			cout << x << ed;
		}
		
		
	}
}
