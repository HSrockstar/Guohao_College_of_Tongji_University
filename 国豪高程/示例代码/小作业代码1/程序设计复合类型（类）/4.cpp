#include <iostream>
#include <string>
using namespace std;

class City
{
private:
	string name;
	int population;
	int farm;
	bool hasCampus = false;

	int food;
	int tech;

public:
	void get_city()
	{
		cin >> name >> population >> farm;
	}

	void print_city()
	{
		cout << name << " "
			 << population << " "
			 << food << " "
			 << tech << endl;
	}

	void updateFarm(int change)
	{
		farm += change;
		if (farm < 0) farm = 0;
	}

	void updatePopulation(int change)
	{
		population += change;
		if (population < 0) population = 0;
		food = farm * 4 - population * 2;
	}

	void updateFood()
	{
		food = farm * 4 - population * 2;
	}

	void updateTech()
	{
		if (hasCampus) tech = 4;
		else tech = 0;
	}

	void build(string opr)
	{
		if (opr == "campus" && !hasCampus)
		{
			hasCampus = true;
		}
	}

	void allUpdate()
	{
		updateFood();
		updateTech();
	}
};



int main()
{
	City city;
	city.get_city();
	city.allUpdate();
	string opr;
	int input;
	while (cin >> opr)
	{
		if (opr == "quit") break;
		else if (opr == "farm")
		{
			cin >> input;
			city.updateFarm(input);
			city.allUpdate();
			city.print_city();
		}
		else if (opr == "population")
		{
			cin >> input;
			city.updatePopulation(input);
			city.allUpdate();
			city.print_city();
		}
		else if (opr == "build")
		{
			cin >> opr;
			city.build(opr);
			city.allUpdate();
			city.print_city();
		}
	}
	return 0;
}