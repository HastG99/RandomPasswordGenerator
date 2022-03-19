#include "RandomPasswordGenerator.h"

using namespace std;

const string lower = "abcdefghijklmnopqrstuvwxyz";
const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string numbers = "1234567890";
const string specific = "~!@#$%^&*()_+-=/";

string randomAlphabetic(int size);
string randomString(int size, string base);
string randomAlphaNumeric(int size);
string randomNumeric(int size);
string randomPassword(int size);



int main() {

	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int size;

	cout << "Введите длину пароля: ";

	cin >> size;

	cout << "Выберите режим: " << endl;

	cout << "\t0 - Только буквы.\n" << "\t1 - Только цифры.\n" << "\t2 - Цифры и буквы.\n" << "\t3 - Цифры, буквы и специальные символы.\n" << "> ";

	int mode;

	cin >> mode;

	switch (mode) {
	case 0:
		cout << randomAlphabetic(size) << endl;
		break;
	case 1:
		cout << randomNumeric(size) << endl;
		break;
	case 2:
		cout << randomAlphaNumeric(size) << endl;
		break;
	case 3:
		cout << randomPassword(size) << endl;
		break;
	default: cout << "Unknown mode" << endl;
	}

	#ifdef _WIN32 
		system("pause");
	#endif

}


string randomString(int size, string base) {

	string str = "";

	for (int i = 0; i < size; i++) {
		int random = rand() % base.length();

		str += base.at(random);
	}

	return str;

}

string randomAlphabetic(int size) {

	return randomString(size, lower + upper);

}

string randomAlphaNumeric(int size) {

	return randomString(size, lower + upper + numbers);

}

string randomNumeric(int size) {

	return randomString(size, numbers);

}

string randomPassword(int size) {

	return randomString(size, lower + upper + numbers + specific);

}