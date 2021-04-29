//IPL NRR Calculator
// Author - Priyanshu Gupta
// Date - 25 october 2020
#include <iostream>
using namespace std;
float NRRUsual(int matches) {
    float RunsConceeded, RunsScored, OversBowled, BallsBowled, OversFaced, BallsFaced, WicketsTaken, WicketsFallen;
    float NRR, RC = 0, RS = 0, OF = 0, OB = 0;

    for (int i = 1; i <= matches; i++)
    {
        cout << "Enter details of match " << i << endl;
        cout << "Number of runs scored :" << "\t";
        cin >> RunsScored;
        cout << "Number of overs and bowls faced : " << "\t";
        cin >> OversFaced >> BallsFaced;
        cout << "Enter wickets fallen : " << "\t";
        cin >> WicketsFallen;
        if (WicketsFallen == 10)
        {
            OversFaced = 20;
            BallsFaced = 0;
        }
        cout << "Number of runs conceeded :" << "\t";
        cin >> RunsConceeded;
        cout << "Number of overs and bowls bowled : " << "\t";
        cin >> OversBowled >> BallsBowled;
        cout << "Enter wickets taken : " << "\t";
        cin >> WicketsTaken;
        if (WicketsTaken == 10)
        {
            OversBowled = 20;
            BallsBowled = 0;
        }
        RS += RunsScored;
        OF += (OversFaced + (BallsFaced) / 6);
        RC += RunsConceeded;
        OB += (OversBowled + (BallsBowled) / 6);
    }
    NRR = (RS / OF) - (RC / OB);
    return NRR;
}
int main() {
    int matches;

    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "*******************************\n\n\n" << endl;
    cout << "Hey, this is Priyanshu Gupta, welcoming you at the net run rate calculator for cricket leagues" << endl;
    cout << "Enter the number of matches played by the team :" << "\t";
    cin >> matches;
    cout << "Please enter details of all the matches :\n " << NRRUsual(matches) << " is the NRR of the team currently" << endl;

    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "*******************************\n\n\n" << endl;
    cout << "Thank you for using NRR calculator !!!" << endl;
    return 0;
}