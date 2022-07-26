#include "records.h"
#include "libs.h"

int records::getRecordsAmount() {
	return records_amount_;
}

records::records(void) {
	records_amount_ = 0;
	first_record_p_ = nullptr;
}

void records::pop_front() {
	Record* temp = this->first_record_p_;
	if (first_record_p_->next_record_ != nullptr) {
		this->first_record_p_ = first_record_p_->next_record_;
	}
	delete temp;
	records_amount_--;
}

void records::clear() {
	while (records_amount_) {
		pop_front();
	}
}

records::~records(void) {
	clear();
}

void records::push_back(string login, string resource, char* password) {
	if (first_record_p_ == nullptr) {
		first_record_p_ = new Record(login, resource, password);
	}

	else if (first_record_p_ != nullptr) {
		Record* this_record = this->first_record_p_;
		while (this_record->next_record_ != nullptr) {
			this_record = this_record->next_record_;
		}
		this_record->next_record_ = new Record(login, resource, password);
		this_record = this_record->next_record_;
	}

	records_amount_++;
}

void records::pop_back() {
	Record* this_record = this->first_record_p_;
	while (this_record->next_record_ != nullptr) {
		this_record = this_record->next_record_;
	}

	delete this_record;
	records_amount_--;
}

void records::push_front(string login, string resource, char* password) {
	Record* new_record = new Record(login, resource, password);
	new_record->next_record_ = first_record_p_;
	first_record_p_ = new_record;
	records_amount_++;
}

void records::edit_record(string login, string resource, char* password, int index, string mod) {
	Record* edited_record = this->first_record_p_;
	int counter = 0;
	while (counter != index - 1) {
		edited_record = edited_record->next_record_;
		counter++;
	}

	if (mod == "login") {
		edited_record->login = login;
	}

	else if (mod == "password") {
		for (int i = 0; i < strlen(password); i++) {
			edited_record->password[i] = password[i];
		}
	}
	
	else if (mod == "resource") {
		edited_record->resource = resource;
	}
}

void records::remove(int index) {
	Record* toRemove = this->first_record_p_;
	Record* prev = this->first_record_p_;
	int counter = 0;
	while (counter != index - 1) {
		toRemove = toRemove->next_record_;
		counter++;
	}

	counter = 0;
	while (counter != index - 2) {
		prev = prev->next_record_;
		counter++;
	}

	prev->next_record_ = toRemove->next_record_;

	delete toRemove;
	prev = nullptr;
	records_amount_--;
}

void records::printRecord(string all) {
	Record* toPrint = this->first_record_p_;
	int count = { 1 };
	for (; ;count++) {
		cout << "Resource: " << toPrint->resource << endl <<
			"Login: " << toPrint->login << endl <<
			"Password: " << toPrint->password << endl <<
			"Number: " << count << endl << endl;

		toPrint = toPrint->next_record_;
		if (toPrint == nullptr) {
			break;
		}
	}
}

void records::printRecord(Record& record) {
	int count = { 1 };
	for (; ; count++) {
		cout << "Resource: " << record.resource << endl <<
			"Login: " << record.login << endl <<
			"Password: " << record.password << endl <<
			"Number: " << count << endl << endl;
	}
}

void records::printRecord(int index) {
	int counter = 0;
	Record* toPrint = this->first_record_p_;
	if (index == 1) {
		cout << "Resource: " << toPrint->resource << endl <<
			"Login: " << toPrint->login << endl <<
			"Password: " << toPrint->password << endl << endl;
	}

	else if (index > 1) {
		while (counter < index) {
			toPrint = toPrint->next_record_;
			counter++;
		}
		cout << "Resource: " << toPrint->resource << endl <<
			"Login: " << toPrint->login << endl <<
			"Password: " << toPrint->password << endl << endl;
	}
}

void showRecords(string& filename, ifstream& fin) {
	fin.open(filename, ifstream::in);
	if (fin.is_open()) {
		char ch{};
		while (fin.eof()) {
			fin >> ch;
			cout << ch;
		}
	}

	else {
		std::system("cls");
		cout << "Error! There is no file with any records or no records were made yet." << endl << endl;
	}

	fin.close();
}

void records::saveToFileAll(string filename) {
	ofstream fout(filename, ios_base::binary);
	if (!fout.is_open()) { cout << "Error! No file!" << endl; }

	else {
		Record* toPrint = this->first_record_p_;
		if (toPrint->next_record_ == nullptr) {
			fout << toPrint->resource << endl <<
				toPrint->login << endl <<
				toPrint->password << endl;
		}
		
		else {
			for (; ;) {
				fout << toPrint->resource << endl <<
					toPrint->login << endl <<
					toPrint->password << endl;

				if (toPrint->next_record_ != nullptr) {
					toPrint = toPrint->next_record_;
				}

				else {
					break;
				}
			}
		}
	}

	fout.close();
}

void records::saveToFileOne(string filename) {
	ofstream fout(filename, ofstream::app);
	if (!fout.is_open()) { cout << "Error! No file!" << endl; }

	else {
		Record* toPrint = this->first_record_p_;
		if (toPrint->next_record_ == nullptr) {
			fout << toPrint->resource << endl <<
				toPrint->login << endl <<
				toPrint->password << endl;
		}

		else {
			for (; ;) {
				fout << toPrint->resource << endl <<
					toPrint->login << endl <<
					toPrint->password << endl;

				if (toPrint->next_record_ != nullptr) {
					toPrint = toPrint->next_record_;
				}

				else {
					break;
				}
			}
		}
	}

	fout.close();
}