#include <iostream>
using namespace std;
class first
{ //user defined class
public:
    int x, y; //complex number x+yi

public:
    first()
    { //default constructor with 0 + 0i
        x = 0;
        y = 0;
    }

    first(int r, int i) //Parameterized constructor
    {
        x = r;
        y = i;
    }

    void print(); //declaration of print function;
    void input();

    first operator+(first const &obj) // overloaded + operator
    {
        first f1;
        f1.x = x + obj.x;
        f1.y = y + obj.y;
        return (f1);
    }
    first operator*(first const &obj) // overloaded * operator
    {
        first f1;
        f1.x = x * obj.x - y * obj.y;
        f1.y = y * obj.x + x * obj.y;
        return (f1);
    }
};

void first ::print() //Definition of print function
{
    cout << "Complex number:   " << x << "+" << y << "i" << endl;
}

void first ::input()
{
    cout<<"Input the real part ";
    cin>>x;
    cout<<"Input the imaginary part ";
    cin>>y;
}

int main() //addition  a+bi "+"  c+di    = (a+c) + (b+d)i)
{  
    first hi;
    first h1,h2;
    cout<<"Input the first number "<<endl;
    h1.input();
    cout<<"Input the second number "<<endl;
    h2.input();
    first h3;
    first h4;
    h3 = h1 + h2;
    h4 = h1 * h2;
    cout<<"Addtiton: ";
    h3.print();
    cout<<"Multiplication: ";
    h4.print();
    return 0;
}