class Solution
{
public:
    void fun(vector<vector<int>> &image, int i, int j, int org_color, int color)
    {
        if (i > image.size() || j > image[0].size() || i < 0 || j < 0 || image[i][j] != org_color)
        {
            return;
        }

        if (image[i][j] == org_color)
        {
            image[i][j] = color;
            fun(image, i + 1, j, org_color, color);
            fun(image, i, j + 1, org_color, color);
            fun(image, i - 1, j, org_color, color);
            fun(image, i, j - 1, org_color, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color)
    {
        fun(image, sr, sc, image[sr][sc], color);

        return image;
    }
};