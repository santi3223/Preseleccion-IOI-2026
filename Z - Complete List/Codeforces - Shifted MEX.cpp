//18 de Enero 2026 10:50
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


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ll c = 1, maxx = 1;
		ff(i, 0, n){
			cin >> arr[i];
		}
		sort(all(arr));
		ff(i, 1, n){
			if(arr[i-1] == arr[i]) continue;
			if(arr[i-1] == arr[i]-1){
				//cout << "Y " << arr[i-1] << " " << arr[i] << ed;

				c++;
			}
			else{
				c = 1;
				//cout <<"          " <<  arr[i-1] << " " << arr[i] << ed;
			}
			maxx = max(maxx, c);
		}
		cout << maxx << ed;
	}
}
