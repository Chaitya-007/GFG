#User function Template for python3

class Solution:
    def getMinDiff(self, arr,k):
        # code here
        n=len(arr)
        arr.sort()
        result=arr[-1]-arr[0]
        small=arr[0]+k
        large=arr[-1]-k
        if small>large:
            small, large=large, small
        for i in range(n):
            min_height=min(small, arr[i]-k)
            max_height=max(large, arr[i-1]+k)
            if min_height < 0:
                continue
            result=min(result, max_height-min_height)
        return result

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, k)
        print(ans)
        tc -= 1

# } Driver Code Ends