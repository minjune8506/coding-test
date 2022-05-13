#include <iostream>
#include <ctime>

using namespace std;

bool isPrimeNumber1(long long num) {
	for (long long i = 2 ; i < num ; i++) {
		if (num % i == 0) {
			return (false);
		}
	}
	return (true);
}

bool isPrimeNumber2(long long num) {
	for (long long i = 2 ; i <= num / 2 ; i++) {
		if (num % i == 0) {
			return (false);
		}
	}
	return (true);
}

bool isPrimeNumber3(long long num) {
	for (long long i = 2 ; i * i <= num ; i++) {
		if (num % i == 0) {
			return (false);
		}
	}
	return (true);
}

int main(void) {
	long long num = 1234567890123456789; // 12자리
	clock_t start, finish;
	double duration;

	cout << "---------- Test 1 ----------" << endl;
	start = clock();
	cout << "is Prime Number ? : " << (isPrimeNumber1(num) ? "Yes" : "No" )<< endl;
	finish = clock();
	duration = double(finish - start);
	cout << "Test 1 Duration : " << duration << endl;

	cout << "---------- Test 2 ----------" << endl;
	start = clock();
	cout << "is Prime Number ? : " << (isPrimeNumber2(num) ? "Yes" : "No") << endl;
	finish = clock();
	duration = double(finish - start);
	cout <<  "Test 2 Duration : " << duration << endl;
	
	cout << "---------- Test 3 ----------" << endl;
	start = clock();
	cout << "is Prime Number ? : " << (isPrimeNumber3(num) ? "Yes" : "No") << endl;
	finish = clock();
	duration = double(finish - start);
	cout << "Test 3 Duration : " << duration << endl;
}
