#include <iostream>
#include <unordered_set>
using namespace std;
#include "dependency_inversion.h"
#include "printer.h"

//  Constructor for Person
Person::Person(const string& name) : _name(name) {}

//  get name of the person
string Person::getName() const {
    return _name;
}

//  Add family members and their relationships
void Family::addRelationship(const Person& person1, const Relation& relation, const Person&person2) {
    unordered_map<Relation, Relation> relationPair = {
        {Relation::child, Relation::parent},
        {Relation::parent, Relation::child},
        {Relation::nephew, Relation::inlaw},
        {Relation::inlaw, Relation::nephew},
        {Relation::sibling, Relation::sibling},
    };
    //  Push the given pair
    relationsDB[relation].push_back({person1, person2});
    //  If the other way exists, also push the other pair
    if (relationPair.find(relation) != relationPair.end()) {
        relationsDB[relationPair[relation]].push_back({person2, person1});
    }
}

//  get the stats by parsing the map
vector<Person> Family::getStats(const RelationSpec& spec) const {
    vector<Person> res;
    for (auto i: relationsDB) {
        //  first element/ key of a map is the relation
        if (spec.isMatch(i.first) == true) {
            unordered_map<string, bool> removeDups;
            //  Second element in the map is a vector of pairs
            for (auto vec: i.second) {
                Person *person = new Person(vec.first);
                //  push the first element of the pair if not already done
                if (removeDups[person->getName()] != true) {
                    res.push_back(*person);
                    removeDups[person->getName()] = true;
                }
                delete person;
            }
        }
    }
    return res;
}

//  Filter only parents
bool ParentSpec::isMatch(const Relation& relation) const {
    return (Relation::parent == relation);
}

//  Filter only children
bool ChildSpec::isMatch(const Relation& relation) const {
    return (Relation::child == relation);
}

//  Collect stats: num of children in the family
uint32_t CollectFamilyStats::getNumChildrenInFamily(const RelationshipStats& relationStats) const {
    return getChildren(relationStats).size();
}

//  Num of parents in the family
uint32_t CollectFamilyStats::getNumParentsInFamily(const RelationshipStats& relationStats) const {
    return getParents(relationStats).size();
}

//  get the vector of children
vector<Person> CollectFamilyStats::getChildren(const RelationshipStats& relationStats) const {
    ChildSpec childSpec;
    vector<Person> children = relationStats.getStats(childSpec);
    return children;
}

//  get the vector of children
vector<Person> CollectFamilyStats::getParents(const RelationshipStats& relationStats) const {
    ParentSpec parentSpec;
    vector<Person> parents = relationStats.getStats(parentSpec);
    return parents;
}

//  print spec of person object
void PersonPrintSpec::printFun(Person item) const {
    cout << item.getName();
}

void driverDependencyInversion() {
    //  Add a print spec
    PersonPrintSpec personPrintSpec;
    Printer<PersonPrintSpec, Person> printer(personPrintSpec);
    vector<Person> parents{Person("SS"), Person("SVR"), Person("SL")};
    vector<Person> children{Person("NS"), Person("VS")};
    Family family;
    //  Add all family members
    family.addRelationship(parents[0], Relation::parent, children[0]);
    family.addRelationship(parents[1], Relation::parent, parents[0]);
    family.addRelationship(parents[2], Relation::parent, parents[0]);
    family.addRelationship(parents[1], Relation::parent, children[1]);
    family.addRelationship(parents[2], Relation::parent, children[1]);
    family.addRelationship(parents[0], Relation::sibling, children[1]);
    family.addRelationship(children[0], Relation::nephew, children[1]);
    //  Collect the statistics
    CollectFamilyStats familyStats;
    dbgVal(familyStats.getNumChildrenInFamily(family), "num of children in the family");
    dbgVal(familyStats.getNumParentsInFamily(family), "num of parents in the family");
    auto parentsInFamily = familyStats.getParents(family);
    printer.print(parentsInFamily, "parents in the family are:");
    auto childrenInFamily = familyStats.getChildren(family);
    printer.print(childrenInFamily, "children in the family are:");
}