//main class
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<cstring>
#include<process.h>
#include <unistd.h>
#include<windows.h>
#include "assistant.h"

using namespace std;

//------------------global variables----------------
string input;

int pos ,l_pos,cnt=0;
string user_input ,s_word;
int s_count=0;
assistant x; //  main  object

//---------------------all functions-------------------------

void check();   //compare the user input with defined commands
void repeat();     //ask user input again.
void shutdown_timer(int);//shutdown timer
void line(); //new line
void player(string);  //search the song from file(songs.txt) then play the song.
void help();          //show commands
void block(string);  //block the websites
void openf(string);   // open the file directory
void lists(string);   //show song list
void convert(string&);   //convert 'space( )' to 'underscore'( _ ) and lowercase string
void search(string,string extra="");
void update_song(string);   //copy song name from different files(list.txt) file into one file(songs.txt)


int main()
{
    x.clock();
    x.greeting();
    repeat();

    return 0;
}

//-----------------------------Repeat function-------------------------//
void repeat()
{
  system("color a");
  system("cls");
  x.clock();


cout<<" \n\n\nType Here : ";
cin.clear();
getline(cin,input);   // get command from user
pos = input.find(" ");
user_input = input.substr(); //main command word
l_pos = input.find('\0');
s_word = input.substr(pos+1,l_pos); //rest word


//-----------check conditions--------------//
check();
}

//----------------------------check function---------------------------//
void check()
{
   int array_size = 5;
    string group_members[array_size] = { "Bongiswa Ngcongo", "Khanyisile Momoti", "Ntobeko Hlongwa", "Manqoba Mlangeni", "Sphamandla Sangweni"};

    /***** To covert the keyboard inputy to lower case *****/
    for (int i = 0; i < user_input.length(); i++) {
        if (user_input[i] >= 'A' && user_input[i] <= 'Z')
            user_input[i] = user_input[i] + 32;
    }

    if (user_input == "hi jarvis" || user_input == "hello jarvis" || user_input == "hello" || user_input == "hi") {
	    x.typing("Hello,how may I be at your service today? ");

    }
    else if (user_input == "how are you?" || user_input == "how are you today?") {
	    x.typing("I am doing good, how about you?");

    }
    else if (user_input == "thanks" || user_input == "thank you") {
	    x.typing("The pleasure is mine");
    }

    else if (user_input == "what is your name?" || user_input == "who are you?") {
	    x.typing("My name is Jarvis, I am virtual personal assistant made by UKZN developers");
    }

    else if (user_input == "who made you?" || user_input == "who built you?") {

        cout << "" << endl;
        for (int i = 0; i < array_size; i++) {
            x.typing(group_members[i]);
            cout << " " << endl;
            Sleep(500);
        }
        cout << "" << endl;
	    x.typing("Collectively built me to be of your service");
    }
    else if (user_input == "play song" || user_input == "song" ) {
       search(user_input, "song");    // call search function
    }
    else if (user_input == "help" ) {
        help();                // call help function
    }
    else if (user_input == "cmd") {
        system(s_word.c_str());    // call system function
    }
    else if (user_input == "youtube" || user_input == "videos" || user_input == "yt") {
      search(user_input, "youtube");    // call search function
    }

    else if (user_input == "open chrome") {
        openf(user_input);    // call openf function
        system("start chrome");
    }
    else if (user_input == "exit" || user_input == "quit") {
        x.speak("Good bye ");
        exit(1);
    }
    else if (user_input == "shutdown" || user_input == "restart") {

        x.typing("Your PC will");
        x.typing(user_input);
        if (user_input == "shutdown")
            system("shutdown /s");
        else
            system("shutdown /r");
            exit(1);
    }
    else if (user_input == "find my ip address" || user_input == "my ip address" || user_input == "ip address") {

        x.typing("Finding your IP address");
        Sleep(700);
        system("ipconfig");
        system("pause");

    }

    else {
        x.speak("Invalid command, please try again");
        cnt++;
    }

    Sleep(700);
    repeat();
}

//------------------------------convert string-------------------------//
void convert(string &c)
{

    for (int i=0;c[i]!='\0';i++)
        {
            if(c[i]==' ')
               c[i]='_';
            c[i]=tolower(c[i]);
        }
}

//------------------------timer function--------------

