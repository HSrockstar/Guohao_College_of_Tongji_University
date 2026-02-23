#include <iostream>
#include <string>
using namespace std;

struct cityInfo
{
	string name = ""; // 城市名
	int population = 0; // 人口
	int farm[3] = { 0 }; // 农田0:hill 1:plain 2:floodplain
	int plantation[2] = { 0 }; // 种植园0:fabric 1:food
	int mine[2] = { 0 }; // 矿山0:material 1:precious

	int food = 0; // 粮食
	int coin = 0; // 金币
	int production = 0; // 生产力
	bool has_factory = false; // 工厂
	bool has_market = false; // 市场
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
	city.food = city.farm[0] * 2 + city.farm[1] * 3 + city.farm[2] * 4 + city.plantation[1] * 4 - city.population * 2;
}

void coin_update(cityInfo& city)
{
	if (city.has_market) city.coin = city.plantation[0] * 4 + city.mine[0] * 2 + city.mine[1] * 4 + city.population * 2; // 市场加成
	else city.coin = city.plantation[0] * 4 + city.mine[0] * 2 + city.mine[1] * 4;
	if (city.has_factory) city.coin -= 10; // 工厂维护费
}

void production_update(cityInfo& city)
{
	if (city.has_factory) city.production = city.mine[0] * 4 + city.mine[1] * 2 + city.population * (1 + 2); // 工厂加成
	else city.production = city.mine[0] * 4 + city.mine[1] * 2 + city.population * 1;
}

void update(cityInfo& city)
{
	food_update(city);
	coin_update(city);
	production_update(city);
}

int main()
{
	cin >> city.name >> city.population;
	update(city);
	string opr;
	int input;
	while (cin >> opr)
	{
		if (opr == "quit") break;
		else if (opr == "farm")
		{
			cin >> opr;
			if (opr == "hill")
			{
				cin >> input;
				city.farm[0] += input;
				city.farm[0] = (city.farm[0] < 0) ? 0 : city.farm[0];
			}
			else if (opr == "plain")
			{
				cin >> input;
				city.farm[1] += input;
				city.farm[1] = (city.farm[1] < 0) ? 0 : city.farm[1];
			}
			else if (opr == "floodplain")
			{
				cin >> input;
				city.farm[2] += input;
				city.farm[2] = (city.farm[2] < 0) ? 0 : city.farm[2];
			}
			update(city);
			print_city(city);
		}
		else if (opr == "population")
		{
			cin >> input;
			city.population += input;
			city.population = (city.population < 0) ? 0 : city.population;
			update(city);
			print_city(city);
		}
		else if (opr == "plantation")
		{
			cin >> opr;
			if (opr == "fabric")
			{
				cin >> input;
				city.plantation[0] += input;
				city.plantation[0] = (city.plantation[0] < 0) ? 0 : city.plantation[0];
			}
			else if (opr == "food")
			{
				cin >> input;
				city.plantation[1] += input;
				city.plantation[1] = (city.plantation[1] < 0) ? 0 : city.plantation[1];
			}
			update(city);
			print_city(city);
		}
		else if (opr == "mine")
		{
			cin >> opr;
			if (opr == "material")
			{
				cin >> input;
				city.mine[0] += input;
				city.mine[0] = (city.mine[0] < 0) ? 0 : city.mine[0];
			}
			else if (opr == "precious")
			{
				cin >> input;
				city.mine[1] += input;
				city.mine[1] = (city.mine[1] < 0) ? 0 : city.mine[1];
			}
			update(city);
			print_city(city);
		}
		else if (opr == "build")
		{
			cin >> opr;
			if (opr == "factory")
			{
				city.has_factory = true;
				update(city);
				print_city(city);
			}
			else if (opr == "market")
			{
				city.has_market = true;
				update(city);
				print_city(city);
			}
		}
	}
	return 0;
}