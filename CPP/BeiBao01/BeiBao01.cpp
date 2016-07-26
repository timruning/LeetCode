// BeiBao01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int beiBao(int keyValue[][2],int n,int m) {
	int A[10][2000] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0) {
				if (j >= keyValue[i][0])
					A[i][j] = keyValue[i][1];
				else
					A[i][j] = 0;
				continue;
			}
			if (j < keyValue[i][0]) {
				A[i][j] = A[i - 1][j];
			}
			else {
				A[i][j] = max(A[i - 1][j], A[i-1][j - keyValue[i][0]] + keyValue[i][1]);
			}
		}
	}
	return A[n - 1][m];
}
int main() {
	int n, m;
	scanf_s("%d%d", &n, &m);
	int keyValue[501][2] = {0};
	for (int i = 0; i < n; i++) {
		scanf_s("%d%d", &keyValue[i][0], &keyValue[i][1]);
	}
	int result = beiBao(keyValue, n, m);
	printf("%d\n", result);
}

