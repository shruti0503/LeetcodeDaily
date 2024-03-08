/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function(nums) {
    const numCount = new Map();

    for (let i = 0; i < nums.length; i++) {
        numCount.set(nums[i], (numCount.get(nums[i]) || 0) + 1);
    }

    // Now, find the maximum frequency
    let maxFrequency = 0;
    for (const count of numCount.values()) {
        maxFrequency = Math.max(maxFrequency, count);
    }

    // Count the elements with maximum frequency
    let totalElements = 0;
    for (const count of numCount.values()) {
        if (count === maxFrequency) {
            totalElements += count;
        }
    }

    return totalElements;
};

// Example usage:
const nums = [1, 2, 2, 3, 1, 4];
const result = maxFrequencyElements(nums);
console.log(result); // Output: 4
