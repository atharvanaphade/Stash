#include <bits/stdc++.h>

using namespace std;

// Overloading : -
// 		|
//		| -> Function
// 		| -> Operator

class Complex {
	int real;
	int imag;
public:

	Complex() {
		this->real = 0;
		this->imag = 0;
	}

	Complex(int a, int b) {
		this->real = a;
		this->imag = b;
	}

	void Print() {
		cout << this->real << " " << this->imag << "j";
	}

	void Print(int a) {
		cout << a << endl;
	}

	Complex operator + (Complex const &obj) {
		Complex ret;
		ret.real = real + obj.real;
		ret.imag = imag + obj.imag;
		return ret;
	}
};

// y1 = mx1 + c1
// y2 = mx2 + c2
// y1 + y2 = m(x2 + c1) + c1 + c2


int main () {
	Complex a(1, 2), b(2, 5);
	a.Print();
	cout << endl;
	b.Print();
	cout << endl;
	a = a + b;
	a.Print();
	// a.Print(6);
}

// . :: ?: sizeof .* Cannot be overloaded

// + / % += ++ -- new delete Can be overloaded



