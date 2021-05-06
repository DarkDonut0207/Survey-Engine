/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Users.h
 * Author: Drake
 *
 * Created on April 18, 2021, 7:38 PM
 */

#ifndef USERS_H
#define USERS_H
#include <map>
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Users {
private:
    map<string, unsigned int> uMap; // A map holding the user emails and password
    map<string, unsigned int>::iterator uMapItr; // Iterator for user map
    map<string, unsigned int> aMap; // A map holding the admin emails and password
    map<string, unsigned int>::iterator aMapItr; // Iterator for admin map
    fstream dataFile;
    fstream adminDataFile;
public:
    Users();
    Users(const Users& orig);
    virtual ~Users();
    string login();
    bool adminLogin();
    void createU();
    string editE(string);
    void editP(string);
    unsigned int PswrdCnvrt(const string&);
    void outputU();
    void deleteU(string);
    void pushUToFile();
};

#endif /* USERS_H */

