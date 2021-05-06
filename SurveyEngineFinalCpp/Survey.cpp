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
    string gName;   // Name of the survey
    string gDesc;   // Description of the survey
    string gDteOp; // Date the survey opens
    string gDteClo;// Date the survey closes
    string gUser;
    vector<uStruct> gUserRes; // Results from the users
    vector<qStruct> gQList;   // List of questions
    int gQCount;
    int gPartCnt;
    string gQName; // Given question name
    int gCCount; // Given choice count
    int surIndx = 0;
   
    sDataF.open("surveyData.dat");

    while(!sDataF.eof()) {
        if (surIndx>0) sDataF.ignore(2);
        getline (sDataF,gName);
        if (!gName.empty() && gName[gName.size() - 1] == '\r') {
            gName.erase(gName.size() - 1);
        }
        getline (sDataF,gDesc);
        if (!gDesc.empty() && gDesc[gDesc.size() - 1] == '\r') {
            gDesc.erase(gDesc.size() - 1);
        }
        getline (sDataF,gDteOp);
        if (!gDteOp.empty() && gDteOp[gDteOp.size() - 1] == '\r') {
            gDteOp.erase(gDteOp.size() - 1);
        }
        getline (sDataF,gDteClo);
        if (!gDteClo.empty() && gDteClo[gDteClo.size() - 1] == '\r') {
            gDteClo.erase(gDteClo.size() - 1);
        }
        sDataF >> gQCount; // Read in the questions, starting with how many
        for(int i=0; i<gQCount; i++) {
            qStruct gQStru; // A question
            sDataF.ignore(2);
            getline (sDataF,gQName);
            if (!gQName.empty() && gQName[gQName.size() - 1] == '\r') {
            gQName.erase(gQName.size() - 1);
            }
            sDataF >> gCCount;
            for(int i=0; i<gCCount; i++) {
                string tempVar;
                sDataF >> tempVar;
                gQStru.choices.push_back(tempVar);
            }
            
            gQStru.quest = gQName;
            gQStru.choCnt = gCCount;
            gQList.push_back(gQStru);
            gQStru.choices.clear();
        }
        sDataF >> gPartCnt;
        for(int i=0; i<gPartCnt; i++) {
            uStruct gUsrStru;
            sDataF >> gUser; // store the email
            for(int i=0; i<gQCount; i++) {
                int tempVar;
                sDataF >> tempVar;
                gUsrStru.answers.push_back(tempVar);
            }
            gUsrStru.email = gUser;
            gUserRes.push_back(gUsrStru);
            gUsrStru.answers.clear();
        }
        surStruc gSurStru;
        gSurStru.name = gName;
        gSurStru.desc = gDesc;
        gSurStru.dteOp = gDteOp;
        gSurStru.dteClo = gDteClo;
        gSurStru.qCount = gQCount;
        gSurStru.userRes = gUserRes;
        gSurStru.qList = gQList;
        gSurStru.partCnt = gPartCnt;
        survList.push_back(gSurStru); // Push back the list
        gUserRes.clear(); // Clear vector content
        gQList.clear();
        surIndx++;
    }
    sTotal = surIndx;
    sDataF.close();
}


//Survey::Survey(const Survey& orig) {
//}

Survey::~Survey() {
}
/*
string Survey::getSName(int indx) {
    return survList[indx].name;
}
string Survey::getDesc(int indx) {
    return survList[indx].desc;
}
string Survey::getDO(int indx) {
    return survList[indx].dteOp;
}
string Survey::getDC(int indx) {
    return survList[indx].dteClo;
}
int Survey::getSize(int indx) {
    return survList[indx].qCount;
}
string Survey::getQName(int indx, int qIndx) {
    return this->survList[indx].qList[qIndx].quest;
}
 */

/*
int Survey::getVote(int indx) {
   // if (indx<sze) return iVotes[indx];
    return 1;
}
 */

