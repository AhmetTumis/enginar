#include "DataManager.h"

DataManager::~DataManager()
{
	//SaveData();
}

void DataManager::SaveInt(const char* key, int value)
{
	data[key] = std::to_string(value).c_str();
}

int DataManager::ReadInt(const char* key)
{
	if (data.find(key) != data.end())
	{
		return stoi(data[key]);
	}
	else 
	{
		data[key] = "0";
		return stoi(data[key]);
	}
}

void DataManager::SaveData()
{
	map<string, string>::iterator it;

	string dataString = "";
	for (it = data.begin(); it != data.end(); it++) 
	{
		dataString += it->first + ":" + it->second + "\n";
	}

	ofstream dataFile("data.txt");

	dataFile << dataString;
}
