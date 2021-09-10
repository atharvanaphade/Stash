#include <bits/stdc++.h>
#define MOD 1000000007
#define print(x) for (auto i : x) cout << x << " "

using namespace std;

namespace TP {
	int x = 69420;
	void Print() {
		cout << "Hello";
	}
	template <class T>
class Complex {
	T real;
	T imag;
public:

	Complex() {
		this->real = 0;
		this->imag = 0;
	}

	Complex(T a, T b) {
		this->real = a;
		this->imag = b;
	}
	
	void Print() {
		cout << this->real << " " << this->imag << "j";
	}

	Complex operator + (Complex const &obj) {
		Complex ret;
		ret.real = real + obj.real;
		ret.imag = imag + obj.imag;
		return ret;
	}
};
}

// Template is a blueprint for creating new Classes/Functions.
// Templates can be either Functions or Classes.

// Template Function
template <class T>
void BubbleSort (T arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap (arr[j], arr[j + 1]);
			}
		}
	}
}

// Template Class


// CORMEN

// parent -> a, b, d -> c.print();

int main () {
	long long arr[] = { 1, 5, 2, 4, 6 };
	cout << "Before Sort : ";
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << "\n";
	BubbleSort<long long> (arr, 5);
	cout << "After Sort : ";
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << "\n";
	Complex<
	TP::Complex<int> a();
	TP::Print();
	int y = TP::x;
}