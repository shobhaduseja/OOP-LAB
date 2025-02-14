#include <iostream>
using namespace std;

class FitnessTracker{
    private:
    string userName;
    int dailyStepGoal;
    int stepsTaken = 0;
    int caloriesBurned = 0;

    public:
        void logSteps(int stepcount){
            stepsTaken += stepcount;
            cout << "Steps are updated" << endl;
        }

        int calCaloriesBurned(){
            caloriesBurned += stepsTaken * 0.013;
            return caloriesBurned;
        }

        void Progress(){
            cout << "\t\t Progress \t\t" << endl;
            cout << "Steps taken: " << stepsTaken << endl;
            cout << "Calories Burned: " << caloriesBurned << endl;
        }

};

int main(){
    int steps;
    int goal;
    cout << "enter your target for calories:"<<endl;
    cin >> goal;
    FitnessTracker t;
    cout << "enter today's step count: " << endl;
    cin >> steps;
    t.logSteps(steps);
    int caloriesBurned = t.calCaloriesBurned();
    if (caloriesBurned > goal){
        cout << "You reached your goal for the day" << endl;
    }
    else{
        cout << "goal not achieved, try harderrr" << endl;
    } 
    t.Progress();

    return 0;
}
