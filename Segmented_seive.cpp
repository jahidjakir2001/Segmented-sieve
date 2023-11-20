#include<bits/stdc++.h>
using namespace std;
const int mx=1e7;
vector<int>v;
vector<int>v1(mx,0);
void sieve()
{
    for(int i=2;1LL*i*i<=mx;i++){
        if(v1[i]==0){
            for(int j=i*i;j<=mx;j+=i){
                 v1[j]=1;
            }
        }
    }
    for(int i=2;i<=mx;i++){
        if(v1[i]==0){
            v.push_back(i);
        }
    }
}
void segmented_sieve(int l,int r)
{
    if(l==1) l++;
    int x=r-l+1;
    int ar[x]={0};
    for(auto u:v){
            //cout<<u<< " ";
        if(u*u<=r){
            int y=(l/u)*u;
            if(y<l) y+=u;
            //cout<<"test";
            for(int i=y;i<=r;i+=u){
                if(u!=i) ar[i-l]=1;
            }
        }
        else{
            //cout<<u;
            break;
        }
    }
    cout<<"Finding prime number using segmented sieve : ";
    for(int i=0;i<x;i++){
        if(ar[i]==0){
            cout<<l+i<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        segmented_sieve(l,r);
    }
}
