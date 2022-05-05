#include <iostream>
#include <string>
#include <memory>
#include <ostream>
using namespace std;
#include "prototype.h"
#include "printer.h"

/*
 *  Let us design an employee prototype class which can be used to create
 *  employees. And then can be later used to customize employees.
 */
//  Implementation using employee prototype factory and smart pointers
class Address {
    public:
        uint32_t cubicle;
        string street;
        string city;

        //  Constructor
        Address(const uint32_t& cubicle, const string& street, const string &city)
            :   cubicle(cubicle), street(street), city(city) {};
        //  Copy constructor
        Address(const Address& other) : cubicle(other.cubicle), street(other.street),
            city(other.city) {};
};

class Employee {
    //  Constructor
    Employee(const string& name, Address* address) :
        name(name), address(address) {};
    public:
        string name;
        Address *address;
        //  Copy Constructor TODO: Make this private
        Employee(const Employee& other) :
            name(other.name), address(new Address{*other.address}) {};
        ~Employee() {
            delete address;
        }
        //  Overload streaming operator
        friend ostream& operator<<(ostream& cout, const Employee& other) {
            cout << "Name: " << other.name << "; Address: " << other.address->cubicle << ", "
                <<  other.address->street << ", " << other.address->city << ";";
            return cout;
        }
        //  Create employee factory
        class EmployeeFactory {
            static unique_ptr<Employee> createEmployee(const string &name, const uint32_t& cubicle,
                    const Employee& prototypeEmployee) {
                        auto employeePtr = make_unique<Employee>(prototypeEmployee);
                        employeePtr->name = name;
                        employeePtr->address->cubicle = cubicle;
                        return employeePtr; 
                    }
            public:
                static unique_ptr<Employee> addNewEmployee(const string& name, const uint32_t& cubicle) {
                    //  call a factory method
                    static Employee prototypeEmployee{"", new Address{0, "Mahadevapura", "Bangalore"}};
                    return createEmployee(name, cubicle, prototypeEmployee);
                }
        };
};

class EmployeePrintSpec: public PrintSpec<Employee> {
    public:
        void printFun(Employee employee) const {
            cout << employee;
        }
};

//  Point exercise
struct Point {
    int x{ 0 }, y{ 0 };

    Point(){}

    Point(const int x, const int y) : x{x}, y{y} {}
    Point(const Point& other) : x(other.x), y(other.y) {}
};

struct Line {
    Point *start, *end;

    Line(Point* const start, Point* const end) : start(start), end(end)    {}

    ~Line() {
        delete start;
        delete end;
    }

    Line deep_copy() const {
        return Line{new Point{*start}, new Point{*end}};
    }
};

void driverPrototypePattern() {
    EmployeePrintSpec employeePrintSpec;
    Printer<EmployeePrintSpec, Employee> printer{employeePrintSpec};
    auto emp1 = Employee::EmployeeFactory::addNewEmployee("VS", 203);
    auto emp2 = Employee::EmployeeFactory::addNewEmployee("SS", 102);
    printer.print({*emp1, *emp2}, "Employees in the company are:");
}