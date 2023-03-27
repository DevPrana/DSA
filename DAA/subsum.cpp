#include <iostream>
#include <stack>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    stack<pair<int, int>> st;
    st.push({0, 0});

    while (!st.empty())
    {
        int curr_sum = st.top().first;
        int index = st.top().second;
        st.pop();

        if (curr_sum == sum)
            return true;

        if (index == n)
            continue;

        st.push({curr_sum, index + 1});
        st.push({curr_sum + arr[index], index + 1});
    }

    return false;
}

int main()
{
    int n, sum;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum to be checked: ";
    cin >> sum;

    if (isSubsetSum(arr, n, sum))
        cout << "Subset with the given sum exists\n";
    else
        cout << "Subset with the given sum does not exist\n";

    return 0;
}