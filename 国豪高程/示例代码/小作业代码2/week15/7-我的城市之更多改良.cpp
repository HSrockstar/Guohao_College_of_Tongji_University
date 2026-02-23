//#include<iostream>
//using namespace std;
//
//struct city_info
//{
//	char name[30] = { "\0" };//城市名字
//	int population = 0;//人口数量
//	int farm = 0;//农田数量
//	int plantation = 0;
//	int mine = 0;
//};
//
//int main()
//{
//	struct city_info city;
//	char inition[100];//初始化指令
//	char input_name[30] = { "\0" };
//	int input_population = 0;
//	int input_farm = 0;
//	int input_plantation = 0;
//	int input_mine = 0;
//
//	//完成初始化操作
//	cin.getline(inition, 100);
//	sscanf_s(inition, "%s %d %d %d %d", input_name, (unsigned)_countof(input_name), &input_population, &input_farm, &input_plantation, &input_mine);
//	strcpy_s(city.name, input_name);//初始化城市名
//	city.population = input_population;//初始化的人口和农田
//	city.farm = input_farm;
//	city.plantation = input_plantation;
//	city.mine = input_mine;
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
//			int farm;
//			sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &farm);
//			if (city.farm + farm > 0)
//			{
//				city.farm += farm;
//			}
//			else
//			{
//				city.farm = 0;
//			}
//		}
//
//		else if (strcmp(trans_str, "plantation") == 0)
//		{
//			int plantation;
//			sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &plantation);
//			if (city.plantation + plantation > 0)
//			{
//				city.plantation += plantation;
//			}
//			else
//			{
//				city.plantation = 0;
//			}
//		}
//
//		else if (strcmp(trans_str, "mine") == 0)
//		{
//			int mine;
//			sscanf_s(instr, "%s %d", trans_str, (unsigned)_countof(trans_str), &mine);
//			if (city.mine + mine > 0)
//			{
//				city.mine += mine;
//			}
//			else
//			{
//				city.mine = 0;
//			}
//		}
//
//		else if (strcmp(trans_str, "quit") == 0)
//		{
//			break;
//		}
//
//		int gain,gold,labor;
//		char gain_sign;
//
//		gain = city.farm * 4 - city.population * 2+ city.plantation*3;
//		if (gain >= 0)
//		{
//			gain_sign = '+';
//		}
//
//		else if (gain < 0)
//		{
//			gain_sign = '-';
//		}
//
//		gold = city.plantation * 2 + city.mine * 2;
//		labor = city.mine * 3;
//		cout << city.name << " " 
//			<<city.population << "人 " 
//			<< gain_sign << gain << "粮 +" 
//			<<gold<<"金 +"
//			<<labor<<"锤"<<endl;
//	}
//
//	return 0;
//}