#include <iostream>
#include <cmath>

using namespace std;

float PROB[27][11] ={
{0, .33, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, .56, .11, 0, 0, 0, 0, 0, 0, 0, 0},
{0, .68, .26, .04, 0, 0, 0, 0, 0, 0, 0},
{0, .80, .41, .11, .01, 0, 0, 0, 0, 0, 0},
{0, .85, .53, .21, .05, 0, 0, 0, 0, 0, 0},
{0, .91, .65, .32, .10, .02, 0, 0, 0, 0, 0},
{0, .93, .73, .43, .17, .05, .01, 0, 0, 0, 0},
{0, .96, .80, .53, .26, .09, .02, 0, 0, 0, 0},
{0, .97, .85, .62, .35, .14, .04, .01, 0, 0, 0},
{0, .98, .89, .70, .44, .21, .08, .02, 0, 0, 0},
{0, .98, .92, .76, .53, .29, .12, .04, .01, 0, 0},
{0, .99, .95, .82, .61, .37, .18, .07, .02, 0, 0},
{0, .99, .96, .86, .68, .45, .24, .10, .03, .01, 0},
{0, 1, .97, .89, .74, .52, .31, .15, .06, .02, 0},
{0, 1, .98, .92, .79, .60, .38, .20, .09, .03, .01},
{0, 1, .99, .94, .83, .66, .45, .26, .13, .05, .02},
{0, 1, .99, .96, .87, .72, .52, .33, .17, .08, .03},
{0, 1, .99, .97, .90, .77, .59, .39, .22, .11, .04},
{0, 1, .99, .98, .92, .81, .65, .46, .28, .15, .06},
{0, 1, 1, .98, .94, .85, .70, .52, .34, .10, .09},
{0, 1, 1, .99, .95, .88, .75, .58, .40, .24, .12},
{0, 1, 1, .99, .96, .90, .79, .64, .46, .29, .16},
{0, 1, 1, .99, .97, .92, .83, .69, .52, .35, .21},
{0, 1, 1, 1, .98, .94, .86, .74, .58, .41, .25},
{0, 1, 1, 1, .99, .95, .89, .78, .63, .46, .30},
{0, 1, 1, 1, .99, .96, .91, .81, .68, .52, .36},
{0, 1, 1, 1, .99, .97, .93, .85, .72, .57, .41}};
int main()
{
    int dodgePool=0;
    int soakPool=0;
    cout << "Super simplified since Zee doesn't feel like implementing combinations!" << endl;
    cout << "Enter Defender Dodge Pool: ";
    cin >> dodgePool;
    cout << "Enter Defender Soak Pool: ";
    cin >> soakPool;

    int totalPool = dodgePool + soakPool;
    cout << "Total pool is " << totalPool << "!" << endl;
    if (totalPool < 1)
    {
        cout << "i made this in like an hour stop trying to break it..." << endl;
        return 0;
    }



    int dodgeRate = dodgePool / 3;
    int soakRate = soakPool / 3;
    int defenderRate = totalPool / 3;

    if (defenderRate > 10)
    {
        cout << "player is too good. average rates greater than 10 not supported at this time." << endl;
        defenderRate = 10;
    }

    cout << "Expected defender result is about " << defenderRate << endl;

    int threshold = defenderRate + 1;

    int mookHit;
    int mookDMG;

    cout << "Mook to-hit?";
    cin >> mookHit;

    int mookRate = mookHit;

    if (mookHit > 26)
    {
        cout << "mook is too good. not supported." << endl;
        return 0;
    }

    cout << endl;

    cout << "MOOKS\t1DV\t2DV\t3DV\t4DV\t5DV\t6DV\t7DV\t8DV\t9DV\t10DV" << endl;


    cout.precision(4);
    for (int i=1; i<21; i++)
    {
        cout << i << "\t";

        for (int j=1; j<11; j++)
        {
            if (j < soakPool)
                cout << (float)1 - pow((1 - PROB[mookHit-1][dodgeRate+soakRate+1-j]), i) << "\t";
            else
                cout << PROB[mookHit-1][dodgeRate+1] << "\t";

        }

        cout << endl;
    }

    return 0;
}
