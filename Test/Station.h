#pragma once
#include <string>
static double
global_th,
global_m,
global_T,
global_P,
global_PC,
global_i,
global_c,
global_SZ,
global_SK,
global_ih,
global_Om,
global_S0,
global_vx,
global_vy,
global_vz;
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
	double
		SD,
		Hz,
		V2,
		X,
		Y,
		Z,
		th;
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
		ih,
		c,
		i,
		SZ,
		SK,
		Om,
		m,
		S0,
		vx,
		vy,
		vz,
		dir;
	vector<Meas> measVec;

	void set_X(std::string&);

	void set_X(std::string&, vector<Station>&);

	void set_th(std::string&);

	void set_Hz(std::string&);

	void set_SD(std::string&);

	void set_T(std::string&);

	void set_i(std::string&);

	void set_SK(std::string&);

	void set_Om(std::string&);

	void set_m(std::string&);

	void set_s0(std::string&);

	void set_Direct0(vector<Station>&, double);

	void set_Direct(vector<Station>&, double);
};