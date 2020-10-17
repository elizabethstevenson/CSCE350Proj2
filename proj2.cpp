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
/*
class Team {
    public:
        string teamName;
        vector<string> people;

        Team(string teamName) {
            this.teamName = teamName;
        }
        string getName() {
            return teamName;
        }
        void setName(string teamName) {
            this.teamName = teamName;
        }
};
vector<Team> teams;

class Employee {
    public:
        string employeeName;
        int ability;

        Employee(string employeeName, int ability) {
            this.employeeName = employeeName;
            this.
        }        
}

*/
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

void print01List(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void createVectors(int n) {

    //people.clear();
    //ability.clear();
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
    //check for same thing with people
    ability.erase(ability.begin(), ability.begin() + n);//had to remove the first n elements bc they were all 0's
    
    //printStringVector(people);
    //printIntVector(ability);
}
/*
void teamGenerator() {
    teams.push_back(new Team("Team A"));
    teams.push_back(new Team("Team B"));
    int n = 0;
    while(people.size() > 0) {
        int highestPersonIndex = findHighestAbility(ability);
        teams.at(n).people.push_back(people.at(highestPersonIndex));
        people.erase(people.begin() + highestPersonIndex);
        ability.erase(ability.begin() + highestPersonIndex);

        if(n < teams.size()-1) {
            n++;
        } else {
            n = 0;
        }
    }
}

int findHighestAbility(vector<int> s) {
    int index = -1;
    int highest = -1;
    for (int i = 0; i < s.size(); ++i) {
        if(s.get(i) > highest) {
            highest = s.get(i)
            index = i;
        }
    }
    return index;
}
*/


void produce01List(int n, int array[], int i) {
    if(i==n) {
        //print01List(array, n);
        return;
    }
    array[i] = 0;
    produce01List(n, array, i+1);
    array[i] = 1;
    produce01List(n, array, i+1);
}

void assignTeams() {
    //look in planner
}

int main(int argc, char* argv[]) {
    int n; //number of employees
    cin >> n;
    int binaryArray[n];
    produce01List(n, binaryArray, 0);
    createVectors(n);
    assignTeams();
    if(!cin.good()) {
        return 0;
    }
    //functions
    //teamGenerator();

}
