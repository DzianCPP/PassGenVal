#pragma once

#include "libs.h"

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