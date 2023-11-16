#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LoL {
private:
    int N1, N2, m;
    float a, b, x0, dx;
    string filename;
    ofstream F;
    int* f1_res;
    float* f2_res;

public:
    LoL(int N1, int N2, float a, float b, float x0, float dx, int m, string filename) : N1(N1), N2(N2), a(a), b(b), x0(x0), dx(dx), m(m), filename(filename) {
        F.open(filename, ios::binary | ios::out);
        F.write((char*)&N1, sizeof(int));
        F.write((char*)&N2, sizeof(int));
        F.write((char*)&a, sizeof(float));
        F.write((char*)&b, sizeof(float));
        F.write((char*)&x0, sizeof(float));
        F.write((char*)&dx, sizeof(float));
        F.write((char*)&m, sizeof(int));

        f1_res = f1();
        F.write((char*)f1_res, sizeof(int) * (N2 - N1 + 1));
   
        f2_res = f2();
        F.write((char*)f2_res, sizeof(float) * m);

        F.close();
    }

    ~LoL() {
        delete[] f1_res;
        delete[] f2_res;
    }

    int* f1() {
        int* f1d;
        f1d = new int[N2 - N1 + 1];
        for (int i = N1; i <= N2; i++) {
            f1d[i - N1] = i * (i + 1) / 2;
        }
        return f1d;
    }

    float* f2() {
        float* f2d, x;
        f2d = new float[m];
        x = x0;
        for (int i = 0; i < m; i++) {
            f2d[i] = a * x + b;
            x += dx;
        }
        return f2d;
    }
};

int main() {
    LoL akali(5, 10, 2, 3, -5, 0.1, 10, "akali.dat");
    LoL amumu(7, 100, -3.5, 4, 100, 10, 15, "amumu.dat");
    LoL annie(12, 17, 0.01, 0.2, 1.5, 0.08, 20, "annie.dat");
    LoL ashe(10, 20, 4.2, -5.3, 2.1, 0.2, 5, "ashe.dat");
    return 33;
}
