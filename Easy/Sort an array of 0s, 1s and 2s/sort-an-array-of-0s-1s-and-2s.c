//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>


// } Driver Code Ends
//User function Template for C

void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}


void Merge(int arr[],int low,int mid,int high)
{
    int i = low, j = mid + 1, k = low;
    int b[high + 1];
    
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        
        else
        {
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    for(;i<=mid;i++)
    {
        b[k] = arr[i];
        k++;
    }
    for(;j<=high;j++)
    {
        b[k] = arr[j];
        k++;
    }
    for(int i = low; i <= high ; i++)
    {
        arr[i] = b[i];
    }
}

void Mergesort(int arr[],int low,int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high)/2;
        Mergesort(arr,low,mid);
        Mergesort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}


// int Partition(int arr[],int low,int high)
// {
//     int pivot = arr[low];
//     int i = low,j = high;
//     do
//     {
//         while(arr[i]<=pivot)
//         {
//             i++;
//         }
//         while(arr[i] > pivot)
//         {
//             j--;
//         }
//         if(i<j)
//         {
//             swap(&arr[i],&arr[j]);
//         }
//     }while(i < j);
    
//     swap(&arr[low],&arr[j]);
//     return j;
// }

// void Quicksort(int arr[],int low,int high)
// {
//     int j;
//     if(low < high)
//     {
//         j = Partition(arr,low,high);
//         Quicksort(arr,low,j);
//         Quicksort(arr,j+1,high);
//     }
// }

void sort012(int a[], int n)
{
    // Quicksort(a,0,n-1);
    // Mergesort(a,0,n-1);
    int brr[n];
    int count = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == 0)
        {
            brr[count] = a[i];
            count++;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == 1)
        {
            brr[count] = a[i];
            count++;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] == 2)
        {
            brr[count] = a[i];
            count++;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        a[i] = brr[i];
    }
}


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends