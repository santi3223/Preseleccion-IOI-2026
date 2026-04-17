//25 de Enero 2026 12:53
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

string t;
vector<string> arr;

bool check(ll id, ll i, ll j){
	if(arr[i][j] == '#') return false;
	if(id == t.size()) return true;
	if(t[id] == 'U'){
		return check(id+1, i-1, j);
	}
	else if(t[id] == 'D'){
		return check(id+1, i+1, j);
	}
	else if(t[id] == 'L'){
		return check(id+1, i, j-1);
	}
	else{
		return check(id+1, i, j+1);
	}
}


int main(){
	ll h, w, n;
	cin >> h >> w >> n;
	cin >> t;
	arr = vector<string>(h);
	ff(i, 0, h){
		cin >> arr[i];
	}
	ll c = 0;
	ff(i, 0, h){
		ff(j, 0, w){
			c += check(0, i, j);
		}
	}
	cout << c;
	
}
