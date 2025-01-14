#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

double Divsion(int a, int b) {
	if (b == 0)
		throw "Divison by zero condition!";
	else
		return ((double)a / (double)b);
}
void Func() {
	int len, time;
	cin >> len >> time;
	cout << Divsion(len, time) << endl;
}
int main()
{
	try {
		Func();
	}
	catch(int errmsg){
		cout << errmsg << endl;
	}
	catch (...) {
		cout << "unkown exception" << endl;
	}

	return 0;
}