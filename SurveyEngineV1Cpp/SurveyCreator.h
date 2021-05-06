/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SurveyCreator.h
 * Author: Drake
 *
 * Created on March 14, 2021, 9:26 PM
 */

#ifndef SURVEYCREATOR_H
#define SURVEYCREATOR_H
#include "Survey.h"

class SurveyCreator {
private:
    Survey *sGroup;
    int sze;
public:
    SurveyCreator();
    //SurveyCreator(const SurveyCreator& orig);
    virtual ~SurveyCreator();
    void addSurvey();
    void outputSurveyList(int);
    void outputSurveyInfo();
};

#endif /* SURVEYCREATOR_H */