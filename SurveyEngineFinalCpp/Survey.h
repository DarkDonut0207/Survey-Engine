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
#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// Questions are now stored in survey file under their survey, can remove question class
struct qStruct {
    string quest;
    vector<string> choices;   // List of choices
    int choCnt; // number of choices
};
struct uStruct {
    string email;
    vector<int> answers;   // List of questions
};
struct surStruc {
    string name;   // Name of the survey
    string desc;   // Description of the survey
    string dteOp; // Date the survey opens
    string dteClo;// Date the survey closes
    int qCount;   // Number of questions, used in reading the file
    int partCnt; // Number of participants who have taken the survey
    vector<qStruct> qList;   // List of questions
    vector<uStruct> userRes; // Results from the users
};
class Survey {
private:
    vector<surStruc> survList;
    ifstream sDataF;
    ofstream oSDataF;
    int sTotal; // Total number of surveys
public:   
    Survey();
    //Survey(const Survey& orig);
    ~Survey();
    /*
    int getTot() { return sTotal; } // Get the total number of surveys
    string getSName(int); // Get a specific survey's name
    string getDesc(int);
    string getDO(int);
    string getDC(int);
    int getSize(int);
    string getQName(int, int);
    int getVote(int);
     */
    
    // Modification
    void modSurvey(int);
    void createSurvey();
    void editPart(string, string); // Edit participant of a survey
    void viewSurveys(string, bool);
    void viewOneSurvey(int, string, bool);
    void takeSurvey(int, string);
    void viewSurveyResults(int);
    void pushSToFile();
};

#endif /* SURVEY_H */

