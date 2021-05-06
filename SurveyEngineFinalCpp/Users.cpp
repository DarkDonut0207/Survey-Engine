/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Users.cpp
 * Author: Drake
 * 
 * Created on April 18, 2021, 7:38 PM
 */

#include "Users.h"

Users::Users() {
    string email;
    unsigned int encPswrd;
    dataFile.open("userData.dat");
    adminDataFile.open("adminData.dat");
    while(!dataFile.eof()) {
        dataFile >> email;
        dataFile >> encPswrd;
        uMap.insert(pair<string,unsigned int>(email, (encPswrd)));
    }
    while(!adminDataFile.eof()) {
        adminDataFile >> email;
        adminDataFile >> encPswrd;
        aMap.insert(pair<string,unsigned int>(email, (encPswrd)));
    }
    dataFile.close();
    adminDataFile.close();
}

Users::Users(const Users& orig) {
}

Users::~Users() {
}
bool Users::adminLogin() {
    string email;
    string pswrd;
    unsigned int encPswrd;
    bool success = false;
    int choice = 2;
    do {
        choice = 2;
        cout << "Input Email: ";
        cin >> email;
        cout << "Input password: ";
        cin >> pswrd;
        while (pswrd.length()>40) {
            cout << "Password is too long, re-input: ";
            cin >> pswrd;
        }
        encPswrd = PswrdCnvrt(pswrd);
        pswrd = "\0";
        aMapItr = aMap.find(email);
        if (aMapItr==aMap.end()) {
            cout << "Email and password do not match.\n";
            cout << "(1): Re-enter info\n(2): Exit to login menu\nEnter Choice:";
            cin >> choice;
        } else if (aMapItr->second != encPswrd) {
            cout << "Email and password do not match.\n";
            cout << "(1): Re-enter info\n(2): Exit to login menu\nEnter Choice:";
            cin >> choice;
        } else success = true;
    }while (choice == 1);
    if (success) return true;
    else return false;
}
string Users::login() {
    string email;
    string pswrd;
    unsigned int encPswrd;
    bool success = false;
    int choice = 2;
    do {
        choice = 2;
        cout << "Input Email: ";
        cin >> email;
        cout << "Input password: ";
        cin >> pswrd;
        while (pswrd.length()>40) {
            cout << "Password is too long, re-input: ";
            cin >> pswrd;
        }
        encPswrd = PswrdCnvrt(pswrd);
        pswrd = "\0";
        uMapItr = uMap.find(email);
        if (uMapItr==uMap.end()) {
            cout << "Email and password do not match.\n";
            cout << "(1): Re-enter info\n(2): Exit to user menu\nEnter Choice:";
            cin >> choice;
        } else if (uMapItr->second != encPswrd) {
            cout << "Email and password do not match.\n";
            cout << "(1): Re-enter info\n(2): Exit to user menu\nEnter Choice:";
            cin >> choice;
        } else success = true;
    }while (choice == 1);
    if (success) return uMapItr->first;
    else return "\0";
}

