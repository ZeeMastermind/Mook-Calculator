#include <iostream>
#include <cmath>

using namespace std;

int pascal(int x, int y)
{
    /*
    Taken from https://stackoverflow.com/questions/15601867/how-can-i-calculate-the-number-at-a-given-row-and-column-in-pascals-triangle
    */
    if((x+1)==1 || (y+1)==1 || x==y)
    {
        return 1;
    }
    else
    {
        return pascal(x-1,y-1)+ pascal(x-1,y);
    }
}

float combinations(int pool, int threshold)
{
    //threshold is 'actual number', must hit threshold+1 to succeed.
    float result = 0;
    while (threshold <= pool)
    {
        float a = pow((float)1/3, threshold);
        float b = pow((float)2/3, pool - threshold);
        int c = pascal(pool,threshold); //pool is row, threshold is column
        result += a * b * (float)c;
        threshold++;
    }

    return result;
}



int main()
{
    int defensePool;
    int soakPool;
    int toHit;
    int defenseRate;
    int soakRate;

    cout.precision(4);

    cout << combinations(3,2) << endl;

    cout << "MOOK CALCULATOR!" << endl;
    cout << endl;
    cout << "Enter Defender Defense roll - should be REA + INT: ";
    cin >> defensePool;
    cout << "Enter Defender Soak roll - should be BOD + Armor: ";
    cin >> soakPool;
    cout << "Finally, enter Mook to-hit roll: ";
    cin >> toHit;
    cout << endl;

    defenseRate = defensePool/3;
    soakRate = soakPool/3;


    cout << "MOOKS\t";
    for (int i=1; i<=5; i++)
    {
        cout << i << "DV\t\t";
    }
    cout << endl;
    for (int i=1; i<=10; i++)
    {
        cout << i << "\t";
        for (int j=1; j<=5; j++)
        {
            int netHitsNeeded = soakRate - j;
            if (netHitsNeeded < 1)
                netHitsNeeded = 1;
            float output = combinations(toHit, defenseRate + netHitsNeeded);
            output = 1 - pow(1-output,i);
            output *= 100;
            if (output < 0.1)
                cout << output << "%\t";
            else
                cout << output << "%\t\t";
        }
        cout << endl;
    }
    cout << endl;


    cout << "MOOKS\t";
    for (int i=6; i<=10; i++)
    {
        cout << i << "DV\t\t";
    }
    cout << endl;
    for (int i=1; i<=10; i++)
    {
        cout << i << "\t";
        for (int j=6; j<=10; j++)
        {
            int netHitsNeeded = soakRate - j;
            if (netHitsNeeded < 1)
                netHitsNeeded = 1;
            float output = combinations(toHit, defenseRate + netHitsNeeded);
            output = 1 - pow(1-output,i);
            output *= 100;
            if (output < 0.1)
                cout << output << "%\t";
            else
                cout << output << "%\t\t";
        }
        cout << endl;
    }

    return 0;
}
