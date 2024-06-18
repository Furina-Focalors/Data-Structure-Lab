//main.cpp
#include<iostream>
#include<string>
#include"Polynomial.h"
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<cmath>
using namespace std;
//exp1 func
void calculate(string str) {
	int appearTimes[95] = {};//所有可显示字符出现次数，按ASCII排列
	for (int i = 0; i < str.length(); ++i) {
		++appearTimes[str[i] - 32];//前32位是控制字符
	}
	for (int j = 0; j < 95; ++j) {
		if (appearTimes[j] != 0)
			cout << "Character '" << char(j + 32) << "' appeared " << appearTimes[j] << " time(s).\n";
	}
}
//exp2 func
void inverse(int* nums,int length) {
	for (int i = 0; i < length / 2; ++i) {
		int temp = nums[length - 1 - i];
		nums[length - 1 - i] = nums[i];
		nums[i] = temp;
	}
}
//extra func
string digitMax(string s,int mid) {
	string temp;
	if (s[mid - 1] == s[mid]) {//向前匹配
		int i;
		for (i = 1; mid - 1 - i >= 0 && mid + i < s.length(); ++i)
			if (s[mid - 1 - i] != s[mid + i])
				break;
		temp = s.substr(mid - i, 2 * i);
	}
	if (s[mid + 1] == s[mid]) {//向后匹配
		int i;
		for (i = 1; mid + 1 + i < s.length() && mid - i >= 0; ++i)
			if (s[mid + 1 + i] != s[mid - i])
				break;
		temp = s.substr(mid - i + 1, 2 * i);
		if (s.substr(mid - i + 1, 2 * i).length() > temp.length())
			temp = s.substr(mid - i + 1, 2 * i);//相同长度保留靠前的子串
	}
	//以mid为中心匹配
		int i;
		for (i = 1; mid + i < s.length() && mid - i >= 0; ++i)
			if (s[mid + i] != s[mid - i])
				break;
		if(s.substr(mid - i + 1, 2 * i - 1).length()>temp.length())
			temp = s.substr(mid - i + 1, 2 * i - 1);

	return temp;
}
string longestPalindrome(string s) {
	int mid = s.length() / 2;
	string result = "";
	int maxLength = 0;
	int i = 0, j = 0;//counter
	while (mid + j <= s.length() - 1 - maxLength / 2 && mid + j >= maxLength / 2) {//小于已获得字符串最大长度的一半为中心一定不是最长
		if (digitMax(s, mid + j).length() >= result.length()) {
			result = digitMax(s, mid + j);
			maxLength = result.length();
		}
		++i;
		j = pow(-1, i - 1) * (1 + (i - 1) / 2);//mid +1 -1 +2 -2 ...
	}
	if (s.length() % 2 == 0 && digitMax(s, mid - j).length() >= result.length())//为获取靠前的字符串，偶数长度需多比较一次
		return digitMax(s, mid - j);
	return result;
}
int main() {
	//exp 1
	/*string str = "1145141919810 a bcd [;.p";
	calculate(str);
	return 0;*/

	//exp 2
	/*const int aLength = 9, bLength = 8;
	int a[aLength] = { 1,2,3,4,5,6,7,8,9 };
	int b[bLength] = { 1,2,3,4,5,6,7,8 };
	cout << "Before inverse,\n"
		<< "a[]=";
	for (int i = 0; i < aLength; ++i)
		cout << a[i] << ' ';
	cout << endl;
	cout << "b[]=";
	for (int i = 0; i < bLength; ++i)
		cout << b[i] << ' ';
	cout << endl;
	inverse(a, aLength);
	inverse(b, bLength);
	cout << "After inverse,\n"
		<< "a[]=";
	for (int i = 0; i < aLength; ++i)
		cout << a[i] << ' ';
	cout << endl;
	cout << "b[]=";
	for (int i = 0; i < bLength; ++i)
		cout << b[i] << ' ';
	cout << endl;
	return 0;*/

	//exp 3

	//part 1
	/*srand(time(0));
	const int maxDegree = 5;
	Polynomial b(maxDegree);
	for (int i = 0; i <= 5; ++i)
		b.coef[i] = rand() % 10;
	cout << "a=";
	b.print();
	cout << endl;
	cout << "F1a=" << b.F1a(2) << endl;
	cout << "F1b=" << b.F1b(2, maxDegree) << endl;
	cout << "F2a=" << b.F2a(2) << endl;
	cout << "F2b=" << b.F2b(2, maxDegree) << endl;*/

	//part 2
	//Polynomial a[16] = { Polynomial(1),Polynomial(5),Polynomial(10),Polynomial(15),Polynomial(20),Polynomial(25),Polynomial(30) ,Polynomial(35)
	//,Polynomial(40) ,Polynomial(45) ,Polynomial(50) ,Polynomial(60) ,Polynomial(70) ,Polynomial(80) ,Polynomial(90),Polynomial(100) };
	//for (int i = 0; i < 16; ++i) {
	//	for (int j = 0; j <= a[i].degree; ++j)
	//		if (j == 0)
	//			a[i].coef[j] = 1;
	//		else
	//			a[i].coef[j] = float(1) / float(j);
	//}
	//cout << "x=1.1，n=5时，f3(x)=" << a[1].F1a(1.1) << endl;
	////get time
	//int m, n;
	//cout << setw(6) << "alg|n";
	//for (int i = 0; i < 16; ++i)
	//	cout << setw(6) << a[i].degree;
	//cout << endl << setw(6) << "F1a";
	//for (int i = 0; i < 16; ++i) {
	//	clock_t timeReq = clock();
	//	for(m=0;m<999;++m)
	//		for(n=0;n<999;++n)
	//			a[i].F1a(1.1);//run for 10^6 times
	//	timeReq = clock() - timeReq;
	//	cout << setw(6) << (float)timeReq / CLOCKS_PER_SEC;
	//}
	//cout << endl << setw(6) << "F1b";
	//for (int i = 0; i < 16; ++i) {
	//	clock_t timeReq = clock();
	//	for (m = 0; m < 999; ++m)
	//		for (n = 0; n < 999; ++n)
	//			a[i].F1b(1.1,a[i].degree);//run for 10^6 times
	//	timeReq = clock() - timeReq;
	//	cout << setw(6) << (float)timeReq / CLOCKS_PER_SEC;
	//}
	//cout << endl << setw(6) << "F2a";
	//for (int i = 0; i < 16; ++i) {
	//	clock_t timeReq = clock();
	//	for (m = 0; m < 999; ++m)
	//		for (n = 0; n < 999; ++n)
	//			a[i].F2a(1.1);//run for 10^6 times
	//	timeReq = clock() - timeReq;
	//	cout << setw(6) << (float)timeReq / CLOCKS_PER_SEC;
	//}
	//cout << endl << setw(6) << "F2b";
	//for (int i = 0; i < 16; ++i) {
	//	clock_t timeReq = clock();
	//	for (m = 0; m < 999; ++m)
	//		for (n = 0; n < 999; ++n)
	//			a[i].F2b(1.1,a[i].degree);//run for 10^6 times
	//	timeReq = clock() - timeReq;
	//	cout << setw(6) << (float)timeReq / CLOCKS_PER_SEC;
	//}
	//cout << endl;
	//return 0;

	//extra
	string a = "aba123bbb789dtzx";
	cout << longestPalindrome(a);
	return 0;
}