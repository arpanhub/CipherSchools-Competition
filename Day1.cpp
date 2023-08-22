#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int height[n];
    for(int i=0;i<n;i++)
    {
        cin>>height[i];
    }  
    int i=0;
    int j=n-1;
    int x;
    int MaxArea=0;
    int max_l1,max_l2;
    while(i<j)
    {
        if(height[i]<height[j])
        {
            x=height[i];
        }
        else
        {
            x=height[j];
        }
        int y=j-i;
        int area=x*y;
        if(area>MaxArea)
        {
            MaxArea=area;
             max_l1=x;
             max_l2=j;
        }
        if(height[i]<height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    } 
    cout<<"lines that can store maximum water are "<<max_l1<<" and "<<max_l2<<"="<<MaxArea;
}