//Elizabeth Stevenson
//CSCE350 Project 2

#include <iostream>
#include <string.h>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//template <typename T> 

vector<string> people;
vector<int> ability;

//string vector printer
void printStringVector(vector<string> s) {
    for (unsigned int i = 0; i < s.size(); i++) {
        cout << s.at(i);
    }
}

//int vector printer
void printIntVector(vector<int> s) {
    for (unsigned int i = 0; i < s.size(); i++) {
        cout << s.at(i);
    }
}

void createVectors(int n) {
    people.resize(n); //sized vector with number of employees
    ability.resize(n); //sized vector with number of employees

    string person;
    int singleAbility;
    for(int i = 0; i < n; ++i) {
        cin >> person;
        people.push_back(person);
        cin >> singleAbility;
        ability.push_back(singleAbility);
    }

    ability.erase(ability.begin(), ability.begin() + n);//had to remove the first n elements bc they were all 0's
    
    printStringVector(people);
    printIntVector(ability);

}

int main(int argc, char* argv[]) {
    int n; //number of employees
    cin >> n;

    createVectors(n);
    if(!cin.good()) {
        return 0;
    }
    //functions with n

}