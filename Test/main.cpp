#include "headers.h"
#include "Station.h"

using std::cout;

void PrintAllData(vector<Station>& stations)
{
	for (size_t i = 0; i < stations.size(); ++i)
	{
		cout << "STATION " << stations[i].name << "\t";
		cout << "X = " << stations[i].X << "\t";
		cout << "Y = " << stations[i].Y << "\t";
		cout << "Z = " << stations[i].Z << "\n\n";
		for (size_t j = 0; j < stations[i].measVec.size(); ++j)
		{
			cout << "name = " << stations[i].measVec[j].targetName << "\t";
			cout << "X = " << stations[i].measVec[j].X << "\t";
			cout << "Y = " << stations[i].measVec[j].Y << "\t";
			cout << "Z = " << stations[i].measVec[j].Z << "\n";
		}
		cout << endl;
	}
	for (size_t i = 0; i < stations.size(); ++i)
	{
		cout << "STATION " << stations[i].name << "\t";
		cout << "X = " << stations[i].X << "\t";
		cout << "Y = " << stations[i].Y << "\t";
		cout << "Z = " << stations[i].Z << "\n\n";
		for (size_t j = 0; j < stations[i].measVec.size(); ++j)
		{
			cout << "code = " << stations[i].measVec[j].code << "\t";
			cout << "Hz = " << stations[i].measVec[j].Hz << "\t";
			cout << "SD = " << stations[i].measVec[j].SD << "\t";
			cout << "V2 = " << stations[i].measVec[j].V2 << "\n";		
		}
		cout << "\n-----------------------------------------------------------\n";
	}
}

int main()
{
	ifstream file("mozyr.DAT");
	vector<Station> stations;
	stations.push_back(Station());
	for (string line; getline(file, line); )
	{
		if (line.substr(0, 3) == "END")
		{
			break;
		}
		else if (line.substr(49, 1) == "X")
		{
			if (line.substr(23, 1) == "S")
			{
				Station station;
				station.set_X(line);
				stations.push_back(station);
			}
			else
			{
				stations.back().set_X(line, stations);
			}
		}
		else if (line.substr(49, 2) == "th")
		{
			stations.back().set_th(line);
		}
		else if (line.substr(49, 2) == "  ")
		{
			if (line.substr(72, 2) == "Om")
			{
				stations.back().set_Om(line);
			}
			else if (line.substr(95, 2) == "SK")
			{
				stations.back().set_SK(line);
			}
		}
		else if (line.substr(49, 2) == "SD")
		{
			stations.back().set_SD(line);
		}
		else if (line.substr(49, 2) == "T_")
		{
			stations.back().set_T(line);
		}
		else if (line.substr(49, 1) == "i")
		{
			stations.back().set_i(line);
		}
		else if (line.substr(49, 1) == "m")
		{
			stations.back().set_m(line);
			if (line.substr(72, 2) == "Om")
			{
				stations.back().set_Om(line);
				stations.back().set_s0(line);
			}
		}
		else if (line.substr(49, 2) == "vx")
		{
			stations.back().set_vx(line);
		}

	}
	file.close();
	stations.erase(stations.begin());//удаление пустого элемента вектора
	cout.precision(6);
	PrintAllData(stations);
	return 0;
}