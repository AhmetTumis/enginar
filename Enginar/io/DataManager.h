#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class DataManager
{
public:
	~DataManager();

	inline static DataManager* instance;
	inline static DataManager* getInstance()
	{
		return instance;
	}

	DataManager() 
	{
		instance = this;

		ifstream dataFile("data.txt");
		string line = "";
		int b = 0;
		while (std::getline(dataFile, line)) {
			// Output the text from the file
			string key = "";
			string value = "";

			bool isKey = true;
			b++;

			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == ':')
				{
					isKey = false;
					continue;
				}

				if (isKey)
				{
					key += line[i];
				}
				else 
				{
					value += line[i];
				}
			}
			data.insert({ key, value });
			key = "";
			value = "";
		}
	}

	void SaveInt(const char* key, int value);
	int ReadInt(const char* key);
	void SaveData();

private:
	FILE* dataFile = nullptr;
	map<string, string> data;
};

