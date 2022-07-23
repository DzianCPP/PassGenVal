#pragma once

#include "libs.h"
#include "records.h"

char startMenu();
void setRecordInfo(string& resource, string& login, char* password);
void setResource(string& resource);
void setLogin(string& login);
char setPasswordMenu();
bool validatePassword(char* password,string mod);
char* setPasswordManually(char* password);
int setPasswordSize();
char* setPasswordAuto(char* password);
void readInfo(string filename, char* value, ifstream& fin);
bool readInfo(string filename, string& value, ifstream& fin);
bool readAllRecords(string filename, string& resource, string& login, char* password, records& Records);
