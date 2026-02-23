#include <iostream>
#include <string>
using namespace std;

class City
{
private:
	string name = "";
	int population = 0;
	int farm = 0;
	bool hasCampus = false;
	bool hasLibrary = false;
	bool hasUniversity = false;
	bool hasLab = false;

	int food = 0;
	double tech = 0.0;

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
	}

	void updateFood()
	{
		food = farm * 4 - population * 2;
	}

	void updateTech()
	{
		tech = 0;
		if (hasCampus) tech += 4;
		if (hasLibrary) tech += 4 + population * 0.5;
		if (hasUniversity) tech += 8 + population * 1;
		if (hasLab) tech += 16 + population * 1 + ((population - 10 > 0) ? (population - 10) : 0) * 2;
	}

	void build(string opr)
	{
		if (opr == "campus" && !hasCampus) hasCampus = true;
		else if (opr == "library" && hasCampus) hasLibrary = true;
		else if (opr == "university" && hasLibrary) hasUniversity = true;
		else if (opr == "lab" && hasUniversity) hasLab = true;
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