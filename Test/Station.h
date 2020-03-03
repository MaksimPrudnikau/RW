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

	//fixme
	Station()
	{
		T = global_T;
		P = global_P;
		PC = global_PC;
		ih = global_ih;
		c = global_c;
		i = global_i;
		SZ = global_SZ;
		SK = global_SK;
		Om = global_Om;
		m = global_m;
		s0 = global_S0;
		vx = global_vx;
		vy = global_vy;
		vz = global_vz;
	}
		
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