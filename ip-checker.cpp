#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class CheckString{

public:
    vector<int> extractIntegers(string str){
        vector<int> integers;
        string temp = "";

        for(int i=0;i<str.length();i++){
            if( isdigit(str.at(i)) ){
                for(int j=i;j<str.length();j++){
                    if( isdigit(str.at(j)) ) {
                        temp += str.at(j);
                        i=j;
                    }
                    else{
                        i=j;
                        integers.push_back(stod(temp));
                        temp="";
                        break;
                    }
                }
            }
        }
        if(temp.size()!=0){
            integers.push_back(stod(temp));
        }
        return integers;
    }


    bool limit0_255 (int x){
        if(x>=0 && x<256)
            return true;
        return false;
    }

    bool checkIPV4 (string str){

        vector<int> ints;

        for(int i=0;i<str.length();i++)
            if(str.at(i) != '.' && str.at(i) != ':' && !isdigit(str.at(i)) )
                return false;

        if (str.length() < 7 || str.length() > 21){
            return false;
        }
        else{
            ints = extractIntegers(str);
            if(ints.size() != 4 && ints.size() != 5){
                return false;
            }
            else{
                if(ints.size() == 4){
                    if(limit0_255(ints.at(0)) && limit0_255(ints.at(1)) &&
                       limit0_255(ints.at(2)) && limit0_255(ints.at(3)) )
                        return true;
                    else
                        return false;
                }
                else{ //== 5
                    if(limit0_255(ints.at(0)) && limit0_255(ints.at(1)) &&
                       limit0_255(ints.at(2)) && limit0_255(ints.at(3)) &&
                       ints.at(4) >=0 && ints.at(4) <=65535)
                        return true;
                    else
                        return false;
                }
            }

        }
    }

private:
    bool isValidChar(char ch){
        string validChars = "ABCDEFabcdef1234567890";
        for(int i=0;i<validChars.length();i++)
            if(ch == validChars.at(i))
                return true;
        return false;
    }

public:
    bool checkColor(string str){

        if(str.length() != 7)
            return false;
        else{
            if(str.at(0) != '#')
                return false;
            else{
                for(int i=1;i<str.length();i++){
                    if(!isValidChar(str.at(i)))
                        return false;
                }
                return true;
            }
        }
    }

};


int main(){

    CheckString cs;
    string str = "192.168.1.1:80";
    string str2 = "192.168.123.1.1:80";
    string str3 = "192.168.1234.1:80";
    string str6 = "192.168.1234.1:800000";
    string str4 = "192.168.123.1";
    string str5 = "192.16y8.123.1";

    string col1 = "#FFA653";
    string col2 = "#FFFFFF";
    string col3 = "#FFFFFF3";
    string col4 = "#FFFFF";
    string col5 = "#FFG987";
    string col6 = "#ff8765";

    if(cs.checkIPV4(str))
        cout<<"YES\n";
    else
        cout<< "No\n";

    if(cs.checkIPV4(str2))
        cout<<"YES\n";
    else
        cout<< "No\n";

    if(cs.checkIPV4(str3))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkIPV4(str6))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkIPV4(str4))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkIPV4(str5))
        cout<<"YES\n";
    else
        cout<< "No\n\n";


    if(cs.checkColor(col1))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkColor(col2))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkColor(col3))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkColor(col4))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkColor(col5))
        cout<<"YES\n";
    else
        cout<< "No\n";
    if(cs.checkColor(col6))
        cout<<"YES\n";
    else
        cout<< "No\n";



}