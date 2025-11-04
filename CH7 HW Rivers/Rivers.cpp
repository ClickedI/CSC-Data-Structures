//Copyright 2025

#include "Rivers.h"
#include <list>
#include <string>
#include <iostream>



using std::string;
using std::list;
double Rivers::acid_level = 7.0;

Rivers::Rivers() :
    river_name(""),
    pH(0.0),
    DO(0.0)
{}

Rivers::~Rivers() {
    if (!rivers.empty()) {
        Rivers* river = rivers.back();
        rivers.pop_back();
        delete river;  // This triggers the destructor recursively
        this->~Rivers();  // Explicitly call destructor again
    }
}

Rivers::Rivers(string name, double ph, double DO, list<Rivers*> rivers)
    : river_name(name), pH(ph), DO(DO), rivers(rivers) {
}

const string& Rivers::getRiverName() const {
    return river_name;
}

void Rivers::setRiverName(const string& name) {
    river_name = name;
}

double Rivers::getPh() const {
    return pH;
}

void Rivers::setPh(double ph) {
    this->pH = ph;
}

double Rivers::getDo() const {
    return DO;
}

void Rivers::setDo(double DO) {
    this->DO = DO;
}

const list<Rivers*>& Rivers::getRivers() const {
    return rivers;
}

void Rivers::setRivers(const list<Rivers*> &rivers) {
    this->rivers = rivers;
}

void Rivers::make_river(Rivers *river) {
    rivers.push_back(river);
}

void Rivers::setAcidLevel(double acidLevel) {
    acid_level = acidLevel;
}


string Rivers::list_acidic_rivers() {
    string result = "";

    if (pH < acid_level) {
        result += river_name + " ";
    }

    result += list_acidic_tributaries(rivers.begin(), rivers.end());

    return result;
}

string Rivers::list_acidic_tributaries(list<Rivers*>::const_iterator begin,
                                       list<Rivers*>::const_iterator end) {

    if (begin == end) {
        return "";
    }

    string result = (*begin)->list_acidic_rivers();
    list<Rivers*>::const_iterator next = begin;
    ++next;
    result += list_acidic_tributaries(next, end);

    return result;
}

string Rivers::list_acidic_rivers(Rivers* river) {
    return river->list_acidic_rivers();
}

bool Rivers::unhealthy() {
    return bad_numbers(this) || unhealthy_trib(rivers.begin(), rivers.end());
}

bool Rivers::unhealthy(Rivers* river) {
    return river->unhealthy();
}
bool Rivers::unhealthy_trib(list<Rivers*>::const_iterator begin,
                            list<Rivers*>::const_iterator end) {
    if (begin == end) {
        return false;
    }

    if ((*begin)->unhealthy()) {
        return true;
    }
    list<Rivers*>::const_iterator next = begin;
    ++next;
    return unhealthy_trib(next, end);

}

bool Rivers::bad_numbers(Rivers* river) {
    if (river == nullptr) {
        return false;
    }
    return (river->pH < 6.5 || river->pH > 8.5 || river->DO < 6.0);
}

Rivers* Rivers::lower_all_ph() {
    list<Rivers*> newRivers = update_ph(rivers.begin(), rivers.end(), list<Rivers*>());
    return new Rivers(river_name, pH - 0.1, DO, newRivers);
}

Rivers* Rivers::lower_all_ph(Rivers* river, Rivers* newRivers) {
    return river->lower_all_ph();
}

list<Rivers*> Rivers::update_ph(list<Rivers*>::const_iterator begin,
                                list<Rivers*>::const_iterator end,
                                list<Rivers*> newRivers) {
if (begin == end) {
    return newRivers;
}

    newRivers.push_back((*begin)->lower_all_ph());
    list<Rivers*>::const_iterator next = begin;
    ++next;
    return update_ph(next, end, newRivers);
}

Rivers* Rivers::find_subsystem(string name) {
    if (river_name == name) {
        return this;
    }
    return find_in_list(rivers.begin(), rivers.end(), name);
}

Rivers* Rivers::find_subsystem(Rivers* river, string name) {
    return river->find_subsystem(name);
}

Rivers* Rivers::find_in_list(list<Rivers*>::const_iterator begin,
                             list<Rivers*>::const_iterator end,
                             string name) {
    if (begin == end) {
        return nullptr;
    }

   Rivers* found = (*begin)->find_subsystem(name);
    if (found != nullptr) {
        return found;
    }
    list<Rivers*>::const_iterator next = begin;
    ++next;
    return find_in_list(next, end, name);
}

void Rivers::print(Rivers* river, int level) {
    if (level > 0) {
        std::cout << "    ";
        print(river, level - 1);
    } else {
        std::cout << river->river_name << " (pH: " << river->pH
             << ", DO: " << river->DO << ")" << std::endl;
        river->print(river->rivers.begin(), river->rivers.end(), level + 1);
    }
}

void Rivers::print() {
    print(this, 0);
}


void Rivers::print(list<Rivers*>::const_iterator begin,
                  list<Rivers*>::const_iterator end,
                  int level) {

    if (begin == end) {
        return;
    }

    if (*begin != nullptr) {
        print(*begin, level);
    }

    list<Rivers*>::const_iterator next = begin;
    ++next;
    print(next, end, level);
}









