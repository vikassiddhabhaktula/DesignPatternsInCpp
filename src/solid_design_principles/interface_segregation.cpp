#include <iostream>
using namespace std;
#include <interface_segregation.h>

void OnlyPrinter::print(const string& device) {
    cout << "Printed to " << device << "\n";    
}

void OnlyScanner::scan(const string& device) {
    cout << "Scanned copy can be found on " << device << "\n";
}

void OnlyEmailer::email(const string& emailId) {
    cout << "Emailed to " << emailId << "\n";
}

void driverInterfaceSegregation() {
    ScannerPlusEmailer scanAndEmail;
    scanAndEmail.scan("Macbook Air");
    scanAndEmail.email("vikassiddhabhaktula@gmail.com");
    cout << "---\n";
}