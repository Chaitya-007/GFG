class Solution {
    int maxLength(int arr[]) {
        // code here
        int n = arr.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int k = 0;
        int maxlen = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            
            if(sum == k)
            {
                int len = i + 1;
                maxlen = Math.max(maxlen,len);
            }
            
            int rem = sum - k;
            
            if(map.containsKey(rem))
            {
                int ind = map.get(rem);
                int len = i - ind;
                maxlen = Math.max(maxlen,len);
            }
            
            if(!map.containsKey(sum))
            {
                map.put(sum, i);
            }
        }
        
        return maxlen;
    }
}