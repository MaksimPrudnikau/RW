#include "headers.h"
#include "Station.h"

//Удаляет пробелы из строки
string remSpaces(string input)
{
	int length = input.length();
	for (int i = 0; i < length; i++) {
		if (input[i] == ' ')
		{
			input.erase(i, 1);
			length--;
			i--;
		}
	}
	return input;
}

void Station::set_X(string& line) {
	X = stod(line.substr(59, 7));//Макс. длина = 11 символов.
	Y = stod(line.substr(82, 7));
	Z = stod(line.substr(105, 7));
}

void Station::set_th(string& line) {
	global_th = stod(line.substr(61, 5)); //то же самое, что для Х, так как позиция в строке одинаковая. Макс размер такой же
	if (line.substr(72, 2)=="ih") {
		ih = stod(line.substr(84, 5));
	}
}

void Station::set_Hz(string& line) {
	//(measVec[measVec.size() - 1]).Hz = stod(remSpaces(line.substr(24, 11)));
}

void Station::set_SD(string& line) {
	Meas meas;
	meas.code = remSpaces(line.substr(36, 10));
	meas.targetName = remSpaces(line.substr(36, 10));
	meas.SD = stod(remSpaces(line.substr(55, 10)));
	meas.Hz = stod(remSpaces(line.substr(79, 10)));
	meas.V2 = stod(remSpaces(line.substr(102, 10)));
	meas.th = global_th;
	measVec.push_back(meas);
	
}

void Station::set_T(string& line) {
	T = stod(remSpaces(line.substr(58, 8)));
	P = stod(remSpaces(line.substr(83, 6)));
	PC = stod(remSpaces(line.substr(104, 8)));
}

void Station::set_i(string& line) {
	i = stod(line.substr(60, 6));
	c = stod(line.substr(83, 6));
	SZ = stod(line.substr(106, 6));
}

void Station::set_Om(string& line) {
	Om = stod(line.substr(81, 8));
}

void Station::set_SK(string& line){
	SK = stod(line.substr(106, 6));
}

void Station::set_m(string& line) {
	m = stod(line.substr(58, 8));
}

void Station::set_s0(string& line) {
	s0 = stod(line.substr(106, 6));
}

void Station::set_vx(string& line) {
	vx = stod(remSpaces(line.substr(56, 10)));
	vy = stod(remSpaces(line.substr(79, 10)));
	vz = stod(remSpaces(line.substr(102, 10)));
}