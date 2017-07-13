/*
 * PostalCode Parser
 * Copyright (C) 2016  Author: Elliott Sobek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cstdlib>
#include <regex>

#include "menu.hpp"

using namespace std;

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
		cerr << "File does not exist: " << e.what() << endl;
		exit(EXIT_FAILURE);
	}
}

bool is_correct_extension(string filename) {
	// Any filename with a .txt or .csv file extension
	regex target_extension("([0-9A-Za-z]\\w+)\\.?(txt|csv)");
	return regex_match(filename, target_extension);
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "Usage: ./PCP <filename>" << endl;
		exit(EXIT_FAILURE);
	}
	if (!is_correct_extension(argv[1])) {
		cerr << "Unable to parse file" << endl;
		exit(EXIT_FAILURE);
	}
	string contents = try_to_open_file(argv[1]);
	main_menu();
	return 1;
}
