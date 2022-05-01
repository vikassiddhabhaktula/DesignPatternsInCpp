#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "printer.h"

//  Person object to capture name and id of the person
class Person {
    Person(const string& nameIn, const int& idIn) {
        name = nameIn;
        id = idIn;
    };
    friend class PersonFactory;
public:
    string name;
    int id;
};

//  Person object generator i.e. person factory  
class PersonFactory {
public:
    //  generates persons based on sequential id numbering
    Person create_person(const string& name)
    {
        // todo
        static int currId = 0;
        return Person{name, currId++};
    }
};

//  TODO: See if using Abstract factory this can be acheived

//  print spec for person
class PersonPrintSpec: public PrintSpec<Person *> {
    public:
        void printFun(Person *person) const {
            cout << "{name: " << person->name << "; id: " << person->id << "}";
        }
};

//  driverFactory
void driverFactory() {
    //  Create a factory
    PersonFactory personFactory;
    //  Create products (Persons) from the factory
    Person person1 = personFactory.create_person("SVR");
    Person person2 = personFactory.create_person("SL");
    Person person3 = personFactory.create_person("VS");
    Person person4 = personFactory.create_person("SS");
    Person person5 = personFactory.create_person("NS");
    vector<Person *> persons{
        &person1,
        &person2,
        &person3,
        &person4,
        &person5,
    };
    
    //  Create a printspec to print the products
    PersonPrintSpec personPrintSpec;
    Printer<PersonPrintSpec, Person *> printer(personPrintSpec);
    printer.print(persons, "persons from the factory are:");
}