void Survey::createSurvey() {
    int test;
    string tmpNm;
    string tmpDsc;
    string tmpOD;
    string tmpCD;
    string queNm;
    string tmpCho;
    int gQCount = 0;
    int tmpCC;
    vector<qStruct> tQList;   // List of questions
    surStruc gSurStru;
    int cont = 1;
    cout << "***Create Survey Menu***\n";
    cin >> test;
    cout << "What is the survey name: \n";
    cin.ignore();
    getline(cin,tmpNm);
    cout << "What is the description for this survey: \n";
    getline(cin,tmpDsc);
    cout << "What is the opening date: \n";
    getline(cin,tmpOD);
    cout << "What is the closing date: \n";
    getline(cin,tmpCD);
    do {
        qStruct gQStru; // A question
        gQCount++;
        cout << "What is the question: \n";
        getline(cin,queNm);
        cout << "How many choices are with this question: ";
        cin >> tmpCC;
        for (int i=0; i<tmpCC; i++) {
            cout << "What is choice #" << i+1 << ": ";
            cin >> tmpCho;
            gQStru.choices.push_back(tmpCho);
        }
        cout << "\n(1) Add question\n(2) Finish\nEnter Choice: ";
        cin >> cont;
        cin.ignore();
        gQStru.quest = queNm;
        gQStru.choCnt = tmpCC;
        tQList.push_back(gQStru);
        gQStru.choices.clear();
    } while (cont==1);
    gSurStru.name = tmpNm;
    gSurStru.desc = tmpDsc;
    gSurStru.dteOp = tmpOD;
    gSurStru.dteClo = tmpCD;
    gSurStru.qCount = gQCount;
    gSurStru.qList = tQList;
    gSurStru.partCnt = 0;
    survList.push_back(gSurStru); // Push back the list
    sTotal++;
}
void Survey::modSurvey(int indx) {
    int incre = 0;
    int choice = 0;
    int cInc = 0;
    int modMode = 1;
    int qModMode = 1; 
    int qIndx;
    string queNm;
    int tmpCC;
    string tmpCho;
    char charInp;
    indx = indx-1;
    vector<surStruc>::iterator sIt;
    if(indx<sTotal && indx >= 0) {
        cout << "Modification modes:\n(1) Modify Survey\n(2) Delete Survey\n";
        cout << "(3) Return to menu\nInput a modification mode: ";
        cin >> modMode;
        while (modMode < 1 || modMode > 3) {
            cout << "Invalid modification mode, reinput: ";
            cin >> modMode;
        }

        if (modMode == 1) {
            do  {
                cout << "Editing Survey: " << survList[indx].name << endl;
                cout << "(1) Change Name\n";
                cout << "(2) Change Description\n";
                cout << "(3) Change Opening Date\n";
                cout << "(4) Change Closing Date\n";
                cout << "(5) Add/Modify/Remove a Question (Note: this will";
                cout << " reset all participants of the survey)\n";
                cout << "(6) Exit Modify Survey Menu\n";
                cout << "Enter choice: ";
                cin >> choice;
                while (choice > 6 || choice < 1) {
                    cout << "Invalid choice, re-enter: ";
                    cin >> choice;
                }
                string gName;
                string gDesc;
                string gDteOp;
                string gDteClo;
                switch (choice) {
                    case 1:
                        cout << "Enter a new name for the survey: \n";
                        cin.ignore();
                        getline(cin, gName);
                        survList[indx].name = gName;
                        break;
                    case 2:
                        cout << "Enter a new description for the survey: \n";
                        cin.ignore();
                        getline(cin, gDesc);
                        survList[indx].desc = gDesc;
                        break;
                    case 3:
                        cout << "Enter a new opening date for the survey: \n";
                        cin.ignore();
                        getline(cin, gDteOp);
                        survList[indx].dteOp = gDteOp;
                        break;
                    case 4:
                        cout << "Enter a new closing date for the survey: \n";
                        cin.ignore();
                        getline(cin, gDteClo);
                        survList[indx].dteClo = gDteClo;
                        break;
                    case 5:
                        incre = 0;
                        for (auto i = survList[indx].qList.begin(); i!= survList[indx].qList.end(); i++) {
                            cout << "#" << ++incre << ": " << i->quest << endl;
                            cInc = 0;
                            for (auto j = i->choices.begin(); j!= i->choices.end(); j++) {
                                cout << "\t(" << ++cInc << ") " << *j << endl;
                            }
                        }
                        cout << "Modification modes:\n(1) Modify Question\n(2) Delete Question\n";
                        cout << "(3) Add Question\nInput a modification mode: ";
                        cin >> modMode;
                        while (modMode < 1 || modMode > 3) {
                            cout << "Invalid modification mode, reinput: ";
                            cin >> modMode;
                        }
                        if (modMode == 1) {
                            cout << "Enter a question number to modify: ";
                            cin >> choice;
                            qIndx = choice-1;
                            while (choice < 0 || choice > survList[indx].qCount) {
                                cout << "Invalid question choice, enter a ";
                                cout << "question # or 0 to return: ";
                                cin >> choice;
                            } if (choice > 0) {
                                cout << "Change question prompt? (y/n)";
                                cin >> charInp;
                                if (charInp == 'y') {
                                    cout << "Input a new question prompt: \n";
                                    cin.ignore();
                                    getline(cin, queNm);
                                    survList[indx].qList[qIndx].quest = queNm;
                                }
                                cout << "Change choices? (y/n)";
                                cin >> charInp;
                                while (charInp == 'y') {
                                    cout << "(1) Add choice\n";
                                    cout << "(2) Delete choice";
                                    cout << "Enter choice: ";
                                    cin >> choice;
                                    if (choice==1) {
                                        cout << "\nEnter choice: ";
                                        cin >> tmpCho;
                                        survList[indx].qList[qIndx].choices.push_back(tmpCho);
                                        survList[indx].qList[qIndx].choCnt = survList[indx].qList[qIndx].choCnt+1;
                                    } else if (choice==2) {
                                        cout << "Enter choice to delete: ";
                                        cin >> choice;
                                        if (choice <1 || choice > survList[indx].qList[qIndx].choCnt) {
                                            cout << "Invalid choice to modify.";
                                        } else {
                                            auto cItr = survList[indx].qList[qIndx].choices.begin();
                                            for (int i=0; i< choice-1; i++) {
                                                cItr++;
                                            }
                                            survList[indx].qList[qIndx].choices.erase(cItr);
                                        }
                                    }
                                    cout << "Change choices? (y/n)";
                                    cin >> charInp;
                                }
                                survList[indx].userRes.clear();
                            }
                        } else if (modMode == 2) {
                            cout << "Enter a question number to delete: ";
                            cin >> choice;
                            while (choice < 0 || choice > survList[indx].qCount) {
                                cout << "Invalid question choice, enter a ";
                                cout << "question # or 0 to return: ";
                                cin >> choice;
                            } if (choice > 0) {
                                qIndx = choice-1;
                                auto qInc = survList[indx].qList.begin();
                                for (int i=0; i<qIndx; i++) {
                                    qInc++;
                                }
                                survList[indx].qList.erase(qInc);
                                survList[indx].qCount = survList[indx].qCount-1;
                                survList[indx].userRes.clear();
                            }
                        } else if (modMode == 3) {
                            survList[indx].qCount = survList[indx].qCount+1;
                            qStruct gQStru; // A question
                            cout << "What is the question: \n";
                            cin.ignore();
                            getline(cin,queNm);
                            cout << "How many choices are with this question: ";
                            cin >> tmpCC;
                            for (int i=0; i<tmpCC; i++) {
                                cout << "What is choice #" << i+1 << ": ";
                                cin >> tmpCho;
                                gQStru.choices.push_back(tmpCho);
                            }
                            gQStru.quest = queNm;
                            gQStru.choCnt = tmpCC;
                            survList[indx].qList.push_back(gQStru);
                            gQStru.choices.clear();
                            survList[indx].userRes.clear();
                        }
                        
                        break;
                }
            } while (choice!=6);
        } else if (modMode == 2) {
            cout << "Deleting Survey: " << survList[indx].name << endl;
            for (int i=0; i<indx; i++) {
                sIt++;
            }
            survList.erase(sIt);
            sTotal--;
        }
    }
}

