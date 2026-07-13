class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> rooms(n, 0);

        sort(meetings.begin(), meetings.end());

        int m = meetings.size();
        priority_queue<vector<int>, vector<vector<int>>,
                       std::greater<vector<int>>>
            minHeap;
        for (int i = 0; i < m; i++)
        {
            if (minHeap.size() < n)
            {
                int sz = minHeap.size();

                if (sz > 0 && minHeap.top()[0] <= meetings[i][0])
                {
                    int room = minHeap.top()[2];
                    int add = minHeap.top()[0];
                    minHeap.pop();
                    while (minHeap.size() &&
                           minHeap.top()[0] <= meetings[i][0])
                    {
                        if (minHeap.top()[2] < room)
                        {
                            room = minHeap.top()[2];
                            add = minHeap.top()[0];
                        }
                        minHeap.pop();
                    }
                    rooms[room] += 1;
                    minHeap.push(
                        {add + meetings[i][1], add + meetings[i][0], room});
                }
                else
                {
                    rooms[sz] += 1;
                    minHeap.push({meetings[i][1], meetings[i][0], sz});
                }
            }
            else
            {
                int room = minHeap.top()[2];
                int add = minHeap.top()[0];
                minHeap.pop();
                while (minHeap.size() && minHeap.top()[0] <= meetings[i][0])
                {
                    if (minHeap.top()[2] < room)
                    {
                        room = minHeap.top()[2];
                        add = minHeap.top()[0];
                    }
                    minHeap.pop();
                }
                rooms[room] += 1;
                minHeap.push(
                    {add + meetings[i][1], add + meetings[i][0], room});
            }
        }

        int mx = -1;
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if (rooms[i] > mx)
            {
                mx = rooms[i];
                ans = i;
            }
        }

        return ans;
    }
};