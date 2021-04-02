int trap(vectorint &height)
{
    int layer = 1;
    int left = -1;
    int right = -1;
    int bar = 0;
    int all = 0;
    for (int i = 0; i  height.size(); i++)
    {
        if (height[i])
        {
            if (left==-1)
                left = i;
            bar += height[i];
            right = i;
        }
    }
    if (left == right)
        return 0;
    while (left = right)
    {
        all += right - left + 1;
        layer++;
        while (left = right && height[left]  layer)
        {
            left++;
        }
        while (left = right && height[right]  layer)
        {
            right--;
        }
    }
    return all - bar;
}