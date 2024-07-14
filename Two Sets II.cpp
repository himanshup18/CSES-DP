// Problem: Two Sets II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1093
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
int s;
vector<int> a;
int f(int ind,int sum,vector<vi>&dp){
	if(ind<0){
		return 0;
	}
	if(ind==0){
		if(sum+a[ind]==s){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(dp[ind][sum]!=-1){
		return dp[ind][sum];
	}
	
	int take=f(ind-1,sum+a[ind],dp)%M;
	int nottake=f(ind-1,sum,dp)%M;
	return dp[ind][sum]=(take%M+nottake%M)%M;
}
void Himanshu_Patel(){
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	s=n*(n+1)/2;
    if(s%2==1){
    	cout<<0<<endl;
    	return ;
    }
    s/=2;
    int target=n*(n+1)/2;
    target/=2;
    // vector<vector<int>> dp(n,vector<int>(k,-1));
    // cout<<f(n-1,0,dp)<<endl;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	(dp[i][j] += dp[i-1][left]) %= M;
      }
    }
  }
  cout << dp[n-1][target] << endl;
    
}
 
int32_t main(){
	int t=1;
	//cin>>t;
	while(t--){
		Himanshu_Patel();
	}
	return 0;
}
 