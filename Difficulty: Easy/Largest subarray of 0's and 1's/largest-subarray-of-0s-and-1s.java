class Solution {
    public int maxLen(int[] arr) {
        // Your code here
        // Brute
        int n = arr.length;
        int sum = 0;
        int maxlen = 0;
        int k = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < n; i++)
        {
            sum += arr[i] == 1 ? 1 : -1;
            
            if(sum == k)
            {
                maxlen = Math.max(maxlen,i+1);
            }
            
            int rem = sum - k;
            if(map.containsKey(rem))
            {
                int ind = map.get(rem);
                maxlen = Math.max(maxlen, i - ind);
            }
            
            if(!map.containsKey(sum))
            {
                
            map.put(sum, i);
            }
        }
        
        return maxlen;
    }
}