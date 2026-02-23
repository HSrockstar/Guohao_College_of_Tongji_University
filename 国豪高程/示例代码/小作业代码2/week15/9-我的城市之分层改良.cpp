//#include<iostream>
//using namespace std;
//
//struct farm_info
//{
//	int hill = 0;
//	int plain = 0;
//	int floodplain = 0;
//};//农田
//struct plantation_info
//{
//	int fabric = 0;
//	int food = 0;
//};//种植园
//struct mine_info
//{
//	int material = 0;
//	int precious = 0;
//};//矿山数量
//
//struct city_info
//{
//	char name[30] = { "\0" };//城市名字
//	struct farm_info farm;
//	struct plantation_info plantation;
//	struct mine_info mine;
//	int population = 0;//人口数量
//	int factory = 0;
//	int market = 0;
//};
//
//int main()
//{
//	struct city_info city = {};
//	char inition[100];//初始化指令
//	char input_name[30] = { "\0" };
//	int input_population = 0;
//	int input_farm = 0;
//	int input_plantation = 0;
//	int input_mine = 0;
//	int factory_cost = 0;
//
//	//完成初始化操作
//	cin.getline(inition, 100);
//	sscanf_s(inition, "%s %d", input_name, (unsigned)_countof(input_name), &input_population);
//	strcpy_s(city.name, input_name);//初始化城市名
//	city.population = input_population;//初始化的人口和农田
//
//	while (true)
//	{
//		char instr[100] = { "\0" };
//		char trans_str[15] = { "\0" };
//
//		cin.getline(instr, 100);
//		sscanf_s(instr, "%s", trans_str, (unsigned)_countof(trans_str));
//
//		if (strcmp(trans_str, "population") == 0)
//		{
//			int population;
//			sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &population);
//			if (city.population + population > 0)
//			{
//				city.population += population;
//			}
//			else
//			{
//				city.population = 0;
//			}
//		}
//
//		else if (strcmp(trans_str, "farm") == 0)
//		{
//			char farm_type[15];
//			int farm;
//			sscanf_s(instr, "%s %s %d", trans_str, (unsigned)_countof(trans_str), farm_type, (unsigned)_countof(farm_type), &farm);
//			if (strcmp(farm_type, "hill") == 0)
//			{
//				if (city.farm.hill + farm > 0)
//				{
//					city.farm.hill += farm;
//				}
//				else
//				{
//					city.farm.hill = 0;
//				}
//			}
//
//			else if (strcmp(farm_type, "plain") == 0)
//			{
//				if (city.farm.plain + farm > 0)
//				{
//					city.farm.plain += farm;
//				}
//				else
//				{
//					city.farm.plain = 0;
//				}
//			}
//
//			else if (strcmp(farm_type, "floodplain") == 0)
//			{
//				if (city.farm.floodplain + farm > 0)
//				{
//					city.farm.floodplain += farm;
//				}
//				else
//				{
//					city.farm.floodplain = 0;
//				}
//			}
//			
//		}
//
//		else if (strcmp(trans_str, "plantation") == 0)
//		{
//			char plantation_type[10];
//			int plantation;
//			sscanf_s(instr, "%s %s %d", trans_str, (unsigned)_countof(trans_str), plantation_type, (unsigned)_countof(plantation_type), &plantation);
//			if (strcmp(plantation_type, "fabric") == 0)
//			{
//				if (city.plantation.fabric + plantation > 0)
//				{
//					city.plantation.fabric += plantation;
//				}
//				else
//				{
//					city.plantation.fabric = 0;
//				}
//			}
//
//			else if (strcmp(plantation_type, "food") == 0)
//			{
//				if (city.plantation.food + plantation > 0)
//				{
//					city.plantation.food += plantation;
//				}
//				else
//				{
//					city.plantation.food = 0;
//				}
//			}
//		}
//
//		else if (strcmp(trans_str, "mine") == 0)
//		{
//			int mine;
//			char mine_type[10];
//
//			sscanf_s(instr, "%s %s %d", trans_str, (unsigned)_countof(trans_str), mine_type, (unsigned)_countof(mine_type),&mine);
//			
//			if (strcmp(mine_type, "material") == 0)
//			{
//				if (city.mine.material + mine > 0)
//				{
//					city.mine.material += mine;
//				}
//				else
//				{
//					city.mine.material = 0;
//				}
//			}
//
//			else if (strcmp(mine_type, "precious") == 0)
//			{
//				if (city.mine.precious + mine > 0)
//				{
//					city.mine.precious += mine;
//				}
//				else
//				{
//					city.mine.precious = 0;
//				}
//			}
//		}
//
//		else if (strcmp(trans_str, "build") == 0)
//		{
//			char category[8] = { "\0" };
//			sscanf_s(instr, "%s %s", trans_str, (unsigned)_countof(trans_str), category, (unsigned)_countof(category));
//			if (strcmp(category, "factory") == 0)
//			{
//				if (city.factory == 0)
//				{
//					city.factory = 1;
//					factory_cost = 10;
//				}
//			}
//
//			else if (strcmp(category, "market") == 0)
//			{
//				if (city.market == 0)
//				{
//					city.market = 1;
//				}
//			}
//		}
//
//		else if (strcmp(trans_str, "quit") == 0)
//		{
//			break;
//		}
//
//		int gain, gold, labor;
//		char gain_sign[3];
//		char gold_sign[3];
//
//		gain = city.farm.hill * 2+ city.farm.plain * 3+ city.farm.floodplain * 4  - city.population * 2 + city.plantation.food * 4;
//		if (gain >= 0)
//		{
//            strcpy_s(gain_sign, _countof(gain_sign), " +");
//		}
//		else if (gain < 0)
//		{
//			strcpy_s(gain_sign, _countof(gain_sign), " ");
//		}
//
//		gold = city.plantation.fabric * 4 + city.mine.material * 2 + city.mine.precious * 4 + city.population * 2 * city.market - factory_cost;
//		if (gold >= 0)
//		{
//			strcpy_s(gold_sign, _countof(gold_sign), " +");
//		}
//
//		else if (gold < 0)
//		{
//			strcpy_s(gold_sign, _countof(gold_sign), " ");
//		}
//
//		labor = city.mine.material * 4 + city.mine.precious * 2 + city.population * (1 + 2 * city.factory);
//		cout << city.name << " "
//			<< city.population << "人"
//			<< gain_sign << gain << "粮"
//			<< gold_sign << gold << "金 +"
//			<< labor << "锤" << endl;
//	}
//
//	return 0;
//}