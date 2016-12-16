#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <regex>

using namespace std;

class print_out {
	string str;

	public:
		void printabit(void);
};

void print_out::printabit(void) {
	cout << "Hey bob" << endl;
}

// class Control {
// 	private:
// 		Point m_position;
// 		Size m_size;
// }

// class Button : public Control {
// 	private:
// 		std::string m_label
// }

// class Slider : public Control {
// 	private:
// 		int m_minValue;
// 		int m_maxValue;
// 		int m_currentValue;
// }

string try_to_open_file(string filename) {
	ifstream file;
	file.exceptions(ifstream::failbit);
	try {
		file.open(filename.c_str());
		string content;
		content.assign((istreambuf_iterator<char>(file))
			, (istreambuf_iterator<char>()));
		file.close();
		return content;
	} catch (exception &e) {
		cout << "File does not exist" << endl;
		return "";
	}
}

bool is_correct_extension(string filename) {
	// Any filename with a .txt or .csv file extension
	regex target_extension("[0-9A-Za-z]+\\.?(txt|csv)");
	return regex_match(filename, target_extension);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: ./PCP <filename>" << endl;
		exit(EXIT_FAILURE);
	}
	if (!is_correct_extension(argv[1])) {
		cout << "Unable to parse file" << endl;
		exit(EXIT_FAILURE);
	}
	string contents = try_to_open_file(argv[1]);
	cout << "This is contents: " << contents;
	// CREATE MENU
	cout << "Done" << endl;
	return 0;
}
