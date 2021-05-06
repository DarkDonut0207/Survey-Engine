/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Survey.cpp
 * Author: Drake
 * 
 * Created on March 14, 2021, 8:58 PM
 */

#include "Survey.h"

Survey::Survey() {
    
}

Survey::Survey(string sName, string sDesc, string sOD, string sCD, string* list) {
    name = sName;
    desc = sDesc;
    dteOp = sOD;
    dteClo = sCD;
    iList = list; // Store list of items
    sze = list->size(); // Store size of list
    iVotes = new int[sze]; // Allocate new dynamic array for votes list
    for (int i=0; i<sze; i++) iVotes[i] = 0;
}

//Survey::Survey(const Survey& orig) {
//}

Survey::~Survey() {
    delete iList;   // Delete dynamically allocated memory
    delete iVotes;
}

void Survey::addVote(int indx) {
    if (indx<sze) iVotes[indx]++; // Add a vote
}

string Survey::getItem(int indx) {
    if (indx<sze) return iList[indx];
}

int Survey::getVote(int indx) {
    if (indx<sze) return iVotes[indx];
}