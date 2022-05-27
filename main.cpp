#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
    private:
        //Create instance variable to hold 5 scores
        vector <int> scores;
    public:
        //create a void method that reads 5 integers from cin and saves to our scores vector
        void input () {
            int grade = 0;
            for (int i = 0; i < 5; i++) {
                cin >> grade;
                if (grade >= 0 && grade <= 50) {
                    scores.push_back(grade);
                }
            }
        }
        //create calculateTotalScores method that returns the sum of student scores
        int calculateTotalScore () {
            int totalScore = 0;
            vector <int>::iterator itr;
            for (itr = scores.begin(); itr != scores.end(); itr++) {
                totalScore += *itr;
            }
            return totalScore;
        }
};

int main() {
    int n; // number of students
    cin >> n;

    //include data validation so 0 < n <= 100
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

//    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