void Survey::editPart(string user, string newUser) {
    // Iterate through the survey list
    for (auto i = survList.begin(); i != survList.end(); i++) {
        for (auto j = i->userRes.begin(); j!= i->userRes.end(); j++) {
            if (j->email == user) {
                if (newUser!="\0")
                    j->email = newUser; // modify
                else i->userRes.erase(j); // delete44
            }
        }
    }
    cout << endl;
}

void Survey::viewSurveys(string user, bool isAdmin){
    bool comp;
    string tName;
    string tDesc;
    int inc = 0;
    if(!isAdmin) {
        cout << "   #   Survey Name   |          Description         |";
        cout << " # Qs | Start Date | Close Date |    Status    |\n" << fixed;
        for (auto i = survList.begin(); i != survList.end(); i++) {
            inc++;
            comp = false;
            tName = i->name;
            tDesc = i->desc;
            if (tName.length() > 16) {
                tName =  tName.substr(0, 13) + "...";
            }
            if (tDesc.length() > 29) {
                tDesc =  tDesc.substr(0, 26) + "...";
            }
            cout << setw(4) << inc << setw(16) << tName << " |" << setw(29);
            cout << tDesc << " |" << setw(5) << i->qCount << " |" << setw(11);
            cout << i->dteOp << " |" << setw(11) << i->dteClo << " |";
            cout << setw(13);
            for (auto j = i->userRes.begin(); j!= i->userRes.end(); j++) {
                if (j->email == user) {
                    comp = true;
                } 
            } 
            if (comp) cout << "Taken" << " |\n";
            else cout << "Not Started" << " |\n";
        }
    } else {
        cout << "   #   Survey Name   |          Description         |";
        cout << " # Qs | Start Date | Close Date | # Taken |\n";
        for (auto i = survList.begin(); i != survList.end(); i++) {
            inc++;
            comp = false;
            tName = i->name;
            tDesc = i->desc;
            if (tName.length() > 16) {
                tName =  tName.substr(0, 13) + "...";
            }
            if (tDesc.length() > 29) {
                tDesc =  tDesc.substr(0, 26) + "...";
            }
            //setw(16)
            cout << setw(4) << inc << setw(16) << tName << " |" << setw(29);
            cout << tDesc << " |" << setw(5) << i->qCount << " |" << setw(11);
            cout << i->dteOp << " |" << setw(11) << i->dteClo << " |";
            cout << setw(8) << i->partCnt << " |" << endl;
        }
    }
}
void Survey::viewOneSurvey(int indx, string user, bool isAdmin) {
    indx = indx-1;
    if(indx<sTotal && indx >= 0) {
        cout << "Survey Name: " << survList[indx].name << endl;
        cout << "Description: " << survList[indx].desc << endl;
        cout << "# of Questions: " << survList[indx].qCount << endl;
        cout << "Start Date: " << survList[indx].dteOp << endl;
        cout << "Close Date: " << survList[indx].dteClo << endl;
        if (!isAdmin) {
            bool comp = false;
             for (auto j = survList[indx].userRes.begin(); j!= survList[indx].userRes.end(); j++) {
                if (j->email == user) {
                    comp = true;
                } 
            }
            if (comp) cout << "Status: Taken\n";
            else cout << "Status: Not Started\n";
        } else {
            cout << "Amount completed: " << survList[indx].partCnt;
        }
    } else cout << "Invalid survey selected.\n";
}

