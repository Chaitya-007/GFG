//{ Driver Code Starts
//Initial Template for C

#include<stdio.h>

// } Driver Code Ends
//User function Template for C

void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}


int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low,j = high;
    
    do
    {
        while(arr[i] <= pivot)
        {
         i++;   
        }
        
        while(arr[j] > pivot)
        {
            j--;
        }
        
        if(i < j)
        {
            swap(&arr[i],&arr[j]);
        }
        
    }while(i < j);
    
    swap(&arr[low],&arr[j]);
    return j;
}

void Quick_Sort(int arr[],int low,int high)
{
    int j;
    if(low < high)
    {
        j = Partition(arr,low,high);
        Quick_Sort(arr,low,j);
        Quick_Sort(arr,j+1,high);
    }
}


int kthSmallest(int arr[], int l, int r, int k)
    {
        Quick_Sort(arr,l,r);
        return arr[k-1];
    }


//{ Driver Code Starts.
 
int main()
{
    int test_case;
    scanf("%d",&test_case);
    while(test_case--)
    {
        int number_of_elements;
        scanf("%d", &number_of_elements);
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            scanf("%d", &a[i]);
            
        int k;
        scanf("%d",&k);
        printf("%d",kthSmallest(a, 0, number_of_elements-1, k));
        printf("\n");
    }
    return 0;
}
// } Driver Code Ends