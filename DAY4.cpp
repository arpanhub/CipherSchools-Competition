#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int nums[] = {2, 4, -2};
    int k = 5;

    int n = sizeof(nums) / sizeof(nums[0]);

    int maxSubsequences = 1 << n; // 2^n
    int* sums = new int[maxSubsequences];

    int count = 0;
    for (int mask = 0; mask < maxSubsequences; ++mask) {
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                currentSum += nums[i];
            }
        }
        sums[count++] = currentSum;
    }

    sort(sums, sums + count, greater<int>()); // Sort sums in descending order

    int kthLargestSum = sums[k - 1];
    cout << "The " << k << "-th Largest Sum in the array is " << kthLargestSum << endl;

    delete[] sums; // Clean up dynamically allocated memory

    return 0;
}
