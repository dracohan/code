//在非递减序列 arr[s..e]（闭区间）上二分查找第一个大于等于key的位置，如果都小于key，就返回e+1
int upper_bound(int arr[], int s, int e, int key)
{
    int mid;
    if (arr[e] <= key)
        return e + 1;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] <= key)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int LIS(int d[], int n)
{
    int i = 0, len = 1, *end = (int *)alloca(sizeof(int) * (n + 1));
    end[1] = d[0]; //初始化：长度为1的LIS末尾为d[0]
    for (i = 1; i < n; i++)
    {
        int pos = upper_bound(end, 1, len, d[i]); //找到插入位置
        end[pos] = d[i];
        if (len < pos) //按需要更新LIS长度
            len = pos;
    }
    return len;
}