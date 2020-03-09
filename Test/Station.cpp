#include "headers.h"
#include "Station.h"

const int
NAME_POS = 22, //позици€ дл€ имен
FIRST_ROW_POS = 53, // перва€ колонка
SECOND_ROW_POS = 76, //втора€ колонка
THIRD_ROW_POS = 99; // трет€€ колонка


//”дал€ет пробелы из строки
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

//считывание дл€ имен
string ReadTargetName(string line,int pos)
{
	string target_name;
	for (int i = pos; line[i] != '|'; ++i)
		if (line[i]!=' ')
			target_name.push_back(line[i]);
	return target_name;
}

//считывание дл€ чисел
double ReadMeas(string line, int pos)
{
	string target;
	for (int i = pos; line[i] != '|'; ++i)
		if ((int)line[i] >= 48 && (int)line[i] <= 57 || (int)line[i] == 46) // если  0 <= line[i] <= 9 или line[i] == .
			target.push_back(line[i]);
	return stod(target);
}

void Station::set_X(string& line) {
	name = ReadTargetName(line, NAME_POS);
	X = ReadMeas(line, FIRST_ROW_POS);
	Y = ReadMeas(line, SECOND_ROW_POS);
	Z = ReadMeas(line, THIRD_ROW_POS);
	T = global_T;
	ih = global_ih;
	P = global_P;
	PC = global_PC;
	i = global_i;
	c = global_c;
	SZ = global_SZ;
	Om = global_Om;
	SK = global_SK;
	m = global_m;
	S0 = global_S0;
	vx = global_vx;
	vy = global_vy;
	vz = global_vz;
}

void Station::set_X(string& line, vector<Station>& measVec) {
	measVec.back().measVec.back().X = ReadMeas(line, FIRST_ROW_POS);
	measVec.back().measVec.back().Y = ReadMeas(line, SECOND_ROW_POS);
	measVec.back().measVec.back().Z = ReadMeas(line, THIRD_ROW_POS);
}

void Station::set_th(string& line) {
	global_th = ReadMeas(line, FIRST_ROW_POS); //то же самое, что дл€ ’, так как позици€ в строке одинакова€. ћакс размер такой же
	if (line.substr(72, 2)=="ih") {
		global_ih = ReadMeas(line, SECOND_ROW_POS);
	}
}

void Station::set_Hz(string& line) {
	//(measVec[measVec.size() - 1]).Hz = stod(remSpaces(line.substr(24, 11)));
}

void Station::set_SD(string& line) {
	Meas meas;
	meas.code = ReadTargetName(line,NAME_POS); ///„то брать за код символа??
	meas.targetName = ReadTargetName(line, NAME_POS);
	meas.SD = ReadMeas(line, FIRST_ROW_POS);
	meas.Hz = ReadMeas(line, SECOND_ROW_POS);
	meas.V2 = ReadMeas(line, THIRD_ROW_POS);
	meas.th = global_th;
	measVec.push_back(meas);
}

void Station::set_T(string& line) {
	global_T = ReadMeas(line, FIRST_ROW_POS);
	T = global_T;
	global_P = ReadMeas(line, SECOND_ROW_POS);
	P = global_P;
	global_PC = ReadMeas(line, THIRD_ROW_POS);
	PC = global_PC;
}

void Station::set_i(string& line) {
	global_i = ReadMeas(line, FIRST_ROW_POS);
	i = global_i;
	global_c = ReadMeas(line, SECOND_ROW_POS);
	c = global_c;
	global_SZ = ReadMeas(line, THIRD_ROW_POS);
	SZ = global_SZ;
}

void Station::set_Om(string& line) {
	global_Om = ReadMeas(line, SECOND_ROW_POS);
	Om = global_Om;
}

void Station::set_SK(string& line){
	global_SK = ReadMeas(line, THIRD_ROW_POS);
	SK = global_SK;
}

void Station::set_m(string& line) {
	global_m = ReadMeas(line, FIRST_ROW_POS);
	m = global_m;
}

void Station::set_s0(string& line) {
	global_S0 = ReadMeas(line, THIRD_ROW_POS);
	S0 = global_S0;
}

void Station::set_vx(string& line) {
	global_vx = ReadMeas(line, FIRST_ROW_POS);
	vx = global_vx;
	global_vy = ReadMeas(line, SECOND_ROW_POS);
	vy = global_vy;
	global_vz = ReadMeas(line, THIRD_ROW_POS);
	vz = global_vz;
}