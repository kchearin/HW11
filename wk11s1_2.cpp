#include <iostream>
#include <fstream>
using namespace std;

class LoLCharacter {
private:
    int N1, N2, m;
    float a, b, x0, dx;
    int* f1Result;
    float* f2Result;

public:
    LoLCharacter(int N1, int N2, float a, float b, float x0, float dx, int m) : N1(N1), N2(N2), a(a), b(b), x0(x0), dx(dx), m(m) {}


    int* f1() {
        int* result = new int[N2 - N1 + 1];
        for (int i = N1; i <= N2; i++) {
            result[i - N1] = 0;
            for (int j = 0; j <= i; j++) {
                result[i - N1] += j;
            }
        }
        return result;
    }


    float* f2() {
        float* result = new float[m];
        float x = x0;
        for (int i = 0; i < m; i++) {
            result[i] = a * x + b;
            x += dx;
        }
        return result;
    }

    void saveToFile(string filename) {
        ofstream outFile(filename, ios::binary | ios::out);

        outFile.write(reinterpret_cast<const char*>(&N1), sizeof(N1));
        outFile.write(reinterpret_cast<const char*>(&N2), sizeof(N2));
        outFile.write(reinterpret_cast<const char*>(&a), sizeof(a));
        outFile.write(reinterpret_cast<const char*>(&b), sizeof(b));
        outFile.write(reinterpret_cast<const char*>(&x0), sizeof(x0));
        outFile.write(reinterpret_cast<const char*>(&dx), sizeof(dx));
        outFile.write(reinterpret_cast<const char*>(&m), sizeof(m));

        f1Result = f1();
        for (int i = 0; i < N2 - N1 + 1; i++) {
            outFile.write(reinterpret_cast<const char*>(&f1Result[i]), sizeof(int));
        }

        f2Result = f2();
        for (int i = 0; i < m; i++) {
            outFile.write(reinterpret_cast<const char*>(&f2Result[i]), sizeof(float));
        }

        outFile.close();
    }


    ~LoLCharacter() {
        delete[] f1Result;
        delete[] f2Result;
    }
};

int main() {
    LoLCharacter akali(5, 10, 2, 3, -5, 0.1, 10);
    akali.saveToFile("akali.dat");

    LoLCharacter amumu(7, 100, -3.5, 4, 100, 10, 15);
    amumu.saveToFile("amumu.dat");

    LoLCharacter annie(12, 17, 0.01, 0.2, 1.5, 0.08, 20);
    annie.saveToFile("annie.dat");

    LoLCharacter ashe(10, 20, 4.2, -5.3, 2.1, 0.2, 5);
    ashe.saveToFile("ashe.dat");

    return 0;
}
