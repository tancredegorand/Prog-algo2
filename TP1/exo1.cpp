/*#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

long power(long value, long n)
{
    Context _("power", value, n); // do not care about this, it allow the display of call stack

    // your code
    // return_and_display shows the result in the window and returns it
    return_and_display(1);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new PowerWindow(power); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}

*/
#include <iostream>
using namespace std;

long power(long value, long n){
    if (n==0){
        return 1; 
    }
    return value*power(value, n-1); 

}


int main(){
    cout << power(2,3) << endl; 

    return 0; 
}