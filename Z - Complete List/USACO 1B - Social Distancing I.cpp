//12 de Febrero 2026 20:53
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
	freopen("socdist1.in", "r", stdin);
	freopen("socdist1.out", "w", stdout);
	ll n;
	cin >> n;
	vl a, b;
	string arr;
	cin >> arr;
	ll c = 0, minn = LLONG_MAX;
	ff(i, 0, n){
		if(i > 0 && arr[i] == '1' && arr[i-1] == '1') continue;
		if(arr[i] == '0'){
			c++;
		}
		else{
			//cout << c << ed;
			if(c == 0) continue;
			//cout << "I " << i << ed;
			if(c == i){
				//cout << "ZEROST" << ed;
				a.pb(c);
				b.pb(c/2);
				//cout << c << " " << c << " ";
			}
			else{
				a.pb((c+1)/2);
				minn = min(minn, c+1);
				//cout << c << " " << (c+1)/2 << " ";
			}
			if(c != i && c != 1){
				c--;
				b.pb((c+2)/3);
				//cout << (c+2)/3;
				c++;
			}
			//cout << ed;
			//cout << "MINN  " << minn << ed;
			c = 0;
		}
	}
	//cout << c << " fin" << ed;
	if(c != 0){
		//cout << "I LAST" << ed;
		a.pb(c);
		//cout << c << " " << c << " ";
		if(c != 1){
			b.pb(c/2);
			if(c == n){
				b.pb(n-1);
			}
			//cout << c/2;
		}
		//cout << ed;
		
	}
	//cout << "MINN " << minn << ed; 
	/*
	ff(i, 0, a.size()){
		cout << a[i] << " ";
	}
	cout << ed;
	ff(i, 0, b.size()){
		cout << b[i] << " ";
	}
	cout << ed << ed;
	*/
	sort(rall(a));
	sort(rall(b));
	if(a.size() == 1){
		cout << min(minn, b[0]);
	}
	else if(b.size() == 0){
		cout << min(minn, a[1]);
	}
	else{
		cout <<  min(minn, max(a[1], b[0]));
	}
	
}
