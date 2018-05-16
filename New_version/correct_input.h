#pragma once

int cin_integer() { //обеспечивает правильный ввод целого числа
	string data;
	cin >> data;
	if (all_of(data.begin(), data.end(), [](char i) { return isdigit(i); }))
	{
		int a = stoi(data);
		return a;
	}
	else return -1;
}
void show_error() {
	cout << "Incorrect input. Therefore, it will be 1" << endl;
}

void show_incorrect_without() {
	cout << "Incorrect input" << endl;
}