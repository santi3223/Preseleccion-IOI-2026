//6 de Marzo 2026 20:03
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()

int main(){
	ll n, q;
	cin >> n >> q;
	vl pref(n, 0);
	ff(i, 0, q){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		pref[a]++;
		if(b+1 < n)	pref[b+1]--;
	}
	ff(i, 1, n){
		pref[i] += pref[i-1];
	}
	/*ff(i, 0, n){
		cout << pref[i] << " ";
	}
	cout << ed;*/
	sort(all(pref));
	if(n % 2 != 0) n++;
	//cout << n/2 << " ";
	cout << pref[n/2-1];
	
}
