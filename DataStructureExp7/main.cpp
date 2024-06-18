//main.cpp
#include<iostream>
#include"SortingAlgorithm.h"
#include<random>
#include<vector>

//exp 3
template<class T>
int partition(std::vector<T>& arr, int lo, int hi) {//切分为arr[lo:i],arr[i],arr[i+1:hi+1]
	int i = lo, j = hi + 1;//左右指针
	T v = arr[lo];//切分元素
	while (true) {
		while (arr[++i] < v)//寻找左边第一个大于等于v的元素
			if (i == hi)break;//防止越界
		while (v < arr[--j]);//寻找右边第一个小于等于v的元素
			//if (j == lo)break;
		if (i >= j)break;//切分完成
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	//将切分元素与不大于它的一部分的最后一个元素交换
	T temp = arr[lo];
	arr[lo] = arr[j];
	arr[j] = temp;
	return j;
}

int quick_choose(std::vector<int>& arr, int k) {
	if (k<1 || k>arr.size())return NULL;
	int lo = 0, hi = arr.size() - 1;
	while (lo<hi) {
		int p = partition(arr, lo, hi);
		if (p == k - 1)return arr[p];
		else if (p > k - 1)hi = p - 1;//arr[k-1]在基准值左边
		else lo = p + 1;
	}
	return arr[lo];
}

//exp 4
int kth_smallest(std::vector<std::vector<int>>&mat, int k) {
	std::vector<int>temp;
	int size = mat.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)temp.emplace_back(mat[i][j]);
	}
	SortAlg::Sort::heap_sort(temp);
	return temp[k - 1];
}

//extra
int reverse_pair_easyfunc(std::vector<int>& arr) {
	int res = 0, size = arr.size();
	for(int i=0;i<size;++i)
		for (int j = i+1; j < size; ++j) {
			if (arr[i] > arr[j])++res;
		}
	return res;
}

int merge(std::vector<int>& arr, int lo, int mid, int hi) {
	int res = 0;//左边大即自增
	int i = lo, j = mid + 1;//两有序数组的第一位下标，每次将较小的填入后使下标后移
	std::vector<int>aux = arr;//临时数组
	for (int k = lo; k <= hi; ++k) {
		if (i > mid)arr[k] = aux[j++];//左边短
		else if (j > hi)arr[k] = aux[i++];//右边短
		else if (aux[i] <= aux[j])arr[k] = aux[i++];//左边小或等（保持稳定性）
		else {//左边大
			arr[k] = aux[j++];
			res += mid - i + 1;//左边比该值大的都构成逆序
		}
	}
	return res;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int merge_sort_BU(std::vector<int>& arr) {//自底向上
	int size = arr.size();
	int res = 0;
	for (int sz = 1; sz < size; sz += sz) {//sz为子数组大小，由2个大小为sz的子数组进行归并
		for (int lo = 0; lo < size - sz; lo += sz + sz) {//lo为子数组首地址
			res+=merge(arr, lo, lo + sz - 1, min(lo + sz + sz - 1, size - 1));
		}
	}
	return res;
}

int reverse_pair(std::vector<int>& arr) {
	return merge_sort_BU(arr);
}

int main() {
	//生成随机整数数列
	const int min_element = 0;
	const int max_element = 200;
	const int size = 10;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(min_element, max_element);
	std::vector<int>arr;
	for (int i = 0; i < size; ++i)arr.emplace_back(dist(gen));

	//exp 1
	/*std::cout << "Before quick_sort:\n";
	for (int i = 0; i < size; ++i)std::cout << arr[i] << ' ';
	std::cout << '\n';
	SortAlg::Sort::quick_sort(arr);
	std::cout << "After quick_sort:\n";
	for (int i = 0; i < size; ++i)std::cout << arr[i] << ' ';
	return 0;*/

	//exp 2
	/*std::cout << "Before heap_sort:\n";
	for (int i = 0; i < size; ++i)std::cout << arr[i] << ' ';
	std::cout << '\n';
	SortAlg::Sort::heap_sort(arr);
	std::cout << "After heap_sort:\n";
	for (int i = 0; i < size; ++i)std::cout << arr[i] << ' ';
	return 0;*/

	//exp 3
	/*std::cout << "Original array:\n";
	for (int i = 0; i < size; ++i)std::cout << arr[i] << ' ';
	std::uniform_int_distribution<> dist2(1, size);
	int k = dist2(gen);
	std::cout << "\nRandomly generate k=" << k << '\n';
	std::cout << "The kth num is " << quick_choose(arr, k);
	SortAlg::Sort::quick_sort(arr);
	std::cout << "\nAfter quick_sort, arr[k-1]=" << arr[k - 1];
	return 0;*/

	//exp 4
	//std::vector<std::vector<int>>mat;
	//std::uniform_int_distribution<> dist2(1, 20);
	//SortAlg::Sort::quick_sort(arr);
	//mat.emplace_back(arr);//第一行递增
	//for (int j = 0; j < size; ++j)std::cout << mat[0][j] << ' ';
	//std::cout << '\n';
	//for (int i = 1; i < size; ++i) {
	//	mat.emplace_back(mat[i - 1]);
	//	int k = dist2(gen);
	//	for (int j = 0; j < size; ++j) {//将每个元素增加随机值，同时增量增加随机值确保不出现反序
	//		mat[i][j] += k;
	//		k += dist2(gen);
	//		std::cout << mat[i][j] << ' ';
	//	}
	//	std::cout << '\n';
	//}
	//std::cout << "\n\nThe kth smallest(k=0 to size-1) is:\n";
	//for (int i = 0; i < size * size; ++i)
	//	std::cout << kth_smallest(mat, i + 1) << ' ';
	//std::cout << '\n';
	//return 0;

	//extra
	for (int i = 0; i < size; ++i)std::cout << arr[i] << ' ';
	std::vector<int>a = arr;
	std::cout << "\nReverse pairs=";
	std::cout << reverse_pair_easyfunc(arr) << "\nreverse_pair()=" << reverse_pair(a);
	return 0;
}