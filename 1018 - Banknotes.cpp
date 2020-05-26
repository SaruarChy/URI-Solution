#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int N,i,coin[7]={100,50,20,10,5,2,1};
    int ways[7];
    cin>>N;
    cout<<N<<endl;
    for(i=0; i<7; i++)
    {
        ways[i]=N/coin[i];
        N=N%coin[i];
    }
    for(i=0; i<7; i++)
    {
        printf("%d nota(s) de R$ %d,00\n",ways[i],coin[i]);
    }

    return 0;
}
