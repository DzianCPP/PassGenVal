#pragma once

#include "libs.h"
#include "records.h"

char startMenu();
void setRecordInfo(string& resource, string& login, char* password);
void setResource(string& resource);
void setLogin(string& login);
char setPasswordMenu();
bool validatePassword(char* password);
bool validatePasswordAuto(char* password);
char* setPasswordManually(char* password);
int setPasswordSize();
char* setPasswordAuto(char* password);
void readInfo(string filename, char* value, ifstream& fin);
void readInfo(string filename, string& value, ifstream& fin);
void readAllRecords(string filename, string& resource, string& login, char* password, records& Records);
