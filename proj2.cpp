//Elizabeth Stevenson
//CSCE350 Project 2

#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

vector<string> people;
vector<int> ability;
vector<string> teamAPeople;
vector<string> teamBPeople;

/*
This was my first attempt of trying to assign teams but it doesn't sort correctly
bc it only puts the highest ability left in alternating teams. This way doesn't
make equal teams.
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

//prints binary stuff
void print01List(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//prints team in correct format
void printTeamVectors(vector<string> team) {
    for (unsigned int i = 0; i < team.size(); ++i) {
        cout << " " << team.at(i) << endl;
    }
}

//puts the input into people and ability vectors
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
    ability.erase(ability.begin(), ability.begin() + n);//had to remove the first n elements bc they were all 0's
    
    //printStringVector(people);
    //printIntVector(ability);
}

//makes binary list
void produce01List(int n, int array[], int i) {
    if(i == n) {
        //print01List(array, n);
        return;
    }
    array[i] = 0;
    produce01List(n, array, i+1);
    array[i] = 1;
    produce01List(n, array, i+1);
}

/*making 001010101000 to
 * 001
 * 010
 * 101
 * 000
 * with the appropriate numbers
 *
 * Could not figure out how to break up the array
 * so then the sorting can work 

int** convert01(unsigned int n, int array[]) {
    unsigned int size = pow(2,n)-1;
    int** newBinary = new int[size][n];
    for(unsigned int i = 0; i < size; ++i) {
        for(unsigned int j = 0; j < n; ++j) {
            newBinary[i][j] = array.at((j+n) % 10);
        }
    }
    return newBinary;
}
*/

//the exhaustive search design strategy is this method
void assignTeams(int n, int array[]) {
    //if there is 1 employee, no teams can be made
    if(n == 1) {
        cout << "No solution." << endl;
        cout << "------------" << endl;
        return;
    }
    int index = 0; //keeps track of the index in the corresponding people and ability vectors

    /* initialize vectors
     * Did this bc of the error:
     * terminate called after throwing an instance of 'std::out_of_range'
     *  what():  vector::_M_range_check: __n (which is 3) >= this->size() (which is 3)
     *  Aborted (core dumped)
     */
    teamAPeople.resize(n);
    teamBPeople.resize(n);

    //team ability totals
    int teamATotal = 0;
    int teamBTotal = 0;

    //the actual sorting part
    for(int a = 0; a < ((pow(2,n))-1); ++a) {
        for(int e = 0; e < (n-1); ++e) {
            //these conditions move through the 0s and 1s to make all the combinations of teams
            // if (((array.at(a) >> array.at(e)) & 1) == 0) I tried to use this as my condition but I couldn't
            // figure out the array and I wanted it to compile.  It's the same thing with the else if condition
            if(((a >> e) & 1) == 0) {
                teamAPeople.push_back(people.at(index)); //add person to Team A
                teamATotal += ability.at(index); //add person's ability to Team A total ability
                index++; //move on to the next person in the vector
                //cout << index;
                //cout << teamATotal;
            } else if(((a >> e) & 1) == 1) { //else if (((array.at(a) >> array.at(e)) & 1) == 1)
                teamBPeople.push_back(people.at(index)); //add person to Team B
                teamBTotal += ability.at(index); //add person's ability to Team B total ability
                index++; //move on to the next person in the vector
                //cout << index;
                //cout << teamBTotal;
            }
        }
    }
    //prints the teams with the same total
    if(teamATotal == teamBTotal) {
        cout << "Team A:" << endl;
        printTeamVectors(teamAPeople);
        cout << "Team B:" << endl;
        printTeamVectors(teamBPeople);
    } else {
        cout << "No solution." << endl;
        cout << "------------" << endl;
    }
}

int main(int argc, char* argv[]) {
    int n; //number of employees
    cin >> n;
    int binaryArray[n];
    produce01List(n, binaryArray, 0);
    createVectors(n);
    assignTeams(n, binaryArray);
    if(!cin.good()) {
        return 0;
    }
}
