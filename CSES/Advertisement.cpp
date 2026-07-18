#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl arr;
	ff(i, 0, n){
		ll x;
		cin >> x;
		arr.pb(x);
	}
	arr.pb(-1);
	stack<ll> st;
	st.push(-1);
	ll maxx = 0;
	ff(i, 0, n+1){
		//cout << "I " << i << ed;
		while(st.top() != -1 && arr[st.top()] >= arr[i]){
			//cout << "C " << st.top() << ' ' << i << "    " << (st.top() != -1 ? arr[st.top()] : -10) << ' ' << arr[i] << ed;
			ll x = st.top();
			st.pop();
			maxx = max(maxx, (i-1-st.top())*arr[x]);
			//cout << i-1 << ' ' << st.top() << ' ' << (i-1-st.top()) << ' ' << (i-1-st.top())*arr[x] << ed;
		}
		//cout << st.top() << ' ' << i << "    " << (st.top() != -1 ? arr[st.top()] : -10) << ' ' << arr[i] << ed;
		//cout << ed << "====================" << ed;
		st.push(i);
	}
	cout << maxx;
}
//4 1 5 3 3 2 4 1
//-1     x
//-1 4     4
//-1 x 1     x
//-1 x 1 5     5
//-1 x 1 x 3     6
//-1 x 1 x x 3     9
//-1 x 1 x x x 2     x
//-1 x 1 x x x 2 4     4 10 7
//-1 x x x x x x x 1     8
//-1 x x x x x x x x -1
