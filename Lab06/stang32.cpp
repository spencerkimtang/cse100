#include <iostream>
#include <list>

using namespace std;


//Looked online on how to create linked list 
//Looked online on how to do each function(insertion, delete, search)
//Colaborated with Malia Bowman in print function

int hashFunction(int key, int size){		//k mod m
	int index = 0;
	index = key % size;
	return index;
}

int hashSearch(list<int> hashTable[], int key, int index){
	list<int>::iterator i;
	int index1 = 0;

	//if (hashTable.empty()){
	//	cout << key << ":NOT_FOUND" << endl;
	//	return -1;
	//}
	//else {
	for(i = hashTable[index].begin(); i != hashTable[index].end();){
		if(*i == key){
			return index1;
		}
		index1++;
		i++;
	}
	//}
	//not sure why it needs to be -100, other numbers doesn't work
	return -100;
}

void hashInsertion(list<int> hashTable[], int key, int index){
	hashTable[index].push_front(key);
}

void hashDelete(list<int> hashTable[], int key, int index, int position){
	int count = 0;
	list<int>::iterator i;
	list<int>::iterator j;
	for(i = hashTable[index].begin(); i != hashTable[index].end(); i++){
		j = i;
		if(position == count){
			i++;
			hashTable[index].erase(j);
		}
		count++;
	}
}

void print(list<int> hashTable[], int size){
	//points to each term in the linked list from start to end
	list<int>::iterator i;
	//got help from Malia Bowman 
	for(int j = 0; j <= size - 1; j++){
		cout << j << ":";
		if(hashTable[j].size() > 0){
			for(i = hashTable[j].begin(); i != hashTable[j].end(); ++i){
				cout << *i << "->";
			}
		}
		cout << ";" << endl;
	}
}

int main(){
	int size;
	cin >> size;
	char command;
	cin >> command;

	list<int>* hashTable = new list<int>[size];
	int key;
	int index;

	while(command != 'e'){
		if(command == 'i'){
			cin >> key;
			index = hashFunction(key, size);
			hashInsertion(hashTable, key, index);
		}
		else if(command == 'd'){
			cin >> key;
			int position;
			index = hashFunction(key, size);
			position = hashSearch(hashTable, key, index);
			if(position == -100){
				cout << key << ":DELETE_FAILED;" << endl;
			}
			else{
				hashDelete(hashTable, key, index, position);
				cout << key << ":DELETED;" << endl;
			}
		}
		else if(command == 's'){
			cin >> key;
			int position;
			index = hashFunction(key, size);
			position = hashSearch(hashTable, key, index);
			if(position == -100){
				cout << key << ":NOT_FOUND;" << endl;
			}
			else{
				cout << key << ":FOUND_AT" << index << "," << position << ";" << endl;
			}
		}
		else if(command == 'o'){
			print(hashTable, size);
		}
		cin >> command;
	}
	return 0;
}	