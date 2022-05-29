#pragma once
class DataManager
{
public:
	inline static DataManager* instance;
	inline static DataManager* getInstance()
	{
		return instance;
	}

	void SaveInt(const char* key, int value);
};

