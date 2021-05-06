/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: Drake
 * 
 * Created on April 4, 2021, 7:15 PM
 */

#include "Menu.h"

Menu::Menu() {
    cont = true;
    isAdmin = false;
    curUser = "\0";
    int choice;
    string newUser;
    string inUser;
    //this->editPart("dfafard2@student.rccd.edu", "\0");
    cout << "Run in:\n(1): Administrator\n(2): User\nEnter choice: ";
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> choice;
    
    while (choice<1 || choice>2) {
                cout << "This is an invalid choice, re-enter choice: ";
                cin >> choice;
                
            }
    if (choice==1) {
        
        while (cont) {
            if (!isAdmin) {
                choice = this->adminLoginMenu();
                if (choice == 1) {
                    isAdmin = this->adminLogin();
                } if (choice == 2) {
                    cont = false;
                }
            } else {
                choice = this->adminMenu();
                if (choice == 1) {
                    this->outputU();
                    cout << "Input a user to modify/delete: ";
                    cin >> inUser;
                    cout << "(1) Edit Username\n(2) Edit Password\n(3) ";
                    cout << "Delete User\n(4) Return to menu\n";
                    cout << "Enter choice: ";
                    cin >> choice;
                    while (choice < 1 || choice > 4) {
                        cout << "Invalid choice, re-enter: ";
                        cin >> choice;
                    }
                    if (choice==1) {
                        this->editE(inUser);
                    } else if (choice==2) {
                        this->editP(inUser);
                    } else if (choice==3) {
                        this->deleteU(inUser);
                    }
                } else if (choice == 2) {
                    this->viewSurveys(curUser, isAdmin);
                    cout << "Input a survey to view/modify the info of.\n";
                    cout << "Input 0 to return to admin menu.\n";
                    cout << "Enter choice: ";
                    cin >> choice;
                    if (choice!=0) {
                        this->viewOneSurvey(choice,curUser,isAdmin);
                        this->modSurvey(choice);
                    }
                } else if (choice == 3) {
                    this->viewSurveys(curUser, isAdmin);
                    cout << "Input a survey to view the results of.\n";
                    cout << "Input 0 to return to admin menu.\n";
                    cout << "Enter choice: ";
                    cin >> choice;
                    if (choice!=0) {
                        this->viewSurveyResults(choice);
                    }
                } else if (choice == 4) {
                    isAdmin = false;
                } else if (choice == 5) {
                    cont = false;
                }
            }
        }
    } else if (choice==2) {
        isAdmin = false;
        while (cont) {
            if (curUser=="\0") { // If the user is not logged in
                choice = this->userLogin();
                if (choice==1) {
                    curUser = this->login();
                } else if (choice==2) {
                    this->createU();
                } else {
                    cont = false;
                }
            } else { // If the user is logged in
                choice = this->userMenu();
                if (choice==1) {
                    this->viewSurveys(curUser, isAdmin);
                    cout << "Input a survey to view the info of.\n";
                    cout << "Input 0 to return to user menu.\n";
                    cout << "Enter choice: ";
                    cin >> choice;
                    if (choice!=0) {
                        char charInp;
                        this->viewOneSurvey(choice,curUser,isAdmin);
                        cout << "\nTake survey #" << choice << "? (y/n)";
                        cin >> charInp;
                        if (charInp == 'y') {
                            this->takeSurvey(choice,curUser);
                        }
                    } 
                } else if (choice==2) {
                    // View account details
                    choice = this->userAccount();
                    if (choice==1) {
                        newUser = this->editE(curUser);
                        if(newUser!="\0") {
                            this->editPart(curUser, newUser);
                            curUser = newUser;
                        }
                    } else if (choice==2) {
                        this->editP(curUser);
                    } else if (choice>=4) cont = false;
                } else if (choice==3) {
                    cout << "Reset";
                    curUser = "\0";
                } else {
                    cont = false; // Exit
                }
            }
           
            
            
            /*
            cout << "***User Menu***" << endl;
            cout << "(1): Create Survey";
            cout << "(2): Take Survey";
            cout << "Enter choice: ";
            cin >> choice;
            while (choice >2 || choice <1) {
                cout << "This is an invalid choice, re-enter choice: ";
                cin >> choice;
            }
            if (choice==1) {
                // Call create survey functions
                this->addSurvey();
                cont = this->ReturnCheck();
            }
            if (choice==2) {
                // Call take/display survey functions
                this->ballotSelect();
                cont = this->ReturnCheck();
            }
            cout << "LOOP";*/
        }
    }  
    this->promptSave();
}

//Menu::Menu(const Menu& orig) {
//}

Menu::~Menu() {
}

/*
bool Menu::ReturnCheck() {
    int choice;
    cout << "\nReturn to menu (1) or end program (2): ";
    cin >> choice;
    while (choice >2 || choice <1) {
        cout << "This is an invalid choice, re-enter choice: ";
        cin >> choice;
    }
    if (choice==1) {
        cout << "true";
        return true;
    }
    else {
        cout << "false";
        return false;
    }
}

 */
int Menu::userLogin() {
    int choice;
    cout << "\n***Login Menu***\n" << endl;
    cout << "(1): Login\n";
    cout << "(2): Create Account\n";
    cout << "(3): Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    while (choice <1 || choice > 3) {
    cout << "This is an invalid choice, re-enter choice: ";
    cin >> choice;
    }
    return choice;
}
int Menu::userMenu() {
    int choice;
    cout << "\n***User Menu***\n" << endl;
    cout << "(1): View Survey List\n";
    cout << "(2): View/Edit Account Details\n";
    cout << "(3): Logout\n";
    cout << "(4): Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    while (choice <1 || choice > 4) {
    cout << "This is an invalid choice, re-enter choice: ";
    cin >> choice;
    return choice;
    } 
}

int Menu::userAccount() {
    int choice;
    cout << "\n***Account Menu***\n";
    cout << "User Email: " << curUser;
    cout << "\n(1): Edit Email\n";
    cout << "(2): Edit Password\n";
    cout << "(3): Return to User Menu\n";
    cout << "(4): Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    while (choice < 1 || choice > 4) {
        cout << "This is an invalid choice, re-enter choice: ";
        cin >> choice;
    }
    return choice;
}
int Menu::adminMenu() {
    int choice;
    cout << "\n***Administrator Menu***\n";
    cout << "\n(1): View Users\n";
    cout << "(2): View Surveys\n";
    cout << "(3): View Survey Results\n";
    cout << "(4): Logout\n";
    cout << "(5): Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    while (choice < 1 || choice > 5) {
        cout << "This is an invalid choice, re-enter choice: ";
        cin >> choice;
    }
    return choice;
}
int Menu::adminLoginMenu() {
    int choice;
    cout << "\n***Admin Login Menu***\n" << endl;
    cout << "(1): Login\n";
    cout << "(2): Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    while (choice <1 || choice > 2) {
    cout << "This is an invalid choice, re-enter choice: ";
    cin >> choice;
    }
    return choice;
}
void Menu::promptSave() {
    char choice;
    cout << "\nSave session to file? (y/n): ";
    cin >> choice;
    if (choice=='y') {
        this->pushUToFile();
        this->pushSToFile();
        cout << "Saving and exiting";
    } else cout << "Exiting without saving.";
}