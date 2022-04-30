#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>
using namespace std;

//  print a whole vector/string etc.,
template<typename T>
void dbgVec(const T& args, const string& label = "") {
    if ("" != label) {
        cout << label << ":\n";
    }
    //  Print vals
    for (auto i: args) {
        cout << i << ", ";
    }
    cout << "\n---\n";
}

//  print a single value
template<typename T>
void dbgVal(const T& args, const string& label = "") {
    if ("" != label) {
        cout << label << ":\n";
    }
    cout << args;
    cout << "\n---\n";
}

#endif