// You will be given an array A of size N. You need to tell which value occurs the most and the count of that value.

// Note: If there are multiple values with the highest count, then pick the maximum value as answer.

// Input Format

// First line will contain T, the number of test cases.
// First line of each test case will contain N.
// Second line of each test case will contain the array A of size N.
// Constraints

// 1 <= T <= 100
// 1 <= N <= 10^5
// -10^9 <= A[i] <= 10^9
// Output Format

// Output the number that occurs the most, then the count of that number.
// Sample Input 0

// 3
// 10
// 2 1 3 5 4 6 5 2 1 3
// 10
// -5 -2 1 5 -5 4 -2 -1 -2 -1
// 5
// -1000000000 -112101 10100101 1000000000 12345
// Sample Output 0

// 5 2
// -2 3
// 1000000000 1


// #include <iostream>
// using namespace std;

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//       cin >> arr[i];
//     }


//     int max_count = 1, most_frequent = arr[0];

//     // Iterate over the array and update the maximum count and the most frequent element.
//     for (int i = 1; i < n; i++) {
//       int count = 1;
//       for (int j = i + 1; j < n; j++) {
//         if (arr[i] == arr[j]) {
//           count++;
//         }
//       }

//       if (count > max_count) {
//         max_count = count;
//         most_frequent = arr[i];
//       } else if (count == max_count && arr[i] > most_frequent) {
//         most_frequent = arr[i];
//       }
//     }

//     cout << most_frequent << " " << max_count << endl;
//   }
//   return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++) {
//       cin >> arr[i];
//     }


//     int max_count = 1, high_val = arr[0];


//     for (int i = 0; i < n; i++) {
//       int count = 1;
//       for (int j = i + 1; j < n; j++) {
//         if (arr[i] == arr[j]) {
//           count++;
//         }
//       }

//       if (count > max_count) {
//         max_count = count;
//         high_val = arr[i];
//       } else if (count == max_count && arr[i] > high_val) {
//         high_val = arr[i];
//       }
//     }

//     cout << high_val << " " << max_count << endl;
//   }
//   return 0;
// }





#include <bits/stdc++.h>

using namespace std;

pair<int, int> highNumber(const vector<int>& arr) {
    int n = arr.size();
    int max_count = 1;
    int high_val = arr[0];
    int count = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
            high_val = arr[i];
        } else if (count == max_count && arr[i] > high_val) {
            high_val = arr[i];
        }
    }

    return make_pair(high_val, max_count);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        pair<int, int> result = highNumber(A);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}