void Survey::takeSurvey(int indx, string user) {
    indx = indx-1;
    int inc = 0;
    int choice;
    bool comp = false;
    uStruct tmpStruct;
    for (auto j = survList[indx].userRes.begin(); j!= survList[indx].userRes.end(); j++) {
        if (j->email == user) {
           comp = true;
       }
    }
    if(indx<sTotal && indx >= 0 && !comp) {
        tmpStruct.email = user;
        for (auto i = survList[indx].qList.begin(); i!= survList[indx].qList.end(); i++) {
            inc++;
            int cInc = 0;
            cout << "#" << inc << ": " << i->quest << endl;
            for (auto j = i->choices.begin(); j!= i->choices.end(); j++) {
                cInc++;
                cout << "\t(" << cInc << ") " << *j << endl;
            }
            cout << "Input choice: ";
            cin >> choice;
            while (choice < 1 || choice > cInc) {
                cout << "Invalid choice, input choice: ";
                cin >> choice;
            }
            tmpStruct.answers.push_back(choice);
        }
        survList[indx].userRes.push_back(tmpStruct);
        survList[indx].partCnt = survList[indx].partCnt+1;
    } else if (comp) {
        cout << "This survey was already taken.\n";
    }
    /*
    for (auto i = survList[indx].userRes.begin(); i!= survList[indx].userRes.end(); i++) {
        cout << i->email << " ";
        for (auto j= i->answers.begin(); j!=i->answers.end(); j++) {
            cout << *j << " ";
        }
    }
     */
}
void Survey::viewSurveyResults(int indx) {
    indx = indx-1;
    int inc = 0;
    vector<int> qRes;
    if(indx<sTotal && indx >= 0) {
        for (auto i = survList[indx].qList.begin(); i!= survList[indx].qList.end(); i++) {
            for (int j=0; j<i->choCnt; j++) {
                qRes.push_back(0);
            }
            
            for (auto j = survList[indx].userRes.begin(); j!= survList[indx].userRes.end(); j++) {
                int temp = j->answers[inc] - 1;
                qRes[temp] = qRes[temp] + 1;
            }
            cout << "Question #" << inc+1 << ": " << i->quest << endl;
            for (int j=0; j<i->choCnt; j++) {
                cout << "(" << j+1 << "): " << i->choices[j];
                cout << " **Votes: " << qRes[j] << endl;
            }
            qRes.clear();
            inc++;
        }
    }
}
void Survey::pushSToFile() {
    int sItr = 0;
    int pItr = 0;
    int itr = 0;
    vector<surStruc>::iterator survItr;
    vector<qStruct>::iterator qItr;   
    vector<uStruct>::iterator userItr; 
    vector<string>::iterator choItr;  
    vector<int>::iterator ansItr;  
    std::ofstream surveyOF;
    surveyOF.open ("surveyData.dat", ofstream::trunc);
    for(survItr = survList.begin(); survItr != survList.end(); ++survItr) {
        sItr++;
        surveyOF << survItr->name << endl << survItr->desc << endl;
        surveyOF << survItr->dteOp << endl << survItr->dteClo << endl;
        surveyOF << survItr->qCount << endl;
        for(qItr = survItr->qList.begin(); qItr != survItr->qList.end(); ++qItr) {
            surveyOF << qItr->quest << endl << qItr->choCnt;
            for(choItr = qItr->choices.begin(); choItr != qItr->choices.end(); ++choItr) {
                surveyOF << " " << *choItr;
            }
            surveyOF << endl;
        }
        surveyOF << survItr->partCnt;
        if (survItr->partCnt > 0) surveyOF << endl;
        pItr = 0;
        for(userItr = survItr->userRes.begin(); userItr != survItr->userRes.end(); ++userItr) {
            pItr++;
            surveyOF << userItr->email << endl;
            itr = 0;
            for(ansItr = userItr->answers.begin(); ansItr != userItr->answers.end(); ++ansItr) {
                itr++;
                surveyOF << *ansItr;
                if (itr < survItr->qCount) surveyOF << " ";
            }
            if (pItr < survItr->partCnt) surveyOF << endl;
        }
        if(sItr < sTotal) surveyOF << endl;
    }
    surveyOF.close();
}