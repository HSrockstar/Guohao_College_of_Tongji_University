#include <iostream>
#include <string>
using namespace std;

struct cityInfo
{
	string name; // 城市名
	int population; // 人口
	int farm; // 农田
	int plantation; // 种植园
	int mine; // 矿山

	int food; // 粮食
	int coin; // 金币
	int production; // 生产力
};

cityInfo city;

void print_city(cityInfo city)
{
	char sign_f = (city.food >= 0) ? '+' : '\0';
	char sign_c = (city.coin >= 0) ? '+' : '\0';
	char sign_p = (city.production >= 0) ? '+' : '\0';
	cout << city.name << " "
		<< city.population << "人 "
		<< sign_f << city.food << "粮 "
		<< sign_c << city.coin << "金 "
		<< sign_p << city.production << "锤" << endl;
}

void food_update(cityInfo& city)
{
	city.food = city.farm * 4 + city.plantation * 3 - city.population * 2;
}

void coin_update(cityInfo& city)
{
	city.coin = city.plantation * 2 + city.mine * 2;
}

void production_update(cityInfo& city)
{
	city.production = city.mine * 3;
}

int main()
{
	cin >> city.name >> city.population >> city.farm >> city.plantation >> city.mine;
	city.food = city.farm * 4 + city.plantation * 3 - city.population * 2;
	city.coin = city.plantation * 2 + city.mine * 2;
	city.production = city.mine * 3;
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
			food_update(city);
			print_city(city);
		}
		else if (opr == "population")
		{
			cin >> input;
			city.population += input;
			city.population = (city.population < 0) ? 0 : city.population;
			food_update(city);
			print_city(city);
		}
		else if (opr == "plantation")
		{
			cin >> input;
			city.plantation += input;
			city.plantation = (city.plantation < 0) ? 0 : city.plantation;
			food_update(city);
			coin_update(city);
			print_city(city);
		}
		else if (opr == "mine")
		{
			cin >> input;
			city.mine += input;
			city.mine = (city.mine < 0) ? 0 : city.mine;
			coin_update(city);
			production_update(city);
			print_city(city);
		}
	}
	return 0;
}