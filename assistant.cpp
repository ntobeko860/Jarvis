//Assistant class
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cstring>
#include <ctype.h>
#include<windows.h>
#include<ctime>
#include "assistant.h"

using namespace std;

string greet; //variable
//constructor
assistant::assistant()
{

 system("md data");
 system("attrib +s +h data");
 system("cls");
 system("title   Jarvis");
}

//----------salutation function--------------
void assistant::greeting()
{
    system("color a");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t";
    cout<<"Welcome to the Jarvis ";
    Sleep(250);
    speak(greet);
    //system("color 0c");
    Sleep(500);
}

//--------------speak function--------------
void assistant::speak(string s)
{
ofstream file;
file.open("data//speak.vbs",ios::out);
file<<"dim s";
file<<"\nset s = createObject(\"sapi.spvoice\")";
file<<"\ns.speak \""<<s<<"\"";
file.close();
system("start data//speak.vbs");
Sleep(300);
}


//---------------typing function--------------
void assistant::typing(string t)
{
    speak(t);   //----------for speaking the text
for (int i=0;t[i]!='\0';i++)
   {
     cout<<t[i];
     Sleep(65);
   }
}

//----------------Full Date Function-----------
void assistant::clock()
{

    time_t now = time(0); // get current date and time
    tm* CAT = localtime(&now);

    cout << "Today's  date is " << 1900 + CAT->tm_year<< "-"<<1 + CAT->tm_mon<< "-"<<CAT->tm_mday << endl; // print the year

    // Print time in hour:minute:second
    cout << "Time: " << CAT->tm_hour << ":";
    cout <<  CAT->tm_min << ":";
    cout << CAT->tm_sec << endl;
    //tm*CAT = localtime(&now);

    if(CAT->tm_hour >=0 && CAT->tm_hour <12)
       string greet="Good morning";
    else if (CAT->tm_hour >=12 && CAT->tm_hour<14)
         string greet="Good day";
    else  if(CAT->tm_hour >=14 && CAT->tm_hour<18)
            greet="Good afternoon";
    else
            greet="Good Evening";


    cout<<"\t\t\t\t\t\t\t\t\t";
    cout<<greet;
}
assistant::~assistant()
{
    system("attrib +s +h data");
}
