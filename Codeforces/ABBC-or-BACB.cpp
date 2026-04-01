//23 de Febrero 2026
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"

int main(){
	ll t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		vl arr;
		ll c = 0;
		ff(i, 0, str.size()){
			if(str[i] == 'A') c++;
			else{
				arr.pb(c);
				c = 0;
			}
		}
		arr.pb(c);
		sort(all(arr));
		c = 0;
		ff(i, 1, arr.size()){
			c += arr[i];
		}
		cout << c << ed;
	}
}
//test
