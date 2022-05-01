#ifndef OPEN_CLOSED_H
#define OPEN_CLOSED_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "printer.h"

enum class Color {red, green, blue};
enum class Size {small, big};

//  Product class to capture product name, color and size
class Product {
    string _name;
    Color _color;
    Size _size;

    public:
        Product(const string& name, const Color& color, const Size& size);
        string getName() const;
        Color getColor() const;
        Size getSize() const;
};

//  Filter specification class: forms the specifiaction needed for filtering
template <typename T>
class FilterSpec {
    public:
        // Create a spec: strictly virtual function
        virtual bool isMatch(T* item) const = 0;
};

//  Color specification
template <typename T>
class ColorSpec: public FilterSpec<T> {
    Color _color;
    public:
        ColorSpec(Color color);
        // Color based spec
        bool isMatch(T* item) const;
};

//  Size specification
template <typename T>
class SizeSpec: public FilterSpec<T> {
    Size _size;
    public:
        SizeSpec(Size size);
        //  size based spec
        bool isMatch(T* item) const;
};

//  Product print spec
class ProductPrintSpec : public PrintSpec<Product *> {
    public:
        ProductPrintSpec();
        void printFun(Product *item) const;
};

//  Both Size & Color filter spec
template <typename T>
class AndFilterSpec: public FilterSpec<T> {
    Color _color;
    Size _size;
    public:
        AndFilterSpec(Color color, Size size);
        // size and color filter spec
        bool isMatch(T *item) const;
};

//  Filter for the products class, open for extension & closed for modification
template <typename T>
class Filter {
    public:
        //  Create filter by specifics: How to generalize this is the trick
        vector<T *> getFilteredItems(const vector<T *>& allItems,
                const FilterSpec<T>& spec);
};

void driverOpenClosed();

#endif