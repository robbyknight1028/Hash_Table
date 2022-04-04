#include "hashTable.h"


//function that creates the entire hashtable as empty
hash::hash() {

	for (int i = 0; i < tableSize; i++) {
		Hashtable[i] = new item;
		Hashtable[i]->firstTwo = "empty";
		Hashtable[i]->remainLets = "empty";
		Hashtable[i]->next = NULL;
	}



}

//function that hashes the first two letters of all the words to decide where to place them
int hash::Hash(std::string key) {
	int hash = 0;
	int index;
	int asc;

	//gets ascii value of both letters and adds them
	for (int i = 0; i < key.length(); i++) {
		asc = (int)key[i];
		hash = hash + asc;
	}

	//gets index by using modulus to decide which bucket to place
	index = hash % tableSize;

	return index;
}


//function that adds each word to the specific bucket
void hash::AddWord(std::string firstTwo, std::string remainLets) {

	//go to hash function
	int index = Hash(firstTwo);


	//if no other words in bucket, place word here with no issues
	if (Hashtable[index]->firstTwo == "empty") {
		Hashtable[index]->firstTwo = firstTwo;
		Hashtable[index]->remainLets = remainLets;
	}

	//if there is a collision, send to next spot in the same bucket
	else {
		//this is how i handled collisions by pointing to the next item in the bucket
		item* Pointer = Hashtable[index];
		item* n = new item;
		n->firstTwo = firstTwo;
		n->remainLets = remainLets;
		n->next = NULL;
		
		
		while (Pointer->next != NULL) {
			Pointer = Pointer->next;
		}
		Pointer->next = n;
	}
}

//function that checks if the user word is in the hash table, if so, prints out all other words with same first two letters
void hash::CheckBucket(int index,std::string first, std::string second) {

	
	item* Pointer = Hashtable[index];
	int wordCheck = 0;
	
	//while loop that checks each item in the bucket for similarity to users word
	while (Pointer != NULL) {

		if (first == Pointer->firstTwo && second == Pointer->remainLets) {
			std::cout << "TRUE";
			wordCheck += 1;
			PrintBucket(index, first);
			break;
		}
		
		else {
			Pointer = Pointer->next;
		}
	}

	if (wordCheck == 0) {
		std::cout << "FALSE";
	}
	
}


//prints the items of the bucket that have same first two letter as users word if users word is in the hash table
void hash::PrintBucket(int index, std::string first){

	item* Pointer = Hashtable[index];
	
	//checks first two letters of each word in bucket and prints out if they match first two of users word
	while (Pointer != NULL) {

		if (first == Pointer->firstTwo) {
			std::cout << Pointer->firstTwo << Pointer->remainLets << std::endl;
		}

		Pointer = Pointer->next;
	}


}



//function used to print out all buckets for troubleshooting

void hash::AllBuckets(){

	
	
	for(int i = 0; i < 50; i++){
		

		item* Pointer = Hashtable[i];

		while (Pointer != NULL) {
				
			std::cout << Pointer->firstTwo << Pointer->remainLets << ",";	
			Pointer = Pointer->next;
			
		}
		std::cout << std::endl;
		std::cout << "----------------------------------------"<<std::endl;

	}
}

