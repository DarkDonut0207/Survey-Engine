/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SurveyCreator.cpp
 * Author: Drake
 * 
 * Created on March 14, 2021, 9:26 PM
 */

#include "SurveyCreator.h"

SurveyCreator::SurveyCreator() {
    sze = 0; // Initialize size
}

//SurveyCreator::SurveyCreator(const SurveyCreator& orig) {
//}

SurveyCreator::~SurveyCreator() {
    delete sGroup;
}

void SurveyCreator::addSurvey() {
    Survey *group = new Survey[sze+1];
    string sName;
    string sDesc;
    string sOD;
    string sCD;
    int sNumIt;
    cout << "Input survey name: ";
    cin >> sName;
    cout << "Input survey description: ";
    cin.ignore();
    getline(cin, sDesc);
    cout << "Input survey opening date: ";
    cin >> sOD;
    cout << "Input survey close date: ";
    cin >> sCD;
    cout << "Input number of items in the survey: ";
    cin >> sNumIt;
    string *itm = new string[sNumIt];
    for (int i=0; i<sNumIt; i++) {
        cout << "Input name of item " << i+1 << ": ";
        cin >> itm[i];
    }
    Survey nSurv(sName, sDesc, sOD, sCD, itm);
    cout << "Test";
    for(int i=0; i<sze; i++) {
        group[i] = sGroup[i];
    }
    Survey *groupF = &group[sze];
    group[sze] = nSurv;
    sGroup = group;
    sze++;
}

void SurveyCreator::outputSurveyList(int indx) {
    if (indx<sze) {
        cout << "Survey: " << sGroup[indx].getName() << endl;
        cout << "     Item     |" << "   Vote Count    ";
        for (int i=0; i<sGroup[indx].getSize(); i++) {
            cout << sGroup[indx].getItem(i) << " | " << sGroup[indx].getVote(i);
        }
    }
}