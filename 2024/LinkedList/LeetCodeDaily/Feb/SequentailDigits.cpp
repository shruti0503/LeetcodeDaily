#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> sequentialDigits(int low, int high) {
    vector<int> result;
    for (int num = low; num <= high; ++num) {
        string numStr = to_string(num);
        bool isSequential = true;
        for (int i = 1; i < numStr.size(); ++i) {
            if (numStr[i] != numStr[i - 1] + 1) {
                isSequential = false;
                break;
            }
        }
        if (isSequential) {
            result.push_back(num);
        }
    }
    return result;
}

int main() {
    int low = 100;
    int high = 300;
    vector<int> result1 = sequentialDigits(low, high);
    cout << "Output for range [" << low << ", " << high << "]: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    low = 1000;
    high = 13000;
    vector<int> result2 = sequentialDigits(low, high);
    cout << "Output for range [" << low << ", " << high << "]: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
