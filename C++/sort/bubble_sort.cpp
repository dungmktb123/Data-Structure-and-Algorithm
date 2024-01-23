#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = {3,6,7,1,2,0,8,9,15};
    int n = 10;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
