//30 de Junio 2026 22:35
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll m = 2*n;
		vl arr(m);
		ff(i, 0, m) cin >> arr[i];
		sort(all(arr));
		bool ok = 1;
		ff(i, 0, n){
			if((arr[2*i] != arr[2*i+1]) || (arr[2*i] & 1) || (arr[2*i+1] & 1)){
				ok = false;
				break;
			}
			if(i != 0 && arr[2*i-1] == arr[2*i]) ok = false;
		}
		//ff(i, 0, m) cout << arr[i] << ' ';
		//cout << ed;
		if(!ok){
			cout << "NO" << ed;
			continue;
		}
		
		vl x;
		ff(i, 0, n) x.pb(arr[2*i]);
		reverse(all(x));
		ll sum = 0, cur = 0;
		ff(i, 0, n){
			cur = x[i]-2*sum;
			if(cur <= 0 || cur % (2*(n-i)) != 0){
				ok = false;
				break;
			}
			sum += cur/(2*(n-i));
		}
		if(!ok){
			cout << "NO" << ed;
			continue;
		}
		cout << "YES" << ed;
		
	}
	
}
