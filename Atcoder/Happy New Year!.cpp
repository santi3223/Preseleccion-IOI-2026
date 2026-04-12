//26 de Febrero 2026 22:25
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
#define ed "\n"

int main(){
	/*ll t;
	cin >> t;
	while(t--){*/
	ll x;
	cin >> x;
	ll l = 0;
	ff(i, 0, 100){
		if((1ll << i) > x){ l = i; break;}
	}
	ll cur = (1ll << (l-1));
	//cout << x << " ";
	x -= cur;
	l = 0;
	ll r = cur-1;
	//cout << ed << x << " " << l << " " << r << ed;
	cout << 2;
	while(l < r){
		ll mid = (l+r)/2;
		//cout << x << " " << mid << " " << l << " " << r<<"  ";
		if(x <= mid){
			cout << 0;
			r = mid;
		}
		else{
			cout << 2;
			l = mid+1;
			 
		}
		//cout << ed;
		
	}
	cout << ed;
//}
}
