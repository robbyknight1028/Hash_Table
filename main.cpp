#include "hashTable.h"
#include <sstream>
#include <fstream>
#include "TimeInterval.h"

//function prototype
void wordSuggestor(hash Wordhash);

int main() {
	//class instance
	hash Wordhash;


	//holders for word and file
	std::string word;
	std::ifstream myfile;

	
	//opening text file
	myfile.open("Dictionary.txt");

	//while loop that runs through each word in text file and adds to hash table
	while (getline(myfile, word)) {
		
		//takes space away at end of word that getline was grabbing for some reason
		word = word.substr();

		//holders for first two letters of word and then the rest of the word
		std::string twoLetter;
		std::string completeWord;


		//for loop that splits the word into two different holders
		for (int i = 0; i < word.length(); i++) {
			if (i < 2) {
				twoLetter += word[i];
				
			}
			else {
				completeWord += word[i];
			}
		
		}

		//add words to hash table
		Wordhash.AddWord(twoLetter, completeWord);
		
		

	}
	myfile.close();
	


	Wordhash.AllBuckets();	

	

	bool keepGoing = true;
	//while loop that allows user to continue searching for words until they no longer want to
	while (keepGoing == true) {
		int userInput;
		std::cout << "Word Suggestor Menu" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "1) Enter a Word" << std::endl;
		std::cout << "2) Close Program" << std::endl;
		
		std::cin >> userInput;

		if (userInput == 1) {
			wordSuggestor(Wordhash);
		}
		
		else {
			keepGoing = false;
			std::cout << "Thank you for trying out my word suggestor";
		}






	}
	

}

void wordSuggestor(hash Wordhash) {
	

	//takes user input and hashes first two letters
	std::string userWord;
	std::string userFirst;
	std::string userSecond;

	std::cout << "Please enter a word" << std::endl;
	std::cin >> userWord;
	for (int i = 0; i < userWord.length(); i++) {
		if (i < 2) {
			userFirst += userWord[i];

		}
		else {
			userSecond += userWord[i];
		}

	}
	//starts the time interval timing
	TimeInterval timing;
	timing.start();
	int check = Wordhash.Hash(userFirst);


	//sends users word to check if it is in hashtable
	Wordhash.CheckBucket(check, userFirst, userSecond);
	timing.stop();
	int time = timing.GetInterval();
	
	//outputs time
	std::cout << "The suggestion took " << time << "micro seconds" << std::endl;

}


	
