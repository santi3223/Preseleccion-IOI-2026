//26 de Enero 2026 08:41
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>
ll MOD = 1e9;

int main(){
	deque<ll> q;
	ll n;
	cin>> n;
	while(n--){
		ll o;
		cin >> o;
		if(o == 1){
			ll x;
			cin >> x;
			q.push_back(x);
		}
		else{
			ll a = q.front();
			cout << a << ed;
			q.pop_front();
		}
	}
}
