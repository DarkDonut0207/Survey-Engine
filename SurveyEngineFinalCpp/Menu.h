/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: Drake
 *
 * Created on April 4, 2021, 7:15 PM
 */

#ifndef MENU_H
#define MENU_H
#include "Users.h"
#include "Survey.h"
class Menu: public Survey, public Users {
private:
    bool cont;
    string curUser;
    bool isAdmin;
public:
    Menu();
    //Menu(const Menu& orig);
    ~Menu();
    //bool ReturnCheck();
    int userLogin();
    int userMenu();
    int adminMenu();
    int adminLoginMenu();
    int userAccount();
    void promptSave();
};

#endif /* MENU_H */

