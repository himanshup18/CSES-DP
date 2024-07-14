// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long 
#define pb push_back
#define umap unordered_map
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vpii vector<pii>
#define mp make_pair
#define ff first
#define ss second
#define loop(i,x,y) for(int i=x; i<y; i++)
#define lloop(i,x,y) for(int i=x; i>=y; i--)
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define setbits(x) __builtin_popcountll(x)
#define lzeroes(x)  __builtin_clzll(x)
#define tzeroes(x)  __builtin_ctzll(x)
#define yn(f) f?cout<<"YES\n":cout<<"NO\n"
#define syn(f) f?cout<<"Yes\n":cout<<"No\n"
 
int M=1000000007;
//int M=998244353;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; //sorted set with extra functions
// initialize-> pbds name
// can change int to any other datatype, can change less to greater for descending order 
// find_by_order ->gives iterator of the element at given index, order_of_key ->gives no. of elements less than given value
 
int bpow(int x,int n){  //binary exponentiation only for integers
  if(n==0){
     return 1;
  }
  return x*bpow(x,n-1);
}
 
int bpowm(int x,int n,int m){   //binary exponentiation with mod m
  if(n==0){
    return  1;
  }
   if(n%2==0)
  {
    return bpowm(((x%m)*(x%m))%m,n/2,m);
  }
  return ((x%m)*bpowm(((x%m)*(x%m))%m,n/2,m))%m;
}
 
/* 
 
sieve code -->
 
vector<int> isprime(1e6+1,1);
void sieve(int n){isprime[1]=0;for(int i=2;i*i<1000001;i++)
if(isprime[i]!=0)for(int j=i*i;j<1000001;j+=i)isprime[j]=0;}
 
*/
 
// n & (1ll << i) -> ith bit is on or off
// n |= (1LL<<i) -> ith bit on
//  n & ( n ^ ( 1LL << i ) ) -> turn off
 
//priority_queue <int, vector<int>, greater<int>> pq;  --> min heap that means
//smallest element at the top
 
//pi=3.14159265358979323846264338327950288419716939937510582097494   upto 60 decimal places
 
int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
 
int lcm(int a, int b){
    int ans=(a/gcd(a,b))*b;
    return ans;
}
 
bool cmp(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}
bool powerof2(int n) {
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
 
bool prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return 0;
    }   
    return 1;
} 
 
/*-------------------------------------------------------------------------------------------------------------------------------------*/
int f(int ind,int x,vi &a,vector<vector<int>> &dp){
	if(ind==0){
		if(x%a[0]==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[ind][x]!=-1){
		return dp[ind][x];
	}
	int nottake=f(ind-1,x,a,dp)%M;
	int take=0;
	if(a[ind]<=x){
		take =f(ind,x-a[ind],a,dp)%M;
	}
	return dp[ind][x]=(take+nottake)%M;
}
void Himanshu_Patel(){
	int n,x;
	cin>>n>>x;
	vi a(n);
	loop(i,0,n){
		cin>>a[i];
	}
	vector<vector<int>> dp(n,vector<int>(x+1,-1));
	cout<<f(n-1,x,a,dp);
	
}
 
int32_t main(){
	  int mod = 1e9+7;
	  int n, target;
	  cin >> n >> target;
	  vector<int> c(n);
	  for (int&v : c) cin >> v;
	
	  vector<int> dp(target+1,0);
	  dp[0] = 1;
	  for (int i = 1; i <= target; i++) {
	    for (int j = 0; j < n; j++) {
	      if (i-c[j] >= 0) {
		(dp[i] += dp[i-c[j]]) %= mod;
	      }
	    }
	  }
	  cout << dp[target] << endl;
}
 