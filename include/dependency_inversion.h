#ifndef DEPENDENCY_INVERSION_H
#define DEPENDENCY_INVERSION_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
#include "printer.h"

/*
 *  Let's create a relationships design where we capture various relationships
 *  those exist in a family. We will split it into LLModule and HLModule. Also,
 *  we will expose an interface defined in LLModule so that HLModule can use
 *  this.
 */

enum class Relation {
    parent,
    child,
    nephew,
    sibling,
    inlaw
};

class Person {
    string _name;
    public:
        Person(const string& name);
        //  Donot allow setname later
        string getName() const;
};

//  Interface to expose Person spec filter
class RelationSpec {
    public:
        virtual bool isMatch(const Relation& relation) const = 0;
};

//  Parent spec: Implements the interface spec for parent
class ParentSpec : public RelationSpec {
    public:
        bool isMatch(const Relation& relation) const;
};

//  Child spec: Implements the interface spec for parent
class ChildSpec : public RelationSpec {
    public:
        bool isMatch(const Relation& relation) const;
};

//  Sibling spec: Implements the interface spec for parent
class SiblingSpec : public RelationSpec {
    public:
        bool isMatch(const Relation& relation) const;
};

//  Nephew spec: Implements the interface spec for parent
class NephewSpec : public RelationSpec {
    public:
        bool isMatch(const Relation& relation) const;
};

//  Inlaw spec: Implements the interface spec for parent
class InlawSpec : public RelationSpec {
    public:
        bool isMatch(const Relation& relation) const;
};

//  Interface to expose relationships managed by LL module
class RelationshipStats {
    public:
        virtual vector<Person> getStats(const RelationSpec& personSpec) const = 0;
};

//  low level module/ concrete class that captures and manages relationships
class Family : public RelationshipStats {
    unordered_map<Relation, vector<pair<Person, Person>>> relationsDB;
    public:
        void addRelationship(const Person& person1, const Relation& relation,
                const Person& person2);
        vector<Person> getStats(const RelationSpec& personSpec) const;
};

//  high level module: To collect stats etc.,
//  TODO: Make this HLM also interface driven so that it is Open-Closed
class CollectFamilyStats {
    public:
        uint32_t getNumParentsInFamily(const RelationshipStats& relationStats) const;
        uint32_t getNumChildrenInFamily(const RelationshipStats& relationStats) const;
        vector<Person> getParents(const RelationshipStats& relationStats) const;
        vector<Person> getChildren(const RelationshipStats& relationStats) const;
};

//  spec to print the person product
class PersonPrintSpec: public PrintSpec<Person> {
    public:
        void printFun(Person item) const;
};

//  Driver to test dependency inversion concept
void driverDependencyInversion();

#endif