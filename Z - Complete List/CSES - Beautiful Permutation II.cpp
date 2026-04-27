//6 de Febrero 2026 21:36
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
#define ed "\n"
#define vb vector<bool>
 
int main(){
	ll n;
	cin >> n;
	if(n == 2 || n == 3){
		cout << "NO SOLUTION";
		return 0;
	}
	ll prev = -1;
	ll a = 1, b = 2, no = n;
	vl arr;
	while(n--){
		if(b > no){
			arr.pb(a);
			prev = a;
			a+= 2;
			continue;
		}
		if(a > no){
			arr.pb(b);
			prev = b;
			b+= 2;
			continue;
		}
		if(a< b){
			if(abs(prev-a) > 1){
				arr.pb(a);
				a += 2;
				prev = a-2;
			}
			else{
				arr.pb(b);
				b += 2;
				prev = b-2;
			}
		}
		else{
			if(abs(prev-b) > 1){
				arr.pb(b);
				b += 2;
				prev = b-2;
			}
			else{
				arr.pb(a);
				a += 2;
				prev = a-2;
			}
		}
	}
 
	ll x = (no-4)%5;
	if(x == 0){
		swap(arr[no-1], arr[no-3]);
		swap(arr[no-2], arr[no-4]);
	}
	if(x == 3){
		swap(arr[no-3], arr[no-2]);
	}
	if(x == 4){
		swap(arr[no-4], arr[no-3]);
		swap(arr[no-3], arr[no-2]);
	}
	ff(i, 0, no){
		cout << arr[i] << " ";
	}
	
}
