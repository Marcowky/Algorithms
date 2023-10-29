#include <iostream>
#include <cstring>
#define MAX_NUM 100010
using namespace std;

int num_array[MAX_NUM];

struct node
{
    int left, right, sum;
    node(int x, int y, int z) : left(x), right(y), sum(z) {}
};

node cal_mid_result(int num_array[], int left, int mid, int right)
{
    node temp_node(0, 0, 0);
    int temp_mid_left = -10000, temp_mid_right = -10000, temp_num = 0;
    for (int i = mid; i >= left; i--)
    {
        temp_num += num_array[i];
        if (temp_num >= temp_mid_left)
        {
            temp_node.left = i;
            temp_mid_left = temp_num;
        }
    }
    temp_num = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        temp_num += num_array[i];
        if (temp_num >= temp_mid_right)
        {
            temp_node.right = i;
            temp_mid_right = temp_num;
        }
    }
    temp_node.sum = temp_mid_left + temp_mid_right;
    return temp_node;
}

node cal_result(int num_array[], int left, int right)
{
    if (left == right)
    {
        return node(left, left, num_array[left]);
    }

    int mid = (right + left) / 2;
    node max_left = cal_result(num_array, left, mid);
    node max_right = cal_result(num_array, mid + 1, right);
    node max_mid = cal_mid_result(num_array, left, mid, right);
    if (max_left.sum >= max_right.sum && max_left.sum >= max_mid.sum)
    {
        return max_left;
    }
    else if (max_mid.sum >= max_left.sum && max_mid.sum >= max_right.sum)
    {
        return max_mid;
    }
    else
    {
        return max_right;
    }
}

int main()
{
    int total_case, case_num = 0, num_num;
    cin >> total_case;
    while (total_case--)
    {
        cin >> num_num;
        memset(num_array, 0, sizeof(num_array));
        for (int i = 0; i < num_num; i++)
        {
            cin >> num_array[i];
        }
        node result = cal_result(num_array, 0, num_num - 1);
        if (case_num)
            cout << endl;
        cout << "Case " << ++case_num << ":" << endl;
        cout << result.sum << " " << result.left + 1 << " " << result.right + 1 << endl;
    }
}