#include<iostream>
using namespace std;
int main()
{
    int n, i, j, current;
    cin>>n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    // before insertion sort
    cout<<"Array before insertion sort : -"<<endl;
    for (i = 0; i < n; i++)
    {
        cout<<*(arr + i)<<" ";
    }
    cout<<endl;

    //sorting
    for (i = 1; i <= n-1; i++)
    {
        current = arr[i];
        for (j = i-1; j >= 0 && arr[j]>current; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = current;
    }
    
    // after insertion sort
    cout<<"Array after insertion sort : -"<<endl;
    for (i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}