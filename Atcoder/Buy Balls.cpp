//25 de Enero 2026 21:10
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


int main(){
	ll n, m;
	cin >> n >> m;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	vl b(m);
	ff(i, 0, m){
		cin >> b[i];
	}
	sort(rall(arr));
	sort(rall(b));
	ll minn = 0;
	ll i = 0, j = 0;
	while(true){
		ll p = minn;
		while(minn + arr[i] > minn && i < n){
			minn += arr[i];
			i++;
		}
		while(i > j && j < m && minn+b[j] > minn){
			minn += b[j];
			j++;
		}
		while(minn+arr[i]+b[j] > minn && i < n && j < m){
			minn += arr[i]+b[j];
			i++;
			j++;
		}
		if(minn == p) break;
	}
	cout << minn;
	
		
}
