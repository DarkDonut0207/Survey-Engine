/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Survey.h
 * Author: Drake
 *
 * Created on March 14, 2021, 8:58 PM
 */

#ifndef SURVEY_H
#define SURVEY_H
#include <string>
#include <iostream>
using namespace std;
class Survey {
private:
    string *iList; // List of items in the survey
    int *iVotes;   // List of votes for the items 
    int sze;       // Size of list
    string name;   // Name of the survey
    string desc;   // Description of the survey
    string dteOp; // Date the survey opens
    string dteClo;// Date the survey closes
public:   
    Survey(string, string, string, string, string*);
    Survey();
    //Survey(const Survey& orig);
    ~Survey();
    void addVote(int);
    string getName() {return name;}
    string getDesc() {return desc;}
    string getDO() {return dteOp;}
    string getDC() {return dteClo;}
    string getItem(int);
    int getSize() {return sze;}
    int getVote(int);
};

#endif /* SURVEY_H */

