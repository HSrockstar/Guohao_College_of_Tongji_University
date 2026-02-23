#include <iostream>
#include <string>
using namespace std;

struct cityInfo
{
	string name;
	int population;
	int farm;
	int food;
};

cityInfo city;

void print_city(cityInfo city)
{
	char sign = (city.food >= 0) ? '+' : '\0';
	cout << city.name << " "
		<< city.population << "ÈË "
		<< sign << city.food << "Á¸" << endl;
}

int main()
{
	cin >> city.name >> city.population >> city.farm;
	string opr;
	int input;
	while (cin >> opr)
	{
		if (opr == "quit") break;
		else if (opr == "farm")
		{
			cin >> input;
			city.farm += input;
			city.farm = (city.farm < 0) ? 0 : city.farm;
			city.food = city.farm * 4 - city.population * 2;
			print_city(city);
		}
		else if (opr == "population")
		{
			cin >> input;
			city.population += input;
			city.population = (city.population < 0) ? 0 : city.population;
			city.food = city.farm * 4 - city.population * 2;
			print_city(city);
		}
	}
	return 0;
}