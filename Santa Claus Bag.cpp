#include<iostream>
using namespace std;
int knapsack(int n,int capacity,int p[],int w[]);
int item,maxweight;
int main()
{
    int w[100],p[100];
    int t,n,maxi;
    cin>>t;
    while(t--)
    {
        item=maxi=maxweight=0;
        cin>>n;
        int capacity=50;
        for(int i=1; i<=n; i++)
            cin>>p[i]>>w[i];
        maxi=knapsack(n,capacity,p,w);
        cout<<maxi<<" brinquedos"<<endl;
        cout<<"Peso: "<<maxweight<<" kg"<<endl;
        cout<<"sobra(m) "<<n-item<<" pacote(s)"<<endl<<endl;
    }
    return 0;
}
int knapsack(int n,int capacity,int p[],int w[])
{
    int dp[100][100],i,j;
    for(i=0; i<=n; i++)
        dp[i][0]=0;
    for(i=0;  i<=capacity; i++)
        dp[0][i]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=capacity; j++)
        {
            if(w[i]<=j)
            {
                if(p[i]+dp[i-1][j-w[i]] > dp[i-1][j])
                    dp[i][j]=p[i]+dp[i-1][j-w[i]];
                else
                    dp[i][j]=dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    int mw=0;
    mw=capacity;
    int maxprice=dp[n][capacity];
    for(i=n; i>0 && maxprice>0; i--)
    {
        if(maxprice==dp[i-1][mw])
            continue;
        else
        {
            item++;
            maxprice = maxprice - p[i];
            maxweight+=w[i];
            mw = mw - w[i];
        }
    }
    return dp[n][capacity];
}