void Users::createU() {
    string email;
    string pswrd;
    string cnfPswrd;
    int choice = 1;
    unsigned int encPswrd;
    cout << "Input Email: ";
    cin >> email;
    do {
    cout << "Create password (max of 40 characters): ";
    cin >> pswrd;
    while (pswrd.length()>40) {
        cout << "Password is too long, re-input: ";
        cin >> pswrd;
    }
    cout << "Confirm password: ";
    cin >> cnfPswrd;
    if (cnfPswrd!=pswrd) cout << "Password does not match with confirmation.\n";
    } while (cnfPswrd!=pswrd);
    encPswrd = PswrdCnvrt(pswrd);
    pswrd = "\0";
    cnfPswrd = "\0";
    uMapItr = uMap.find(email);
    
    if (uMapItr == uMap.end()) { // Make sure that the email isnt already used
        uMap.insert(pair<string,unsigned int>(email, (encPswrd)));
        cout << "\nAccount created successfully.";
    } else {
        while (uMapItr != uMap.end() && choice == 1) {
            cout << "That email is already associated with an account.\n";
            cout << "(1): Re-enter email\n(2): Exit to user menu\nEnter Choice:";
            cin >> choice;
            if (choice==1) {
                cout << "Input Email: ";
                cin >> email;
                uMapItr = uMap.find(email);
            }
        }
        if (choice==1) {
            uMap.insert(pair<string,unsigned int>(email, (encPswrd)));
            cout << "\nAccount created successfully.";
        }
    }
}
string Users::editE(string gUser) {
    string inEmail;
    int choice = 1;
    unsigned int encPswrd;
    cout << "Input new email: ";
    cin >> inEmail;
    uMapItr = uMap.find(inEmail);
    if (uMapItr == uMap.end()) { // Make sure that the email isnt already used
        uMapItr = uMap.find(gUser);
        encPswrd = uMapItr->second;
        uMap.erase(gUser);
        uMap.insert(pair<string,unsigned int>(inEmail, (encPswrd)));
        cout << "\nAccount email changed successfully.";
        return inEmail;
    } else {
        while (uMapItr != uMap.end() && choice == 1) {
            cout << "That email is already associated with an account.\n";
            cout << "(1): Re-enter email\n(2): Exit to user menu\nEnter Choice:";
            cin >> choice;
            if (choice==1) {
                cout << "Input Email: ";
                cin >> inEmail;
                uMapItr = uMap.find(inEmail);
            }
        }
        if (choice==1) {
            //uMap.insert(pair<string,unsigned int>(email, (encPswrd)));
            uMapItr = uMap.find(gUser);
            encPswrd = uMapItr->second;
            uMap.erase(gUser);
            uMap.insert(pair<string,unsigned int>(inEmail, (encPswrd)));
            cout << "\nAccount email changed successfully.";
            return inEmail;
        } else return "\0";
    }
}
void Users::editP(string gUser) {
    string pswrd;
    string cnfPswrd;
    unsigned int encPswrd;
    
    uMapItr = uMap.find(gUser);
    do {
    cout << "Create new password (max of 40 characters): ";
    cin >> pswrd;
    while (pswrd.length()>40) {
        cout << "Password is too long, re-input: ";
        cin >> pswrd;
    }
    cout << "Confirm password: ";
    cin >> cnfPswrd;
    if (cnfPswrd!=pswrd) cout << "Password does not match with confirmation.\n";
    } while (cnfPswrd!=pswrd);
    encPswrd = PswrdCnvrt(pswrd);
    pswrd = "\0";
    cnfPswrd = "\0";
    uMap[gUser] = encPswrd;
    //uMap.insert(pair<string,unsigned int>(gUser, (encPswrd)));
}
unsigned int Users::PswrdCnvrt(const string& str) {
    // Initialize variables
    unsigned int hash = static_cast<unsigned int>(str.length());
    for (int i=0; i<str.length(); i++) { // Loop through string
        // Compute hash
        hash = ((hash << 5) ^ (hash >> 27)) ^ str[i];
    }
    return hash; // Return value
}
void Users::outputU() {
    cout << "User List:\n";
    for(uMapItr = uMap.begin(); uMapItr != uMap.end(); ++uMapItr) {
        cout << uMapItr->first << endl;
    }
}
void Users::deleteU(string user) {
    uMapItr = uMap.find(user);
    if (uMapItr != uMap.end()) {
        cout << "User " << uMapItr->first << " deleted.";
        uMap.erase(uMapItr);
    } else cout << "User not found.";
}
void Users::pushUToFile() {
    std::ofstream userOF;
    userOF.open ("userData.dat", ofstream::trunc);
    for(uMapItr = uMap.begin(); uMapItr != uMap.end(); ++uMapItr) {
        userOF << uMapItr->first << ' ' << uMapItr->second << endl;
    }
    userOF.close();
}