/*
 * @lc app=leetcode id=1000 lang=java
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
class Solution {
    int[][][] dp = new int[31][31][31];
    int[] sum = new int[31];

    int f (int l, int r, int piles, int k) {
        if (l == r && piles == 1) return dp[l][r][piles] = 0;
        if ((r - l + 1) % (k - 1) != 0) {
            return 2147483647 / 2;
        }
        int ret = dp[l][r][piles];
        if (ret != -1) {
            return ret;
        }
        ret = 2147483647 / 2;
        if (piles == 1) {
            ret = f (l, r, 1, k) + sum[r + 1] - sum[l];
        } else {
            for (int i = l; i < r; i++) {
                ret = Math.min (ret, f (l, i, 1, k) + f (i + 1, r, piles - 1, k));
            }
        }
        return ret;
    }
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        
        return 0;
    }
}
// @lc code=end

