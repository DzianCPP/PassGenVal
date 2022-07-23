#pragma once

#include "records.h"
#include "libs.h"

class records {
private:
	class Record {
	public:
		Record* next_record_;
		string login{};
		string resource{};
		char* password{};

		Record(string login, string resource, char* password, Record* next_record_ = nullptr) {
			this->login = login;
			this->resource = resource;
			this->password = password;
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
	void edit_record(string login, string resource, char* password, int index);
	void remove(int index);
	void printRecord(string all);
	void printRecord(int index);
	void printRecord(Record& record);
	int idBuilder();

	void saveToFileAll(string filename);

private:

	int records_amount_;
	Record* first_record_p_;
};