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

//  use printer class below to print objects
//  print spec class which defines the object specific print function
template <typename T>
class PrintSpec {
    public:
        virtual void printFun(T item) const = 0;
};

//  Printer class to print objects: K is the spec, T is the data type
//  Currently only supports vector of pointers to objects
//  TODO: vector of objects, vector of vals, vals alone
template <typename K, typename T>
class Printer {
    K _spec;
    public:
        Printer(const K& spec) : _spec(spec) {};
        void print(const vector<T>& allItems, const string& label = "") {
            if ("" != label) {
                cout << label << ":\n";
            }
            for (auto item: allItems) {
                _spec.printFun(item);
                cout << ", ";
            }
            cout << "\n---\n";
        }
};

#endif