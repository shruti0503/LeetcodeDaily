#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    
    int count = 0;
    int prod = 1;
    int left = 0;
    
    for (int right = 0; right < nums.size(); ++right) {
        prod *= nums[right];
        while (prod >= k) {
            prod /= nums[left];
            left++;
        }
        count += right - left + 1;
    }
    
    return count;
}

// Example usage:
#include <iostream>
int main() {
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    cout << numSubarrayProductLessThanK(nums1, k1) << endl;  // Output: 8
    
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    cout << numSubarrayProductLessThanK(nums2, k2) << endl;  // Output: 0
    
    return 0;
}
