class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid = 0, result = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (true)
            {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return result;
    }
};