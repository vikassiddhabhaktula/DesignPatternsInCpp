#include <iostream>
using namespace std;
#include "open-closed.h"
#include "printer.h"

//  Product constructor
Product::Product(const string& name, const Color& color, const Size& size) :
        _name(name), _color(color), _size(size) {
}

//  get the name of the product
string Product::getName() const {
    return _name;
}

//  get the color of the product
Color Product::getColor() const {
    return _color;
}

//  get the size of the product
Size Product::getSize() const {
    return _size;
}

//  Color contructor
template<typename T>
ColorSpec<T>::ColorSpec(Color color) : _color(color) {}

//  Color filter specification code
template<>
bool ColorSpec<Product>::isMatch(Product *item) const {
    return (item->getColor() == _color);
}

//  Size constructor
template<typename T>
SizeSpec<T>::SizeSpec(Size size) : _size(size) {}

//  Size filter spec code
template<>
bool SizeSpec<Product>::isMatch(Product *item) const {
    return (item->getSize() == _size);
}

//  And filter spec
template<typename T>
AndFilterSpec<T>::AndFilterSpec(Color color, Size size) :
        _color(color), _size(size) {
}

//  And filter spec
template<>
bool AndFilterSpec<Product>::isMatch(Product *item) const {
    return (item->getColor() == _color) && (item->getSize() == _size);
}

//  Filter code
template<>
vector<Product *> Filter<Product>::getFilteredItems(
        const vector<Product *>& allItems, const FilterSpec<Product>& spec) {
    vector<Product *> res;
    for (auto item: allItems) {
        if (spec.isMatch(item)) {
            res.push_back(item);
        }
    }
    return res;
}

//  product print spec constructor
ProductPrintSpec::ProductPrintSpec() {}

//  product print function
void ProductPrintSpec::printFun(Product *item) const {
    cout << item->getName();
}

//  driver to invoke open closed design test
void driverOpenClosed() {
    //  Introduce print spec
    ProductPrintSpec prodPrintSpec;
    Printer<ProductPrintSpec, Product> printer(prodPrintSpec);
    vector<Product *> prods = {
        new Product("bat", Color::blue, Size::small),
        new Product("mat", Color::green, Size::big),
        new Product("basket", Color::red, Size::big),
        new Product("ball", Color::red, Size::small),
        new Product("tree", Color::green, Size::big),
        new Product("frooti", Color::green, Size::small),
        new Product("shirt", Color::red, Size::small),
        new Product("jeans", Color::blue, Size::big),
    };
    //  print vectors of products
    printer.print(prods, "all products");
    //  Create a product filter
    Filter<Product> prodFilter;
    //  Define red color specification
    ColorSpec<Product> redFilter(Color::red);
    //  Define small size spec
    SizeSpec<Product> smallFilter(Size::small);
    //  Define green and big spec
    AndFilterSpec<Product> greenAndBigFilter(Color::green, Size::big);
    //  Filter the products using redFilter
    auto redItems = prodFilter.getFilteredItems(prods, redFilter);
    auto smallItems = prodFilter.getFilteredItems(prods, smallFilter);
    auto greenAndBigItems = prodFilter.getFilteredItems(prods, greenAndBigFilter);
    //  print the products
    printer.print(redItems, "red items");
    printer.print(smallItems, "small items");
    printer.print(greenAndBigItems, "green and big items");
}

