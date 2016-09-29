#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {
    
    //positive tests
    
    //setport
    int statusCode = system("setport > output.txt") / 256;
    cout << "./setport: " << statusCode << endl;
    statusCode = system("diff help.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport: " << statusCode << endl;
    
    //setport -h
    statusCode = system("./setport -h > output.txt") / 256;
    cout << "./setport -h: " << statusCode << endl;
    statusCode = system("diff help.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -h: "<< statusCode << endl;
    
    //setport --help
    statusCode = system("./setport --help > output.txt") / 256;
    cout << "./setport --help: "<< statusCode << endl;
    statusCode = system("diff help.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport --help: "<< statusCode << endl;
    
    //setport -?
    statusCode = system("./setport -? > output.txt") / 256;
    cout << "./setport -?: "<< statusCode << endl;
    statusCode = system("diff help.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport ?: "<< statusCode << endl;
    
    //setport -p 4040
    statusCode = system("./setport -p 4040 > output.txt") / 256;
    cout << "./setport -p 4040: "<< statusCode << endl;
    statusCode = system("diff listening.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -p 4040: "<< statusCode << endl;
    
    //setport --port 4040
    statusCode = system("./setport --port 4040 > output.txt") / 256;
    cout << "./setport --port 4040: "<< statusCode << endl;
    statusCode = system("diff listening.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport --port 4040: "<< statusCode << endl;
    
    //negative tests
    
    //setport help
    statusCode = system("./setport help > output.txt") / 256;
    cout << "./setport help: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport help: " << statusCode << endl;
    
    //setport -help
    statusCode = system("./setport -help > output.txt") / 256;
    cout << "./setport -help: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -help: " << statusCode << endl;
    
    //setport --h
    statusCode = system("./setport --h > output.txt") / 256;
    cout << "./setport --h: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport --h: " << statusCode << endl;
    
    //setport -h --help
    statusCode = system("./setport -h --help > output.txt") / 256;
    cout << "./setport -h --help: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -h --help: " << statusCode << endl;
    
    //setport -hs
    statusCode = system("./setport -hs > output.txt") / 256;
    cout << "./setport -hs: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -hs: " << statusCode << endl;
    
    //setport -p --port 9
    statusCode = system("./setport -p --port 9 > output.txt") / 256;
    cout << "./setport -p --port 9: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -p --port 9: " << statusCode << endl;
    
    //setport -p 77 33
    statusCode = system("./setport -p 77 33 > output.txt") / 256;
    cout << "./setport -p 77 33: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -p 77 33: " << statusCode << endl;
    
    //setport -p -21
    statusCode = system("./setport -p -21 > output.txt") / 256;
    cout << "./setport -p -21: "<< statusCode;
    statusCode = system("diff port_out_range.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -p -21: " << statusCode << endl;
    
    //setport -p 0
    statusCode = system("./setport -p 0 > output.txt") / 256;
    cout << "./setport -p 0: "<< statusCode << endl;
    statusCode = system("diff port_out_range.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -p 0: " << statusCode << endl;
    
    //setport --port
    statusCode = system("./setport --port > output.txt") / 256;
    cout << "./setport --port: "<< statusCode << endl;
    statusCode = system("diff error_incorrect_args.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport --port: " << statusCode << endl;
    
    //setport -p 90642
    statusCode = system("./setport -p 90642 > output.txt") / 256;
    cout << "./setport -p 90642: "<< statusCode << endl;
    statusCode = system("diff port_out_range.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -p 90642: " << statusCode << endl;
    
    //setport -x 45321
    statusCode = system("./setport -x 45321 > output.txt") / 256;
    cout << "./setport -x 45321: "<< statusCode << endl;
    statusCode = system("diff incorrect_flag.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -x 45321: " << statusCode << endl;
    
    //setport -P 714
    statusCode = system("./setport -P 714 > output.txt") / 256;
    cout << "./setport -P 714: "<< statusCode << endl;
    statusCode = system("diff incorrect_flag.txt output.txt > /dev/null") / 256;
    cout << "diff ./setport -P 714: " << statusCode << endl;
    
    return 0;
}