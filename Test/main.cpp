#include "headers.h"
#include "Station.h"

using std::cout;

int main()
{
	ifstream file("mozyr.DAT");
	if (file.is_open()) {
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
			Station station;
			station.set_X(line);
			stations.push_back(station);
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
	cout << stations.size() << endl;
	return 0;
	}
	else {
		cout << "Cannot read the file\n";
		return 1;
	}
}