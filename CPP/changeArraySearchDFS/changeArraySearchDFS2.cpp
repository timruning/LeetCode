// changeArraySearchDFS2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
void printVec(const vector<int>& vec) {
	for (int i = 0; i < vec.size() - 1; i++) {
		cout << vec[i] << " ";
	}
	cout << vec[vec.size() - 1] << endl;
}
void print(const vector<vector<int>>& vec) {
	int nline = vec.size();
	vector<int> sta(nline, 0);
	vector<int> stb(nline, 0);
	for (int i = 0; i < nline; i++) {
		sta[i] = vec[i][stb[i]];
	}
	int p = nline-1;
	while (p>=0)
	{
		stb[p] += 1;
		if (stb[p] < vec[p].size()) {
			sta[p] = vec[p][stb[p]];
			for (int j = p + 1; j < nline; j++) {
				stb[j] = 0;
				sta[j] = vec[j][stb[j]];
			}
			printVec(sta);
			p = nline-1;
		}
		else {
			p--;
		}
	}
}
int main()
{
	vector<vector<int>> vec = {
		{3,4,6,1},
		{2,98,5},
		{4,5,2,10},
		{1,2,4,9,4,10}
	};
	print(vec);
    return 0;
}

