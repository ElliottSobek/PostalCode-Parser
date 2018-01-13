/*
 * PostalCode Parser
 * Copyright (C) 2016  Author: Elliott Sobek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int get_user_input(void) {
	cout << "Enter a menu option: ";
	int input;
	cin >> input;
	return input;
}

bool is_valid_bounds(const int input, const int upperbound, const int lowerbound) {
	return ((input <= upperbound) && (input >= lowerbound));
}

void print_menu(void) {
	cout << "1. General stats\n"
			"2. WIP\n"
			"3. WIP\n"
			"4. WIP\n"
			"0. Exit" << endl;
}

void main_menu(void) {
	int input;

	while (1) {
		print_menu();
		input = get_user_input();

		while (!is_valid_bounds(input, 4, 0)) {
			cout << "Invalid menu option" << endl;
			print_menu();
			input = get_user_input();
		}
		switch(input){
		case 1:
			cout << "Success" << endl;
			// output_general_stats();
			break;
		case 2:
			cout << "Success" << endl;
			break;
		case 3:
			cout << "Success" << endl;
			break;
		case 4:
			cout << "Success" << endl;
			break;
		case 0:
			exit(EXIT_SUCCESS);
		}
	}
}
