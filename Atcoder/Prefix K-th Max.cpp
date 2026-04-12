//26 de Febrero 2026 22:48
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
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	set<ll> st;
	ff(i, 0, k){
		st.insert(arr[i]);
	}
	cout << *st.begin() << ed;
	ff(i, k, n){
		st.insert(arr[i]);
		while(st.size() > k){
			st.erase(st.begin());
		}
		cout << *st.begin() << ed;
	}
}
