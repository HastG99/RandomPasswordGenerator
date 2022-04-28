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

	typedef std::chrono::high_resolution_clock hiclock;

	setlocale(LC_ALL, "Russian");

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

	std::random_device dev;

	seed_seq seed
	{
		static_cast<long long>(std::chrono::high_resolution_clock::now()
								   .time_since_epoch()
								   .count()),

		static_cast<long long>(dev()),
		static_cast<long long>(dev()),
		static_cast<long long>(dev()),
		static_cast<long long>(dev()),
		static_cast<long long>(dev()),
		static_cast<long long>(dev()),

		static_cast<long long>(
			std::hash<std::thread::id>()(std::this_thread::get_id()))

	};

	mt19937 gen(seed);
	std::uniform_int_distribution<> dist(0, base.length() - 1);

	string str = "";

	for (int i = 0; i < size; i++) {
		int random = dist(gen);

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