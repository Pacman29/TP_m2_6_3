#include <iostream>
#include <vector>

bool test_digit(long long number,int offset)
{
    return (number >> offset) & 1;
}

template <class T>
void MSD(std::vector<T>&arr, int left, int right, int offset) {
    int i = left;
    int j = right;
    if (right <= left || offset < 0)
        return;
    while (j != i)
    {
        while (!test_digit(arr[i], offset) && (i < j))
            i++;
        while (test_digit(arr[j], offset) && (j > i))
            j--;
        std::swap(arr[i], arr[j]);
    }
    if (test_digit(arr[right], offset) == 0)
        j++;

    MSD(arr, left, j - 1, offset - 1);
    MSD(arr, j, right, offset - 1);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    MSD(arr, 0, n-1, 63);

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << ' ';

    return 0;
}


