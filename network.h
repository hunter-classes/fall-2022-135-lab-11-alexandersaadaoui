#pragma once
#include <string>
#include "profile.h"

class Network {
private:
    static const int MAX_USERS = 20; 
    int numUsers;                    
    Profile profiles[MAX_USERS];     
    bool following[MAX_USERS][MAX_USERS];    // new 
    int findID (std::string usrn);
public:
    Network();
    bool addUser(std::string usrn, std::string dspn);
    bool follow(std::string usrn1, std::string usrn2); // new
    void printDot();                         // new
};