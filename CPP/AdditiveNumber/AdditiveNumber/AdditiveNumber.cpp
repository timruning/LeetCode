// AdditiveNumber.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
using namespace std;
string add(const string& a,const string& b) {
	string result = "";
	int t = 0;
	int num1;
	int num2;
	int sum;
	for (size_t i = 0;; i++) {
		if (i < a.size() && i < b.size()) {
			num1 = a[a.size() - i - 1];
			num2 = b[b.size() - i - 1];
			sum = num1 + num2 + t-2*'0';
			t = sum / 10;
			result.insert(result.begin(), sum % 10 + '0');
		}
		else if (i < a.size()) {
			num1 = a[a.size() - i - 1]-'0';
			sum = num1 + t;
			t = sum / 10;
			result.insert(result.begin(), sum % 10 + '0');
		}
		else if (i < b.size()) {
			num1 = b[b.size() - i - 1]-'0';
			sum = num1 + t;
			t = sum / 10;
			result.insert(result.begin(), sum % 10 + '0');
		}else if(t>0){
			result.insert(result.begin(), t + '0');
			t = 0;
		}
		else {
			break;
		}
	}
	return result;
}
class Solution {
public:
	bool isAddNum(const string& num,string numa,string numb) {
		size_t t = numa.size() + numb.size();
		while (true)
		{
			string numc = add(numa, numb);
			size_t k = 0;
			while (k< numc.size()) {
				if (k + t == num.size())
					return false;
				if (numc[k] == num[k + t]) {
					k++;
				}
				else {
					return false;
				}
			}
			numa = numb;
			numb = numc;
			t += numb.size();
			if (t == num.size())
				return true;
		}
	}
	bool isAdditiveNumber(string num) {
		size_t i = 0;
		while (i<num.size()-1)
		{
			string numA(num.begin(), num.begin() + i + 1);
			if (numA[0] == '0'&&numA.size() > 1) {
				break;
			}
			size_t j = i + 1;
			while (j<num.size())
			{
				string numB(num.begin() + i+1, num.begin() + j+1);
				if (numB[0] == '0'&&numB.size() > 1) {
					break;
				}
				if (isAddNum(num, numA, numB)) {
					printf("nihao\n");
					return true;
				}
				if (numB[0] == '0') {
					break;
				}
				j++;
			}
			i++;
		}
		return false;
	}
};

int main()
{
	string s = "111122335588143";
	Solution sol;
	if (sol.isAdditiveNumber(s)) {
		printf("hello\n");
	}
    return 0;
}

