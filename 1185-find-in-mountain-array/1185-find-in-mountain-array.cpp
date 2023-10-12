class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // Find the peak index
        int peakIndex = findPeakIndex(mountainArr, 0, n - 1);
        // Search the left side (ascending order) of the mountain array
        int leftResult = binarySearchAscending(mountainArr, target, 0, peakIndex);
        if (leftResult != -1) return leftResult;
        // Search the right side (descending order) of the mountain array
        return binarySearchDescending(mountainArr,target,peakIndex+1,n-1);
    }

private:
    int findPeakIndex(MountainArray &mountainArr, int left, int right) {
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            int nextValue = mountainArr.get(mid + 1);
            if (midValue < nextValue) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int binarySearchAscending(MountainArray &mountainArr, int target, int left, int right) {
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            else if (midValue < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int binarySearchDescending(MountainArray &mountainArr, int target, int left, int right) {
        while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) return mid;
            else if (midValue < target) right = mid - 1;//SEARCH LEFT PART
            else left = mid + 1;//SEARCH RIGHT PART
        }
        return -1;
    }
};
