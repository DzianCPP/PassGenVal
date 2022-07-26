#pragma once

#ifndef _RECORDS_H_
#define _RECORDS_H_

#include "records.h"
#include "libs.h"

class records {
private:
	class Record {
	public:
		Record* next_record_;
		string login{};
		string resource{};
		char password[17]{};

		Record(string login, string resource, char* password, Record* next_record_ = nullptr) {
			this->login = login;
			this->resource = resource;
			for (int i = 0; i < strlen(password); i++) {
				this->password[i] = password[i];
			}
			this->next_record_ = next_record_;
		}
	};
public:
	~records();
	records();

	int getRecordsAmount();
	void push_back(string login, string resource, char* password);
	void push_front(string login, string resource, char* password);
	void clear();
	void pop_front();
	void pop_back();
	void edit_record(string login, string resource, char* password, Record& record, string mod);
	bool remove(int index);
	bool printRecord(string all);
	void printRecord(int index);
	void printRecord(Record& record);
	bool saveToFileAll(string filename);
	void saveToFileOne(string filename);
	Record& findRecords(string keyword);

private:

	int records_amount_;
	Record* first_record_p_;
};

#endif