class Solution {
    public long subarrayXor(int arr[], int k) {
        // code here
        int cnt = 0;
        int n = arr.length;
        int frontXor = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        
        for(int i = 0; i < n; i++)
        {
        
                frontXor ^= arr[i];
                int x = frontXor ^ k;
                
                if(map.containsKey(x))
                {
                    cnt += map.get(x);
                }
                
                map.put(frontXor, map.getOrDefault(frontXor,0) + 1);
             
        }
        
        return cnt;
    }
}