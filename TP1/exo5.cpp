// #include "tp1.h"
// #include <QApplication>
// #include <time.h>

// int isMandelbrot(Point z, int n, Point point){
//     // recursiv Mandelbrot

//     // check n

//     // check length of z
//     // if Mandelbrot, return 1 or n (check the difference)
//     // otherwise, process the square of z and recall
//     // isMandebrot
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow* w = new MandelbrotWindow(isMandelbrot);
//     w->show();

//     a.exec();
// }




#include <iostream>
#include <complex>

using namespace std;

int mandelbrot(complex<double> z, complex<double> point, int n) {
    if (abs(z) > 2) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        complex<double> zn = z*z + point;
        return mandelbrot(zn, point, n-1);
    }
}

int main() {
    complex<double> point(10, 5);
    int n_max = 1000;
    complex<double> z0(0, 0);
    if (mandelbrot(z0, point, n_max)) {
        cout << "Le point " << point << " appartient à l'ensemble de Mandelbrot." << endl;
    } else {
        cout << "Le point " << point << " n'appartient pas à l'ensemble de Mandelbrot." << endl;
    }
    return 0;
}
