// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class A;
class B {
	int a;
public:
	B(int a): a(a) { cout << "Con" << endl; }
	//B() = default;
	explicit B(const A& x) {}
	int geta()const { return a; }
	//B& operator= (const A& x) { return *this; }
	//operator A() { return A(); }
};
class A {
	B& bobj;
public:
	A(B& bojb) : bobj((bojb)) {}
	const B& getbobj()const { return bobj; }
	int d;
};
void fn(B x) {}
void fn2(int *&a)
{
	*a = 2;
	int c = 8;
	a = &c;
}
int main()
{
	//A foo;
	B bar(8);
	//bar = foo;
	//foo = bar;
	fn(bar);
	B bar2(bar);
	//  fn (foo);  // not allowed for explicit ctor.
	B* barr = new B[2]{ 1,2 };
	bar = 4;
	const B& obj(2);
	A foo2(bar);
	A foo3(barr[0]);
	//foo2 = foo3; //deleted function
	cout << foo2.getbobj().geta() << foo3.getbobj().geta() << endl;
	int num = 5;
	int num2 = 7;
	int *numptr = &num;
	delete[] barr;
	fn2(numptr);
	num = 0;
	const int& numref = num;
	num = 1;
	cout << foo2.d<< endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

