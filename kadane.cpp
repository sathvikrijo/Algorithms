#include<bits/stdc++.h>

using namespace std;

int kadane(int a[], int n)
{
    int current_sum, global_sum;
    current_sum = global_sum = a[0];
    for(int i=1; i<n; i++)
    {
        current_sum = max(a[i], current_sum+a[i]);
        global_sum = max(current_sum,global_sum);
    }
    return global_sum;
}

int main()
{
    int arr[] = {-1,-3,2,1,-4,5,6,-3,0,1,1,1,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    int max_sum = kadane(arr,size);
    cout<<max_sum<<endl;

}