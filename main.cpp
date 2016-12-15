#include <iostream>
#include <fstream>
#include <string>
#include <exception>

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
	cout << "This is filename: " << filename << endl;
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

int main(void) {
	cout << "Start" << endl;
	// GET USER INPUT FROM COMMAND LINE

	// ofstream file;
	// file.open("test.txt");
	// file << "Write to file\n";
	// file.close();
	string contents = try_to_open_file("tes.txt");
	cout << "This is contents: " << contents;
	cout << "Done" << endl;
	return 0;
}
