/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Drake
 *
 * Created on March 14, 2021, 3:18 AM
 */

#include <cstdlib>
#include "SurveyCreator.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SurveyCreator ballot;
    ballot.addSurvey();
    ballot.outputSurveyList(0);
    return 0;
}

