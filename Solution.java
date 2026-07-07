class Solution {
    public int[] getConcatenation(int[] nums) {
        int N = nums.length;

        int[] ans = new int[2 * N];

        for (int i = 0; i < N; i++) {
            ans[i] = nums[i];
            ans[i + N] = nums[i];
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = { 1, 2, 3 };
        int[] ans = sol.getConcatenation(nums);

        for (int i : ans) {
            System.out.println(i);
        }
    }
}