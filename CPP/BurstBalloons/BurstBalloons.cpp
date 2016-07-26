// BurstBalloons.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
using namespace std;
class Solution {
public:
	int max(int a, int b) {
		return a > b ? a : b;
	}
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int> > vec(nums.size(), vector<int>(nums.size(), 0));
		for (int len = 1; len <=n; ++len) {
			for (int left = 1; left <= n - len + 1; ++left) {
				int right = left + len - 1;
				for (int k = left; k <= right; ++k) {
					vec[left][right] = max(vec[left][right], nums[left - 1] * nums[k] * nums[right + 1] + vec[left][k - 1] + vec[k + 1][right]);
				}
			}
		}
		return vec[1][n];
	}
};

int main()
{
	vector<int> vec = { 3,1,5,8 };
	Solution sol;
	int t = sol.maxCoins(vec);
	printf("%d\n",t);
    return 0;
}