// function to display the timer
void displayClock(int seconds)
{
	int hour,minute;
	hour=minute=0;
	// system call to clear the screen
	system("cls");
	cout<<"\n\n";
	cout << setfill(' ') << setw(75) << "	        TIMER	      	\n";
	cout << setfill(' ') << setw(75) << " --------------------------\n";
	cout << setfill(' ') << setw(29);
	cout << "| " << setfill('0') << setw(2) << hour << " hour | ";
	cout << setfill('0') << setw(2) << minute << " minute | ";
	cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
	cout << setfill(' ') << setw(75) << " --------------------------\n";
}
//-----------shutdown timer-----------------------
void shutdown_timer(int t)
{
	while (t)
     {
		 displayClock(t);
		 Sleep(900);
		 t--;
     }
}

//----------------online searching and downloading songs----------------

void search(string query,string extra)  //Searching function with two arguments which will take a query from the user and extra to take what was queried
{
          for(int i=0;query[i]!='\0';i++)
              {
                  if(query[i]==' ')
                    query[i]='+';
              }

            Sleep(300);                     //sleep time
            system("cls");                  //using system function to cear screen
            line();
            x.typing("verifying internet connection....");
            if (s_count%5==0)               //if statement to count
            {
                //line();
		cout<<endl;
                Sleep(90);
                cout<<"Colleting info..\n";
                Sleep(50);
                cout<<"securing the data..\n";
                Sleep(30);
                cout<<"clear the cookies..\n";
                Sleep(100);
                system("ipconfig");
                cout<<endl;
                x.typing("All protocols are secured...");
            }

            Sleep(250);
            x.speak("Connecting to your browser.");
            string url;
           // opening youtube
            if(extra == "youtube")
            {
                url= "start https://www.youtube.com/results?search_query=";
                url+=query;
                system(string(url).c_str());
            }
            else if(extra == "song")
            {
                url= "start https://en.muzmo.org/search?q=";
                url+=query;
                system(string(url).c_str());
                Sleep(50);

                url= "start https://m.soundcloud.com/search?q=";
                url+=query;
                system(string(url).c_str());

            }
            else if(extra == "pdf")
            {
                url= "start https://www.google.com/search?q=filetype%3Apdf+";
                url+=query;
                system(string(url).c_str());
            }

            else
            {
                url="start https://www.google.com/search?q=";
                url+=query;
                system(string(url).c_str());
            }

            s_count++;
}
//-----------------newline function----------------
void line()
{
    cout<<"\n";
}

//---------block unsecured websites------------------
void block(string website)
{
    fstream file;
    file.open("C:\\WINDOWS\\system32\\drivers\\etc\\hosts",ios::app);
    file<<"\n127.0.0.2 www."<<website;
    x.typing("Blocking the website..");
    file.close();
}
//--------------locate  the file---------------
void openf(string location)
{
string path="start ",item=location;
convert(item);
path += item;
x.typing("Open....");
x.typing(location);
system(string(path).c_str());
}

//----------------------help file---------------------
void help()
{
cnt=0;
x.speak("you can use only these cammands");
system("cls");
cout<<"\n\n";
system("color f");
line();
cout << setfill(' ') << setw(75) <<"----------------------------\n";
cout << setfill(' ') << setw(75) <<"          Commands          \n";
cout << setfill(' ') << setw(75) <<"--------------------------\n\n";
cout << setfill(' ') << setw(75) <<"    1.search (any question)  \n";
cout << setfill(' ') << setw(75) <<"    2.open (google,mozilla)  \n";
cout << setfill(' ') << setw(75) <<"    3.block (website name)   \n";
cout << setfill(' ') << setw(75) <<"    4.song (song name)       \n";
cout << setfill(' ') << setw(75) <<"    5.update                 \n";
cout << setfill(' ') << setw(75) <<"    6.pdf (pdfname)          \n";
cout << setfill(' ') << setw(85) <<"    7.what/how/where/who/why (question)\n";
cout << setfill(' ') << setw(75) <<"   8.cmd (cmd commands)     \n";
cout << setfill(' ') << setw(75) <<"   9.find my ip             \n";
cout << setfill(' ') << setw(75) <<"   10.exit/quit/q            \n";
cout << setfill(' ') << setw(75) <<"   11.shutdown/restart       \n";
system("pause");
}


