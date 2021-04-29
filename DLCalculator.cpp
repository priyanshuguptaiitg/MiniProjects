//DL Method Calculator
// Author - Priyanshu Gupta
// Date - 27 october 2020



#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    //variable declaration and initialisation

    int overs = 50; //overs left
    int balls = 0; //balls left in incomplete over
    int wickets = 10; //wickets in hand
    int runs1; //runs scored by team 1
    int runs2; //runs scored by team 2
    int target2; // target score for team 2
    int row = 0; //balls faced 0 to 300
    int column = 0; // wickets lost 0 to 10
    int choice; // stage of rain
    bool rain = 0; //occurance of rain
    float R1 = 100; //resources left for team 1
    float R2 = 100; //resources left for team 2
    float resource[301][11]; //resources table

    // access of resource.txt in 2D array resource[301][11] by file handling

    ifstream fp("resource.txt");
    if (!fp) {
        cout << "Error, file couldn't be opened" << endl;
        return 0;
    }
    for (row = 0; row < 301; row++) {
        for (column = 0; column < 11; column++) {
            fp >> resource[row][column];
            if (!fp) {
                cout << "Error reading file for element " << row << "," << column << endl;
                return 0;
            }
        }
    }
    fp.close();

    //implimentation of DL method


    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "*******************************\n\n\n" << endl;

    cout << "For team 1 :- \n";
    cout << "Did rain interrupted ? 1(YES) or 0(NO) : ";
    cin >> rain;
    if (rain == 1) {
        cout << "At which stage , game was interrupted :\n\t 1.) Start \n\t 2.) Middle \n\t 3.) End" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << " Resources for team 1 (R1) = " << R1 << " " << endl;
            break;

        case 2:
            cout << " Resources for team 1 (R1) = " << R1 << " " << endl;
            break;
        case 3:
            cout << " Resources for team 1 (R1) = " << R1 << " " << endl;
            break;

        default:
            cout << "Wrong choice" << endl;
            break;
        }
    }
    cout << "Enter runs scored by team 1 : ";
    cin >> runs1;
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "*******************************\n\n\n" << endl;


    cout << "For team 2 :- \n";
    cout << "Did rain interrupt ? 1(YES) or 0(NO) : ";
    cin >> rain;
    if (rain == 1) {
        cout << "At which stage , game was interrupted :\n\t 1.) Start \n\t 2.) Middle \n\t 3.) End" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of full overs left after rain : ";
            cin >> overs;
            cout << "Enter balls left in incomplete over (if any) : ";
            cin >> balls;
            wickets = 10;
            row = 50 * 6 - (overs * 6 + balls);
            column = 10 - wickets;
            R2 = resource[row][column];
            cout << " Resources for team 1 (R2) = " << R2 << " " << endl;
            target2 = (int)(runs1 * (R2 / R1) + 1);
            cout << "Target score = " << target2 << endl;
            break;

        case 2:
            float temp1, temp2;
            cout << "Enter overs left when rain began: ";
            cin >> overs;
            cout << "Enter balls left in incomplete over (if any) : ";
            cin >> balls;
            cout << "Enter wickets in hand : ";
            cin >> wickets;
            row = 50 * 6 - (overs * 6 + balls);
            column = 10 - wickets;
            temp1 = resource[row][column];
            cout << "Enter remaining full overs after rain : ";
            cin >> overs;
            cout << "Enter remaining balls in incomplete over (if any) : ";
            cin >> balls;
            row = 50 * 6 - (overs * 6 + balls);
            temp2 = resource[row][column];
            R2 = 100 - temp1 + temp2;
            cout << " Resources for team 2 (R2) = " << R2 << " " << endl;
            target2 = (int)(runs1 * (R2 / R1) + 1);
            cout << "Target score = " << target2 << endl;
            break;
        case 3:
            cout << "Enter number of overs wasted in rain : ";
            cin >> overs;
            cout << "Enter balls left in incomplete over (if any) : ";
            cin >> balls;
            cout << "Enter wickets in hand : ";
            cin >> wickets;
            cout << "Enter runs made before rain interrupted: ";
            cin >> runs2;
            row = 50 * 6 - (overs * 6 + balls);
            column = 10 - wickets;
            R2 = 100 - resource[row][column];
            cout << " Resources for team 2 (R2) = " << R2 << " " << endl;
            target2 = (int)(runs1 * (R2 / R1) + 1);
            cout << "Target score was " << target2 << endl;
            if (target2 > runs2 + 1)
                cout << "Team 2 lost by " << target2 - 1 - runs2 << "runs" << endl;
            else if (target2 = runs2 + 1)
                cout << "The match is tied" << endl;
            else
                cout << "Team 2 won by " << runs2 - target2 + 1 << "runs" << endl;
            break;
 
        default:
            cout << "Wrong choice" << endl;
            break;
        }
    }
    cout << "*******************************" << endl;
    cout << "*******************************" << endl;
    cout << "*******************************\n\n\n" << endl;

    cout << "Thank you for using D-L calculator !!!" << endl;

    return 0;
}