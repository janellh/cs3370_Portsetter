// Project Prolog
// Name: JaNell Haynes
// CS3370-001
// Project: CO3
// Date: 9/23/16
// Purpose: https://docs.google.com/document/d/1kDnYljkGwzZTOQCnXeoo4deplvHXzM-BrY9PBz8GYow/edit
// 
// I declare that the following code was written by me or provided 
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive
// a zero on this project if I am found in violation of this policy.
// ---------------------------------------------------------------------------



#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <regex>

using namespace std;

enum {
    INCORRECT_ARGS,
    LISTENING, 
    PORT_OUT_RANGE,
    INCORRECT_FLAG 
};

// strings.c
string en[] = {
    "Incorrect arguments.",
    "Listening on Port: ",
    "Port Number out of range",
    "incorrect flag"
};

string es[] = {
   "indicador incorrecto",
   "Escucha en el puerto:",
   "Número de puerto fuera de rango",
   "indicador incorrecto"
};

string* msg = en; //defaults to English

void usageScreen(){
    string portsetter = "portsetter.usage_en.txt";
    if(msg == es){
        portsetter = "portsetter.usage_es.txt";
    }
    string input;
    ifstream myfile;
    myfile.open(portsetter);
    while(!myfile.eof()){
        getline(myfile, input);
        cout << input << endl;
    }
}

void about(){
    string portsetter_about = "portsetter.about_en.txt";
    if(msg == es){
        portsetter_about = "portsetter.about_es.txt";
    }
    string input;
    ifstream myfile;
    myfile.open(portsetter_about);
    while(!myfile.eof()){
        getline(myfile, input);
        cout << input << endl;
    }
}

void version(){
    const string VERSION = "1.3";
    cout << "version: " << VERSION << endl;
}

int main(int argc, char* args[]) {
    
    system("export PATH=./:$PATH");
    
    const int PORT = 3123; 
    const int MAXPORT = 65000;
    const int MINPORT = 1;
    
    string flag = "";
    string envFlag = "";
    
    char * language = getenv("LANGUAGE");
    char * lc_all = getenv("LC_ALL");
    char * lc_message = getenv("LC_MESSAGE");
    char * lang = getenv("LANG");

    if(language != NULL){
        //copy char * to string to use regex
        string s_language;
        if (language[strlen(language)-1] == '\0') s_language.append(language);
        else for(int i=0; i<strlen(language); i++) s_language.append(1,language[i]);
        
        smatch m;
        regex e("(^..)");
        regex_search (s_language,m,e);
        if(m[0] == "es"){
            msg = es;
            cout << "idioma español" << endl;
        }
        else if(m[0] != "en"){
            cout << "program does not support language. default english." << endl;
        }
    }
    else if(lc_all != ""){
        //copy char * to string to use regex
        string s_lc_all;
        if (language[strlen(language)-1] == '\0') s_lc_all.append(language);
        else for(int i=0; i<strlen(language); i++) s_lc_all.append(1,language[i]);
        
        smatch m;
        regex e("(^..)");
        regex_search (s_lc_all,m,e);
        if(m[0] == "es"){
            msg = es;
            cout << "idioma español" << endl;
        }
        else if(m[0] != "en"){
            cout << "program does not support language. default english." << endl;
        }
    }
    else if (lc_message == "C"){
        //copy char * to string to use regex
        string s_lc_message;
        if (language[strlen(language)-1] == '\0') s_lc_message.append(language);
        else for(int i=0; i<strlen(language); i++) s_lc_message.append(1,language[i]);
        
        smatch m;
        regex e("(^..)");
        regex_search (s_lc_message,m,e);
        if(m[0] == "es"){
            msg = es;
            cout << "idioma español" << endl;
        }
        else if(m[0] != "en"){
            cout << "program does not support language. default english." << endl;
        }
    }
    else{ //lang
        //copy char * to string to use regex
        string s_lang;
        if (language[strlen(language)-1] == '\0') s_lang.append(language);
        else for(int i=0; i<strlen(language); i++) s_lang.append(1,language[i]);
        
        smatch m;
        regex e("(^..)");
        regex_search (s_lang,m,e);
        if(m[0] == "es"){
            msg = es;
            cout << "idioma español" << endl;
        } 
        else if(m[0] != "en"){
            cout << "program does not support language. default english." << endl;
        }
    }

    if(argc <= 1)
    {
        usageScreen();
        return 0;
    }

    if (argc >= 5){
        cout << msg[INCORRECT_ARGS] << endl;
       //cout << "Incorrect arguments.\n";
       usageScreen();
       return 1;
    }
    
    flag = args[1];
    if (argc == 2){
        
        if (flag == "-!" || flag == "--about"){
            about();
            return 0;
        }
        if(flag == "-v" || flag == "--version"){
            version();
            return 0;
        }
        if (flag == "-h" || flag == "--help" || flag == "-?"){
            usageScreen();
            return 0;
        }
        cout << msg[INCORRECT_ARGS] << endl;
        //cout << "Incorrect arguments.\n";
        usageScreen();
        return 1;
    }

    envFlag = args[2];
    //has enviroment variable
    if(envFlag == "-e" || envFlag == "--environment"){
        if(flag == "-p" || flag == "--port"){
            int i_envPort;
            string::size_type sz;   // alias of size_t
            
            if(argc == 4){
                string envPort = getenv(args[3]);
                try
                {
                    i_envPort = stoi (envPort, &sz);
                }
                catch(exception e)
                {
                    cout << msg[INCORRECT_ARGS] << endl;
                    //cout << "Incorrect arguments." << endl;
                    usageScreen();
                    return 1;
                }
                cout << msg[LISTENING] << i_envPort << endl;
                //cout << "Listening on port: " << i_envPort << endl;
                return 0;
            }
            else{
                try {
                        i_envPort = stoi (getenv("PORT"), &sz);
                }
                catch (...) {
                    cout << msg[INCORRECT_ARGS] << endl;
                    //cout << "Incorrect arguments." << endl;
                    usageScreen();
                    return 1;
                }
                cout << msg[LISTENING] << i_envPort << endl;
                //cout << "Listening on port: " << PORT << endl;
                return 0;
            }
           
        }   
    }
    if(argc == 4){
        cout << msg[INCORRECT_ARGS] << endl;
        //cout << "Incorrect arguments.\n";
        usageScreen();
        return 1;
    }
    if(argc == 3){
        string portNumb = args[2];
        string::size_type sz;   // alias of size_t
        int i_portNumb;
        
        try
        {
            i_portNumb = stoi (portNumb, &sz);
        }
        catch(exception e)
        {
            cout << msg[INCORRECT_ARGS] << endl;
            //cout << "Incorrect arguments." << endl;
            usageScreen();
            return 1;
        }
        if(i_portNumb < MINPORT || i_portNumb > MAXPORT)
        {
            cout << msg[PORT_OUT_RANGE] << endl;
            //cout << "Port Number out of range" << endl;
            usageScreen();
            return 3;
        }
        if (flag == "-!" || flag == "--about"){
            about();
            return 0;
        }
        if (flag == "-p" || flag == "--port"){
            cout << msg[LISTENING] << i_portNumb << endl;
            //cout << "Listening on port: " << portNumb << endl;
            return 0;
        } 
        else{
            cout << msg[INCORRECT_FLAG] << endl;
            //cout << "incorrect flag" << endl;
            usageScreen();
            return 2;
        }
    }
    
    return 0;
}
