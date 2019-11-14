#include<iostream>
#define         Okay_bye        return 0

using namespace std;
int knapsack(int n,int capacity,int p[],int w[]);
int main()
{
    int n,capacity,w[300],p[300],maxi,i;
    int t,k=1;
    cin>>t;
    while(t--)
    {
        maxi=0;
        cin>>n;
        if(n==0)
            break;
        cin>>capacity;
        for(i=1; i<=n; i++)
        {
            cin>>p[i]>>w[i];
        }
        maxi=knapsack(n,capacity,p,w);
        cout<<"Galho "<<k<<":"<<endl;
        cout<<"Numero total de enfeites: "<<maxi<<endl;
        k++;
    }
    cout<<endl;
    Okay_bye;
}
int knapsack(int n,int capacity,int p[],int w[])
{
    int dp[300][300],i,j;
    for(i=0; i<=n; i++)
        dp[i][0]=0;
    for(i=0; i<=capacity; i++)
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
    return dp[n][capacity];
}
