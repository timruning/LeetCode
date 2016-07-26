// changeArraySearchDFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
void printVec(const vector<int>& array1) {
	for (int i = 0; i < array1.size() - 1; i++) {
		cout << array1[i] << " ";
	}
	cout << array1[array1.size() - 1] << endl;
}
bool addVector(const vector<vector<int>>& vec, vector<int>& stb) {
	int nline = stb.size() - 1;
	int pline = nline;
	while (nline >= 0) {
		stb[nline] += 1;
		if (stb[nline] < vec[nline].size()) {
			for (int j = nline + 1; j <= pline; j++) {
				stb[j] = 0;
			}
			return true;
		}
		else {
			nline--;
		}
	}
	return false;
}

void print(const vector<vector<int>>& array1) {
	int nline = array1.size();
	vector<int> stb(nline, 0);
	vector<int> sta(nline, 0);
	for (int i = 0; i < nline; i++) {
		sta[i] = array1[i][stb[i]];
	}
	printVec(sta);
	while (addVector(array1, stb)) {
		for (int i = 0; i < nline; i++) {
			sta[i] = array1[i][stb[i]];
		}
		printVec(sta);
	}
}

int main()
{
	vector<vector<int>> vec = {
		{1,2,3},
		{3,4,7,2},
		{4,7,9,2,12}
	};
	print(vec);
    return 0;
}

