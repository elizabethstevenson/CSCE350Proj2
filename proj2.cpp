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

class Team {
    public:
        string teamName;
        
        Team(string teamName) {
            this.teamName = teamName;
        }
        string getName() {
            return teamName;
        }
        void setName(string teamName) {
            this.teamName = teamName;
        }
}
vector<Team> teams;


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
    
    //printStringVector(people);
    //printIntVector(ability);
}

public teamGenerator() {
    teams.push_back(new Team("Team A"));
    teams.push_back(new Team("Team B"));
    int n = 0;
    while(people.size() > 0) {
        int highestPersonIndex = findHighestAbility(ability);
        teams.get(n).people.add(people.get(highestPersonIndex));
        people.remove(highestPersonIndex);
        ability.remove(highestPersonIndex);

        if(n < teams.size()-1) {
            n++;
        } else {
            n = 0;
        }
    }
}

public int findHighestAbility(vector<int> s) {
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

int main(int argc, char* argv[]) {
    int n; //number of employees
    cin >> n;

    createVectors(n);
    if(!cin.good()) {
        return 0;
    }
    //functions with n

}
