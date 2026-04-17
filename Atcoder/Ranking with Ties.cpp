//25 de Enero 2026 21:57
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
	ll n;
	cin >> n;
	vector<pll> arr(n);
	ff(i, 0, n){
		ll x;
		cin>> x;
		arr[i] = {x, i};
	}
	sort(rall(arr));
	vl rank(n);
	ll r = 1, ac = 0;;
	ff(i, 0, n){
		if(i != 0 && arr[i].fi == arr[i-1].fi){
			ac++;
		}
		else{
			if(i > 0){
				r += ac+1;
				ac = 0;
			}
		}
		rank[arr[i].se] = r;
	}
	ff(i, 0, n){
		cout << rank[i] << ed;
	}
	
		
}
