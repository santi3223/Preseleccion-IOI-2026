//3 de Julio 2026 17:20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		if(n < 10){
			cout << n << ed;
			continue;
		}
		ll dig = 1, sub = 9, l = 1;
		while(n > sub*dig){
			n -= sub*dig;
			dig++;
			sub *= 10;
			l *= 10;
		}
		ll st = l-1;
		ll q = n%dig;
		//cout << "A " << dig << ' ' << l << ' ' << n  << ' ' << st << ed;
		n = (n+dig-1)/dig;
		ll num = st+n;
		//cout << n << ' ' << q << ' ' << num << ed;
		if(q == 0){
			cout << num % 10 << ed;
			continue;
		}
		while(true){
			if(q == dig){
				cout << num%10 << ed;
				break;
			}
			q++;
			num /= 10;
		}
	}
}
