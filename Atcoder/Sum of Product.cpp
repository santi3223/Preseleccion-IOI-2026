//26 de Enero 2026 13:06
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
	ll n;
	cin >> n;
	vl arr(1e4+1, 0);
	ff(i, 0, n){
		ll x;
		cin >> x;
		arr[x]++;
	}
	ll c = 0;
	ff(i, 1, 1e4+1){
		if(arr[i] == 0) continue;
		c += i*i * (arr[i]-1)*arr[i]/2;
		ff(j, i+1, 1e4+1){
			/*if(arr[j] != 0){
				cout << i << " " << j << ed;
				cout << arr[j] << " " <<arr[i] << ed;
				cout << arr[j]*arr[i]*i*j << ed;
			}*/
			c += arr[j]*arr[i]*(i*j);
		}
	}
	cout << c;
	
}
