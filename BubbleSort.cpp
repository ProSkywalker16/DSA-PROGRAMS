#include <iostream>
using namespace std;
int main()
{
    int n;
    int i,j;
    cout<<"enter size of array:";
    cin >> n;
    int arr[n];
    cout<<"Enter "<<n<<" elements in the array:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"The unsorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    //Bubble sort algorithm
    for(i=0;i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            while(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    cout<<"The sorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    return 0;
}