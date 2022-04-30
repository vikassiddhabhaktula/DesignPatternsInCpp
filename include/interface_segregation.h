#ifndef INTERFACE_SEGREGATION_H
#define INTERFACE_SEGREGATION_H

#include <iostream>
using namespace std;

/*  Interface is nothing but an abstract class
 *  Abstract class (ABC) is a class from which the objects cannot be created
 *  If there is atleast one pure virtual function, it becomes an ABC
 */

//  Design a printer, scanner and faxer and combinations
//  Interface for print alone
class IPrint {
    public:
        virtual void print(const string& device) = 0;
};

//  Interface for scan alone
class IScan {
    public:
        virtual void scan(const string& device) = 0;
};

//  Interface for email alone
class IMail {
    public:
        virtual void email(const string& emailId) = 0;
};

class OnlyPrinter: public IPrint {
    public:
        void print(const string& device);
};

class OnlyScanner: public IScan {
    public:
        void scan(const string& device);

};

class OnlyEmailer: public IMail {
    public:
        void email(const string& emailId);
};

class ScannerPlusEmailer: public OnlyEmailer, public OnlyScanner {
};

//  driver for interface segregation
void driverInterfaceSegregation();

#endif