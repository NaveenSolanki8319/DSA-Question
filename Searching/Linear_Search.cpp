#include<iostream>
using namespace std;
int main()
{
    int arr[]={10,30,20,15,11,5,81,58,3};
    int ele;
    cout<<"Enter element to search :- "<<endl;
    cin>>ele;
    int flag=0;
    for (int i = 0; i < 9; i++)
    {
        if(arr[i] == ele)
        {
            flag=1;
            break;
        }    
    }
    if(flag==1)
        cout<<"Element Found "<<endl;
    else
        cout<<"Element Not Found "<<endl;
    return 0;
}