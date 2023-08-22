#include <iostream>
using namespace std;
int checktriplet(int* arr,int n){
    int sum;
    int ctr=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            int y=-(arr[i]+arr[j]);
            for(int k=j+1;k<n;k++){
                if(y==arr[k]){
                    return 1;
                    break;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    cin>> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<checktriplet(arr,n);
}











