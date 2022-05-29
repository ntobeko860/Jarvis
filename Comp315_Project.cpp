
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>


using namespace std;

int main()
{
    string line;
    string group_members[5] = { "Bongiswa Ngcongo", "Khanyisile Momoti", "Ntobeko Hlongwa", "Manqoba Mlangeni", "Musa Sangweni" };

    /***** To covert the keyboard inputy tp lower case *****/
    std::cout << "Enter line here" << std::endl;
    getline(cin, line);

    for (int i = 0; i < line.length(); i++) {
        if (line[i] >= 'A' && line[i] <= 'Z') {
            line[i] = line[i] + 32;
        }
    }
    /*****************************************************/



    if (line == "hi jarvis" || line == "hello jarvis" || line == "hello" || line == "hi") {
        cout << "Hello Musa, How are you today";

    }
    else if (line == "how are you" || line == "how are you today") {
        cout << "I am doing good Sir, How about you? ";

    }
    else if (line == "thanks" || line == "thank you") {
        cout << "The pleasure is mine";

    }
    else if (line == "what is your name" || line == "who are you") {

        cout << "My name is Jarvis, I am virtual personal assistant" << endl;

    }
    else if (line == "who made you" || line == "who built you") {

        cout << "" << endl;
        for (const string& member : group_members) {
            cout << member << " " << endl;
            Sleep(500);
            cout << "" << endl;
        }
        cout << "Collectively built me to be of your service " << endl;

    }
    /************** Still need further refining*************/
    else if (line == "play song" || line == "song" ) { 
        //search(line, "song");    // call search (srch) function
    }
    else if (line == "help" ) {
        //help();                // call help function
    }
    else if (line == "cmd") {
        //system(s_word.c_str());    // call system function
    }
    else if (line == "youtube" || line == "videos" || line == "yt") {
        //search(line, "youtube")    // call search (srch) function
    }
    /************** Still need further refining*************/
    else if (line == "open chrome") {
        //openf(line)    // call openf function
        //system(start chrome);
    }
    else if (line == "exit" || line == "quit") {
        //x.speack("Good bye ");
        //exit(1)

    }
    else if (line == "shutdown" || line == "restart") {
        /*
        x.typing("Your PC will");
        x.typing(line);

        if (line == "shutdown") 
            system("shutdown /s");

        else 
            system("shutdown /r");
            exit(1)
        
        */
    
    }
    else if (line == "find my ip address" || line == "my ip address" || line == "ip address") {
        /*
        x.typing("Finding your IP address");
        Sleep(700)
        system("ipconfig");
        system("pause");
        */
   
    
    }
    else {
        // x.speack("Sorry Sir, that is an unknown command...");
        //cnt++
        /*
        x.speack()
        */
    }


    //Sleep(700);
    //repeat();
    system("pause>0");
    return 0;

}