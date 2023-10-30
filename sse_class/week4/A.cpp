#include <iostream>
#define MAX_NUM 500000
using namespace std;

int len, number[MAX_NUM], temp_num[MAX_NUM];
long long result;

void merge(int left, int mid, int right)
{
    int k = 0;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (number[i] <= number[j])
        {
            temp_num[k++] = number[i++];
        }
        else
        {
            result += mid - i + 1;
            temp_num[k++] = number[j++];
        }
    }
    while (i <= mid)
    {
        temp_num[k++] = number[i++];
    }
    while (j <= right)
    {
        temp_num[k++] = number[j++];
    }
}

void merge_sort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    merge(left, mid, right);
    for (int i = left; i <= right; i++)
    {
        number[i] = temp_num[i - left];
    }
}

int main()
{
    result = 0;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> number[i];
    }
    merge_sort(0, len - 1);
    cout << result << endl;
}