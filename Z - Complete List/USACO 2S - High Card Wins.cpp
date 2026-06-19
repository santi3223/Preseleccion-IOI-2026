//18 de Junio 2026 18:57
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	
	ll n;
	cin >> n;
	vl arr(n);
	set<ll> tod;
	ff(i, 0, 2*n) tod.insert(i+1);
	ff(i, 0, n){
		cin >> arr[i];
		tod.erase(arr[i]);
	}
	ll c = 0;
	for(ll cur : arr){
		if(cur > *tod.rbegin()){
			tod.erase(tod.begin());
		}
		else{
			auto it = tod.lower_bound(cur);
			tod.erase(it);
			c++;
		}
	}
	cout << c;
	
	
	
}
