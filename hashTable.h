#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class hash {
private:
	static const int tableSize = 50;

	struct item {
		std::string firstTwo;
		std::string remainLets;
		item* next;
	};

	item* Hashtable[tableSize];
public:
	hash();
	int Hash(std::string key);
	void AddWord(std::string firstTwo, std::string remainLets);
	void CheckBucket(int index, std::string first, std::string second);
	void PrintBucket(int index, std::string first);
	void AllBuckets();
};
