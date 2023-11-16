#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream F("annie.dat", ios::binary | ios::in); 

    if (!F.is_open()) {
        cout << "File not open!" << endl;
        return 1;
    }

    int N1, N2, m;
    float a, b, x0, dx;

    F.read((char*)&N1, sizeof(int));
    F.read((char*)&N2, sizeof(int));
    F.read((char*)&a, sizeof(float));
    F.read((char*)&b, sizeof(float));
    F.read((char*)&x0, sizeof(float));
    F.read((char*)&dx, sizeof(float));
    F.read((char*)&m, sizeof(int));

    cout << "N1: " << N1 << endl;
    cout << "N2: " << N2 << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "x0: " << x0 << endl;
    cout << "dx: " << dx << endl;
    cout << "m: " << m << endl;


    int* f1d = new int[N2 - N1 + 1];
    F.read((char*)f1d, sizeof(int) * (N2 - N1 + 1));

    cout << "f1d: ";
    for (int i = 0; i < (N2 - N1 + 1); ++i) {
        cout << f1d[i] << " ";
    }
    cout << endl;


    float* f2d = new float[m];
    F.read((char*)f2d, sizeof(float) * m);

    cout << "f2d: ";
    for (int i = 0; i < m; ++i) {
        cout << f2d[i] << " ";
    }
    cout << endl;

    delete[] f1d;
    delete[] f2d;

    F.close();

    return 0;
}
