// std includes
#include <iostream>
#include <vector>
using namespace std;
// header includes
#include "printer.h"
#include "single_responsibility.h"
#include "open-closed.h"
#include "interface_segregation.h"
#include "dependency_inversion.h"

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
     *          something out of what is already there and scale it. Use of
     *          specifications as a product filter instead of changing the
     *          product filter itself.
     *  3.  Liskov subsitution:
     *      -   The idea is the places where base class is used should be
     *          easily replaced with derived class reference, and there
     *          shouldn't be any break in functionality. TODO: square derived
     *          from rectangle.
     *  4.  Interface segregation:
     *      -   Always make sure the interfaces exposed for implementation
     *          are not too big. It will be easier to maintain and also to
     *          code and then stich together smaller interfaces to form the
     *          design.
     *  5.  Dependency inversion concept:
     *      -   When there are high level modules and low level modules in
     *          the design, make sure that the high level modules don't
     *          depend on low level modules directly. Instead, they should
     *          depend on interfaces, so that any future implementation
     *          changes in the low level module will not impact the high level
     *          modules. Use an interface and the definition in the low level
     *          design. And then use the magic of polymorphism to get a hold
     *          of that interface function in the high level module.
     */
    driverSingleResponsibility();
    driverOpenClosed();
    driverInterfaceSegregation();
    driverDependencyInversion();
    return 0;
}