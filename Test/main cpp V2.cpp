#include "Station.h"
#include "headers.h"
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


/*struct station {
	struct point {
		string name;
		double
			code,
			SD,
			Hz,
			V2,
			th = 0,
			PC = 0,
			A = 0;
	} point;
	string name;
	double
		X,
		Y,
		Z,
		T,
		P,
		PC,
		Hz;
};
*/


int main()
{
	ifstream file("data.txt");
	vector<Station> stations;
	int i = 0;
	double th;
	for (string line; getline(file, line); )
	{
		if (line.substr(0, 3) == "END") break;
		stations.push_back(Station());
		if (i == 0)
			stations[0].name = line.substr(37, 11);//Макс. длина = 11 символов.

		if (line.substr(49, 1) == "X")
		{
			stations[i].get_X(stations, line, i);
		}else if(line.substr(49, 2) == "th")
		{
			stations[i].get_th(stations, line, i, th);
		}
		else if (line.substr(49, 2) == "  ") 
		{
			stations[i].get_Hz(stations, line, i);
		}
		else if (line.substr(49, 2) == "SD")
		{
			stations[i].get_SD(stations, line, i, th);
		}
		else if (line.substr(49, 2) == "T_")
		{
			stations[i].get_T(stations, line, i, th);
		}
		++i;
	}
	file.close();
	cout << stations.size() << endl;
}