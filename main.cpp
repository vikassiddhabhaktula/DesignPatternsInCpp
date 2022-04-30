// std includes
#include <iostream>
#include <vector>
using namespace std;
// header includes
#include "printer.h"
#include "single_responsibility.h"

int main() {
    cout << "=======================\n";
    cout << "Let's design some code\n";
    cout << "=======================\n";
    /*  Solid design principles
     *  1. Single resposibility:
     *      -   Make sure that the class we design is subject to a single
     *          responsibility. Example, if we are forming a journal of
     *          daily activities, make sure the class just does the journal
     *          management and not the saving to file/ db etc., Keep that
     *          saving as another single responsibility class, that way the
     *          design can scale naturally.
     *  2.  Open but closed:
     *      -   Make sure that the class we create is open for scaling but
     *          closed for any changes in the base class. Instead derive
     *          something out of what is already there and scale it.
     */
    driverSingleResponsibility();
    return 0;
}