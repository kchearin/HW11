#include <iostream>
#include <fstream>
using namespace std;

class LoL {
public:
	LoL() {};
	int N1, N2, m;
	float a, b, x0, dx;
	ofstream dd;
	void f0(string ss) {
		dd.open(ss, ios::binary | ios::out);
		dd.write((char*)&N1, sizeof(int));
		dd.write((char*)&N2, sizeof(int));
		dd.write((char*)&a, sizeof(float));
		dd.write((char*)&b, sizeof(float));
		dd.write((char*)&x0, sizeof(float));
		dd.write((char*)&dx, sizeof(float));
		dd.write((char*)&m, sizeof(int));
	}

	void f1() {
		int* f1d;
		f1d = new int[N2 - N1 + 1];
		for (int i = N1; i <= N2; i++) {
			f1d[i - N1] = i * (i + 1) / 2;
		}
		dd.write((char*)f1d, sizeof(int) * (N2 - N1 + 1));
		delete f1d;
	}

	void f2() {
		float* f2d, x;
		x = x0;
		f2d = new float[m];
		for (int i = 0; i < m; i++) {
			f2d[i] = a * x + b;
			x += dx;
		}
		dd.write((char*)f2d, sizeof(float) * m);
		delete f2d;
		dd.close();
	}
};


int main() {
	LoL l1, l2, l3, l4;

	l1.N1 = 5;	l1.N2 = 10;
	l1.a = 2;	l1.b = 3;
	l1.x0 = -5;	l1.dx = 0.1;
	l1.m = 10;

	l2.N1 = 7;	l2.N2 = 100;
	l2.a = -3.5;	l2.b = 4;
	l2.x0 = 100;	l2.dx = 10;
	l2.m = 15;

	l3.N1 = 12;	l3.N2 = 17;
	l3.a = 0.01;	l3.b = 0.2;
	l3.x0 = 1.5;	l3.dx = 0.08;
	l3.m = 20;

	l4.N1 = 10;	l4.N2 = 20;
	l4.a = 4.2;	l4.b = -5.3;
	l4.x0 = 2.1;	l4.dx = 0.2;
	l4.m = 5;

	l1.f0("akali.dat");
	l1.f1();
	l1.f2();

	l2.f0("amumu.dat");
	l2.f1();
	l2.f2();

	l3.f0("annie.dat");
	l3.f1();
	l3.f2();

	l4.f0("ashe.dat");
	l4.f1();
	l4.f2();

	return 0;
}
