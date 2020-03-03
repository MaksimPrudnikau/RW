#pragma once
#include <string>
static double global_th;
/*
struct Point {
	string name;
	double
		code,
		SD,
		Hz,
		V2,
		th = 0,
		PC = 0,
		A = 0;
};
*/
struct Meas {
	string targetName;
	double SD;
	double Hz;
	double V2;
	double th;
	string code;

};

class Station
{
public:
	string name;
	double
		X,
		Y,
		Z,
		T,
		P,
		PC,
		Hz,
		A = 0,
		ih,
		c,
		i,
		SZ,
		SK,
		Om,
		m,
		s0,
		vx,
		vy,
		vz;

	vector<Meas> measVec;

	void set_X(std::string& line);
	
	void set_th(std::string& line);

	void set_Hz(std::string& line);

	void set_SD(std::string& line);

	void set_T(std::string& line);

	void set_i(std::string& line);

	void set_SK(std::string& line);

	void set_Om(std::string& line);

	void set_m(std::string& line);

	void set_s0(std::string& line);

	void set_vx(std::string& line);
};