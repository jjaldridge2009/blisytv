#include <iostream>
#include <cmath>

using namespace std;

int main()
{
int intv, outtv, targf, hitf, tvin, tvprint, outprint, hitframe, adjtv, adjtv2, donttype;
long double remainder, remaintv, adjout, nds, gba, ms, msout, mstvout, bigtvout, bigout, lowerbetternumber, fasttv;

gba = 59.7275;
nds = 59.6555;
std::cout << "Type the Number that Corresponds to your game console:\n";
std::cout << "[1] Nintendo DS\n"
          << "[2] Gameboy Advance\n";

std::string input;
std::getline(std::cin, input);

while(input != "1" && input != "2") {
    std::cout << "Invalid!\n\n";

std::cout << "Type the Number that Corresponds to your game console:\n";
std::cout << "[1] Nintendo DS\n"
          << "[2] Gameboy Advance\n";
    std::getline(std::cin, input);
}

if (input == "1") {
   ms = nds;
} else if (input == "2") {
   ms = gba;
}


cout <<"Enter Target Frame: ";
cin >> intv;

cout <<"Enter Frames you will spend out of TeachyTV: ";
cin >> outtv;

tvin = intv - outtv;
tvprint = tvin /313;
remainder= tvin % 313;
outprint =  remainder + outtv;
mstvout = tvprint / ms * 1000;
msout = outprint / ms * 1000;
cout << "Frames in TeachyTV: ";
cout <<tvprint;
cout << "      ";
cout << "Frames Out of TeachyTV: ";
cout <<outprint<<endl;
cout << "Total Frames: ";
cout <<tvprint + outprint<<endl;
cout.precision(0);
cout.setf(ios_base::fixed);
cout << "Milliseconds in TeachyTV: ";
cout <<mstvout;
cout << "      ";
cout << "Milliseconds Out of TeachyTV: ";
cout << msout<<endl;
cout << "Total Milliseconds: ";
cout << msout + mstvout<<endl;

cout <<"Enter Frame hit: ";
cin >> hitframe;

adjtv = intv - hitframe;
adjtv2= adjtv / 313;
adjout = adjtv % 313;
if( adjout > 156){
adjout = 313 - adjout;
adjtv2--;
} else if ( adjout < -156){
adjout = 313 + adjout;
adjtv2--;

}

cout <<"Adjust TeachyTV by: ";
cout <<adjtv2;
cout << "      ";
cout <<"Adjust out of TeachyTV frames by: ";
cout <<adjout<<endl;
cout <<"Adjust TeachyTV MS by: ";
cout <<adjtv2 / ms * 1000;
cout << "      ";
cout << "Adjust out of TeachyTV Ms by: ";
cout <<adjout / ms *1000;
cin>> donttype;
    return 0;
}
