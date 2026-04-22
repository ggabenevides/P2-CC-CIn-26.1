#include <iostream>
#include <string>

int main(){
    //initialize a string s1 with the string "As time by..." 
    std::string s1("As time by...");
    //a second string s2 with the string "goes"
    std::string s2 ("goes ");
    //insert string s2 in front of "by" in string s1
    s1.insert(s1.find("by"), s2);
    //erase the remainder of string s1 after the substring "by"
    s1.erase(s1.find("..."));
    //replace the substring "time" in s1 with "Bill"
    std::string s3("time");
    s1.replace(s1.find("time"), s3.length(), "Bill");
    std::cout << s1 << std::endl;
}