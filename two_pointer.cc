/*Given two sorted arrays  𝐴
  and  𝐵,
  each having length  𝑁
  and  𝑀
  respectively. Form a new sorted merged array having values of both the arrays in sorted format.
*/

#define MAX 100005 
 
lli C[2*MAX]; 
 
void merge(lli A[], lli B[]) 
{ 
    int l1 = 0, l2 = 0, cnt = 0; 
    while ( l1 < n || l2 < m ) { 
       if ( l1 < n && l2 < m ) { 
          if ( A[l1] < B[l2] ) { 
              C[cnt++] = A[l1];  
              l1++; 
          } 
          else if ( A[l1] > B[l2] ) { 
              C[cnt++] = B[l2]; 
              l2++; 
          } 
       } 
       else if ( l1 < n ) { 
          C[cnt++] = A[l1]; 
          l1++; 
       } 
       else if ( l2 < m ) { 
          C[cnt++] = B[l2]; 
          l2++;  
       } 
    } 
    return; 
} 

//

#include <bits/stdc++.h> 
#define lli long long 
#define MAX 1000005 
 
using namespace std; 
 
lli A[MAX]; 
 
int main() 
{ 
    int n; 
	lli sum = 0;	  
    cin >> n; 
    
    for ( int i = 0; i < n; i++ ) cin >> A[i]; 
     
    int l = 0, r = 0; 
	lli ans = 0; 
 
    while ( l < n ) { 
       while ( r < n && sum + A[r] <= M ) { 
           sum += A[r]; 
           r++; 
       } 
       ans = max(ans, sum); 
       sum -= A[l]; 
       l++; 
    } 
 
    cout << ans << endl; 
    return 0; 
} 

//

int l = 0, r = 0, ans = INF; 
map <int , int >  cnt; 
 
while ( l < n ) { 
    while ( r < n && s.size() < K ) { 
       s.insert(A[r]); 
       cnt[A[r]]++; 
       r++; 
    } 
    if (s.size() >=K) { 
		ans = min(ans, r-l); 
	} 
    if ( cnt[A[l]] == 1 ) s.erase(A[l]);  
    cnt[A[l]]--;  
    l++; 
} 
if ( ans == INF ) ans = -1; 
  
cout << ans << endl; 

//