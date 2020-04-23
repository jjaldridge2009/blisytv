#include <iostream>
#include <cmath>

using namespace std;

int main()
{


int intv, outtv, targf, hitf, tvin, tvprint, outprint, hitframe, adjtv, adjtv2, donttype;
float remainder, remaintv, adjout;
cout <<"Enter Target Frame: ";
cin >> intv;

cout <<"Enter Frames you will spend out of TeachyTV: ";
cin >> outtv;

tvin = intv - outtv;
tvprint = tvin /313;
remainder= tvin % 313;
outprint =  remainder + outtv;
cout << "Frames in TeachyTV: ";
cout <<tvprint;
cout << "      ";
cout << "Frames Out of TeachyTV: ";
cout <<outprint<<endl;



cout <<"Enter Frame hit: ";
cin >> hitframe;

adjtv = intv - hitframe;
adjtv2= adjtv /313;
adjout= adjtv % 313;

cout <<"Adjust TeachyTV by: ";
cout <<adjtv2;
cout << "      ";
cout <<"Adjust out of TeachyTV frames by: ";
cout <<adjout;
cin>> donttype;
    return 0;
}
