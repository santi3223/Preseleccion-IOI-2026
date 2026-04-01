//17 de Febrero 2026 23:29
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
		long double n, d, h;
		cin >> n >> d >> h;
		vl arr(n);
		long double c = 0;
		ff(i, 0, n){
			cin >> arr[i];
			if(i == 0){
				c += (long double)(d*h)/2;
			}
			else{
				if(arr[i-1]+h <= arr[i]){
					c += (long double)(d*h)/2;
				}
				else{
					long double dist = arr[i]-arr[i-1];
					long double uppr = (long double)(d/h);
					uppr *= (long double)(h-dist)*1.0;
					c += (long double)((long double)((d+uppr)/2))*dist;
				}
			}
			
		}
		cout << fixed << setprecision(7) << c << ed;
	}
	
}
