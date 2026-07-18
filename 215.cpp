class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (auto x : nums)
        {
            min_heap.push(x);
        }

        for (int i = 0; i < k - 1; i++)
        {
            min_heap.pop();
        }

        return min_heap.top();
    }
};