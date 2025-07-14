class Solution {
    int countFreq(int[] arr, int target) {
        // code here
        int n = arr.length;
        int l = 0;
        int r = n - 1;
        int first = -1;

        while(l <= r)
        {
            int mid = (l + r) >> 1;

            if(arr[mid] == target)
            {
                first = mid;
                r = mid - 1;
            }
            else if(arr[mid] < target)
            {
                l = mid + 1;
            }
            else 
            {
                r = mid - 1;
            }
        }

        if(first == -1) return 0;   
    
        int last = -1;
        l = 0;
        r = n - 1;

        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(arr[mid] == target)
            {
                last = mid;
                l = mid + 1;
            }
            else if(arr[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return last - first + 1;
    }
    
}
