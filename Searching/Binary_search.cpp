#include<iostream>
using namespace std;
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int ele;
    cout<<"Enter element to search :- "<<endl;
    cin>>ele;
    int flag=0 , middle=0, low=0, high=9;

    while(low<=high)
    {
        middle=(low+high)/2;
        if(arr[middle]==ele)
        {
            flag=1;
            break;
        }    
        else
        if(arr[middle]>ele)
            high=middle-1;
        else
            low=middle+1;
    }
    if(flag==1)
        cout<<"Element Found "<<endl;
    else
        cout<<"Element Not Found "<<endl;
    return 0;
}