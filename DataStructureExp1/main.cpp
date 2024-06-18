//main.cpp
#include<iostream>
#include<vector>
#include"SparseMatrix.h"
using namespace std;

//q1 function
int search(vector<int>arr, int target) {//顺序为从小到大
	if (target <= arr[0])
		return 0;
	if (target >= arr[arr.size()-1])
		return arr.size()-1;
	int low = 0, mid, high = arr.size()-1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] < target)//则target若存在于数组中应在中值与最大值之间
			low = mid + 1;
		else if (arr[mid] > target)//则target若存在于数组中应在最小值与中值之间
			high = mid - 1;
		else//arr[mid]==target
			return mid;
	}
	return mid;
}

//q2  function
void arrCompare(int* a, int aSize, int* b, int bSize) {
	if (aSize > bSize)
		cout << "Neither a<b nor a=b." << endl;
	int j = 0;
	for (j = 0; j < aSize; ++j) {//下标为0至j-1的元素值均相等
		if (a[j] != b[j])
			break;
	}
	if (j == aSize && aSize < bSize) {
		cout << "a<b" << endl;
		return;
	}
	if (aSize == bSize && j == aSize) {
		cout << "a=b" << endl;
		return;
	}
	if (a[j] < b[j]) {
		cout << "a<b" << endl;
		return;
	}
}

int main() {
	//q1 code

	//const int size = 10;
	//vector<int>nums = { 1,3,5,7,9,11,13,15,17,19 };
	//int t;//test target value 9 20 -1 4
	//while (cin >> t) {
	//	cout << "value " << t << " is at position or should be put at position:" << search(nums, t) << endl;
	//}
	//return 0;
	

	//q2 code
	/*const int n = 5, m = 8;
	int a[n] = { 1,2,3,4,5 };
	int b1[m] = { 1,2,3,4,6,7,8,9 };
	int b2[m] = { 1,2,3,4,5,6,7,8 };
	arrCompare(a, n, b1, m);
	arrCompare(a, n, b2, m);
	arrCompare(a, n, a, n);
	arrCompare(b1, m, a, n);
	return 0;*/

	//q3 code
	SparseMatrix m(6, 6, 8);
	m.smArray[0].row = 0, m.smArray[0].col = 0, m.smArray[0].value = 15;
	m.smArray[1].row = 0, m.smArray[1].col = 3, m.smArray[1].value = 22;
	m.smArray[2].row = 0, m.smArray[2].col = 5, m.smArray[2].value = -15;
	m.smArray[3].row = 1, m.smArray[3].col = 1, m.smArray[3].value = 11;
	m.smArray[4].row = 1, m.smArray[4].col = 2, m.smArray[4].value = 3;
	m.smArray[5].row = 2, m.smArray[5].col = 3, m.smArray[5].value = -6;
	m.smArray[6].row = 4, m.smArray[6].col = 0, m.smArray[6].value = 91;
	m.smArray[7].row = 5, m.smArray[7].col = 2, m.smArray[7].value = 28;
	m.print();//original matrix
	cout << endl;
	m.FastTranspose().print();//original transpose function
	cout << endl;
	m.FastTransposeUpdated().print();//updated function
	return 0;
	vector<int>nums;
	nums.emplace_back(0);
	nums.emplace_back(1);
	cout << &nums + 1;
}