//deloitte question (always type cast sum to float before calculating average!!!!)

#include <bits/stdc++.h>
using namespace std;

void solve(int A1[], int m, int A2[], int n){
    int i=0,count=0;
    int max=m+n;
    
    cout<<"[";
    while(count<max-1){
        if(i<m){
            cout<<A1[i]<<", ";
            count++;
            if(count>=max-1)
            break;
        }
        if(i<n){
            cout<<A2[i]<<", ";
            count++;
        }
        i++;
    }
    
    if(m>n){
       cout<<A1[m-1]<<"]";
    }
    else{
        cout<<A2[n-1]<<"]";
    }
    
    return;
}

int main()
{
    int A1[]={1,2,3,4,5};
    int m= sizeof(A1)/sizeof(A1[0]);
    int A2[]={6,7,8,9,10};
    int n= sizeof(A2)/sizeof(A2[0]);
    
    solve(A1,m,A2,n);


    return 0;
}

