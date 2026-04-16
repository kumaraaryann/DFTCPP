#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <fstream>   // for file output

using namespace std;

int main() {
    int N = 8; // number of samples
    vector<double> x = {1,1,1,1,0,0,0,0}; // input signal
    vector<complex<double>> X(N);

    // Compute DFT
    for (int k = 0; k < N; k++) {
        complex<double> sum(0,0);
        for (int n = 0; n < N; n++) {
            double angle = -2.0 * M_PI * k * n / N;
            sum += x[n] * complex<double>(cos(angle), sin(angle));
        }
        X[k] = sum;
    }

    // Print to console
    cout << "DFT Output:" << endl;
    for (int k = 0; k < N; k++) {
        cout << "k=" << k << " : " << X[k] << endl;
    }

    // Save to CSV file
    ofstream fout("output.csv");
    fout << "Index,Real,Imag\n"; // header row
    for (int k = 0; k < N; k++) {
        fout << k << "," << X[k].real() << "," << X[k].imag() << "\n";
    }
    fout.close();
}