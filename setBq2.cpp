#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> calculateDerivative(const vector<int>& coefficients) {
    vector<int> derivative;
    int degree = coefficients.size() - 1;


    for (int i = 1; i <= degree; ++i) {
        derivative.push_back(coefficients[i] * i);
    }

    return derivative;
}


void printPolynomial(const vector<int>& coefficients) {
    int degree = coefficients.size() - 1;
    if (degree < 0) {
        cout << "0\n";
        return;
    }

    stringstream ss;
    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (i != degree) {
                ss << (coefficients[i] > 0 ? " + " : " - ");
            }
            if (i == 0 || coefficients[i] != 1 && coefficients[i] != -1) {
                ss << abs(coefficients[i]);
            }
            if (i > 0) {
                ss << "x";
                if (i > 1) {
                    ss << "^" << i;
                }
            }
        }
    }
    cout << ss.str() << endl;
}

int main() {
    const int maxDegree = 5;
    vector<int> coefficients(maxDegree + 1);

    cout << "Enter the coefficients of the polynomial from highest degree to constant term (up to degree 5):";


    for (int i = maxDegree; i >= 0; --i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }


    vector<int> derivative = calculateDerivative(coefficients);


    cout << "The derivative of the polynomial is: ";
    printPolynomial(derivative);

    return 0;
}
