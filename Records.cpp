#include "Records.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

/////////////// Student Class Implementation ///////////////
Student::Student()
{}

Student::Student(unsigned int student_ID, std::string name, unsigned short age)
{
    mStudentID = student_ID;
    mStudentName = name;
    mStudentAge = age;
}
    
unsigned int Student::getStudentID()
{
    return mStudentID;
}

std::string Student::getStudentName()
{
    return mStudentName;
}
    
unsigned short Student::getStudentAge()
{
    return mStudentAge;
}

Student::~Student()
{}

/////////////// MyManager Class Implementation ///////////////
MyManager::MyManager()
{}

MyManager::MyManager(std::vector<Student *> vector)
{
    studentRecords = vector;
}

void MyManager::Add(std::vector<std::string> parsed_command) //unsigned studentID, std::string Name, unsigned short Age
{
    int intID = std::stoul(parsed_command[1]);
    unsigned int ID = (unsigned int)intID;
    
    int intAGE = std::stoi(parsed_command[3]);
    unsigned short age = (unsigned short)intAGE;

    Student *sPtr = new Student(ID, parsed_command[2], age);
    studentRecords.push_back(sPtr);
}

void MyManager::Find(std::vector<std::string> parsed_command)
{   
    if(parsed_command[1] == "id"){
        int intID = std::stoul(parsed_command[3]);
        unsigned int ID = (unsigned int)intID;

        //all "id" conditions
        if(parsed_command[2] == "="){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentID() == ID){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                            studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
        else if(parsed_command[2] == ">"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentID() > ID){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                            studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
        else if(parsed_command[2] == "<"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentID() < ID){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                            studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
    }

    else if(parsed_command[1] == "name"){
        //names only possible condition
        if(parsed_command[2] == "="){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentName() == parsed_command[3]){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                    studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
    }

    else if(parsed_command[1] == "age"){
        int intAGE = std::stoi(parsed_command[3]);
        unsigned short age = (unsigned short)intAGE;

        //all age conditions
        if(parsed_command[2] == "="){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentAge() == age){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                    studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
        else if(parsed_command[2] == ">"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentAge() > age){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                    studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
        else if(parsed_command[2] == "<"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentAge() < age){
                    std::cout << studentRecords[i]->getStudentID() << "\t" <<
                    studentRecords[i]->getStudentName() << "\t" << studentRecords[i]->getStudentAge() << std::endl;
                }
            }
        }
    }
}

void MyManager::Remove(std::vector<std::string> parsed_command)
{
    if(parsed_command[1] == "id"){
        int intID = std::stoul(parsed_command[3]);
        unsigned int ID = (unsigned int)intID;

        //all id conditions
        if(parsed_command[2] == ">"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentID() > ID){
		    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            }
        }
        if(parsed_command[2] == "="){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentID() == ID){
                    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            }
        }
        if(parsed_command[2] == "<"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentID() < ID){
		    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            }
        }
    }

    else if(parsed_command[1] == "name"){
        if(parsed_command[2] == "="){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentName() == parsed_command[3]){
		    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            } 
        }
    }

    else if(parsed_command[1] == "age"){
        int intAGE = std::stoi(parsed_command[3]);
        unsigned short age = (unsigned short)intAGE;

        //all age conditions
        if(parsed_command[2] == ">"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentAge() > age){
		    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            }
        }
        if(parsed_command[2] == "="){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentAge() == age){
		    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            }
        }
        if(parsed_command[2] == "<"){
            for(int i=0; i<studentRecords.size(); i++){
                if(studentRecords[i]->getStudentAge() < age){
		    delete studentRecords[i];
                    studentRecords.erase(studentRecords.begin()+i);
                    i--;
                }
            }
        }
    }    
}

void MyManager::Stop()
{
    HardDisk hardrive;
    hardrive.write_f(studentRecords);
}

bool MyManager::Process(std::vector<std::string> parsed_command)    //will call the above ADD, FIND, REMOVE, STOP functions
{
    Parser parse;

    if (parsed_command.size() == 0){
        std::cout << "Invalid command" << std::endl;
        return false;
    }
    if (parsed_command.size() > 4){
        std::cout << "Invalid command" << std::endl;
        return false;
    }
    if(parsed_command[0] == "STOP"){
        Stop();
        return true;    //shouldStop becomes true --> while(!=true), therefore ends program
    }

//=======================================================================================================================//  

    else if(parsed_command[0] == "ADD"){
        for (int i=0; i<parsed_command[1].size(); i++){
            if(isdigit(parsed_command[1][i]) == false){
                std::cout << "Invalid second token [1] when using ADD" << std::endl;
                return false;
            }
        }
        for (int i=0; i<parsed_command[2].size(); i++){
            if(isalpha(parsed_command[2][i]) == false && parsed_command[2][i] != '-' && parsed_command[2][i] != ',' && parsed_command[2][i] != ' ' && parsed_command[2][i] != '.'){
                std::cout << "Invalid third token [2] when using ADD" << std::endl;
                return false;
            }
        }
        for (int i=0; i<parsed_command[3].size(); i++){
            if(isdigit(parsed_command[3][i]) == false){
                std::cout << "Invalid fourth token [3] when using ADD" << std::endl;
                return false;
            }
        }
        ///// ^^^^^ Check for invalid [1], [2], and [3] above ^^^^^ /////

        Add(parsed_command);
        return false;
    }

//=======================================================================================================================//

    else if(parsed_command[0] == "FIND"){
        if(parsed_command[1] != "id" && parsed_command[1] != "name" && parsed_command[1] != "age"){
            std::cout << "Invalid second token [1] when using FIND" << std::endl;
            return false;
        }
        if(parsed_command[2] != ">" && parsed_command[2] != "=" && parsed_command[2] != "<"){
            std::cout << "Invalid third token [2] when using FIND and (id, name, or age)" << std::endl;
            return false;
        }
        ///// ^^^^^ Check for invalid [1] and [2] above ^^^^^ /////

        if(parsed_command[1] == "id" || parsed_command[1] == "age"){
            for(int i=0; i<parsed_command[3].size(); i++){
                if(isdigit(parsed_command[3][i]) == false){
                    std::cout << "Invalid fourth token [3] when using FIND and (id or age)" << std::endl;
                    return false;
                }
            }
        }
        if(parsed_command[1] == "name"){
            for(int i=0; i<parsed_command[3].size(); i++){
                if(isalpha(parsed_command[3][i]) == false && parsed_command[3][i] != ',' && parsed_command[3][i] != '-' && parsed_command[3][i] != ' ' && parsed_command[3][i] != '.'){
                    std::cout << "parsed_command[3][i] = " << parsed_command[3][i] << "Invalid fourth token [3] when using FIND and name" << std::endl;
                    return false;
                }
            }
        }
        ///// ^^^^^ Check for invalid [3] above ^^^^^ //////

        Find(parsed_command);
        return false;
    }

//=======================================================================================================================//

    else if(parsed_command[0] == "REMOVE"){
        if(parsed_command[1] != "id" && parsed_command[1] == "name" && parsed_command[1] == "age"){
            std::cout << "Invalid second token [1] when using REMOVE" << std::endl;
            return false;
        }
        else if(parsed_command[2] != ">" && parsed_command[2] != "=" && parsed_command[2] != "<"){
            std::cout << "Invalid third token [2] when using REMOVE and (id, name, or age)" << std::endl;
            return false;
        }
        ///// ^^^^^ Check for invalid [1] and [2] above ^^^^^ /////

        if(parsed_command[1] == "id" || parsed_command[1] == "age"){
            for(int i=0; i<parsed_command[3].size(); i++){
                if(isdigit(parsed_command[3][i]) == false){
                    std::cout << "Invalid fourth token [3] when using REMOVE and (id or age)" << std::endl;
                    return false;
                }
            }
        }
        if(parsed_command[1] == "name"){
            for(int i=0; i<parsed_command[3].size(); i++){
                if(isalpha(parsed_command[3][i]) == false && parsed_command[3][i] != ',' && parsed_command[3][i] != '-' && parsed_command[3][i] != ' ' && parsed_command[3][i] != '.'){
                    std::cout << "Invalid fourth token [3] when using REMOVE and name" << std::endl;
                    return false;
                }
            }
        }
        ///// ^^^^^ Check for invalid [3] above ^^^^^ //////

        Remove(parsed_command);
        return false;
    }

//=======================================================================================================================//

    else{
        std::cout << "Invalid command" << std::endl;
        return false;
        }
}

MyManager::~MyManager()
{
    for (unsigned int i=0; i < studentRecords.size(); i++){
        delete studentRecords[i];
        studentRecords[i] = nullptr;
    }    
}

/////////////// Parser Class Implemenation ///////////////
Parser::Parser()
{}

std::vector<std::string> Parser::operator()(std::string user_command)
{
    std::vector<std::string> tokenVec;
    std::vector<int> quoteVec;  // hold all the index positions that '"' occurs within user_command
    std::vector<std::string> emptyVec;
    std::string token = "";

    for (int i = 0; i < user_command.size(); i++){  //find quote index positions
        if(user_command[i] == '\"'){
            quoteVec.push_back(i);
        }
    }

    //early invalid-command checker
    if(user_command == "" || quoteVec.size() > 2 || quoteVec.size() == 1){
        return emptyVec; 
    }

    for (int i = 0; i < user_command.size(); i++){ 
        if(user_command[i] == ' ' && user_command[i+1] == ' '){
            continue;
        }
        else if(user_command[i] == '\"'){ 
            token = user_command.substr(i+1, quoteVec[1] - quoteVec[0] - 1);    //start after first quote, write until/before second quote
            i = quoteVec[1];  
        }
        else if (user_command[i] == '>' || user_command[i] == '<' || user_command[i] == '='){
            if(token != ""){
                tokenVec.push_back(token);
            }
            token = "";
            token = token + user_command[i];
            tokenVec.push_back(token);
            token = "";
        }
        else if(user_command[i] != ' ' && user_command[i] != '\t'){
            token = token + user_command[i];
        }
        else{
            if(token != ""){
                tokenVec.push_back(token);
            }
            token = "";
        }
    }
    tokenVec.push_back(token);  //required so that the final token will be pushed back

    return tokenVec;
}

Parser::~Parser()
{}

/////////////// HardDisk Class Implemenation ///////////////
HardDisk::HardDisk()
{}

std::vector<Student *> HardDisk::read_f()
{
    std::vector<Student *> studentVec;
    std::vector<std::string> tempRecord;
    Parser parse;

    std::fstream myFile;
    myFile.open("data.txt", std::ios::in);  //read mode
    if(myFile.is_open()){
        std::string line;
        while (getline(myFile, line)){
            if(line == ""){
                break;
            }
            tempRecord = parse(line);

            int intID = std::stoul(tempRecord[0]);
            unsigned int ID = (unsigned int)intID;

            int intAGE = std::stoi(tempRecord[2]);
            unsigned short age = (unsigned short)intAGE;

            Student *studentPtr = new Student(ID, tempRecord[1], age);
            studentVec.push_back(studentPtr);
        }
        myFile.close();
    }
    return studentVec;
}

void HardDisk::write_f(std::vector<Student *> students_info)
{
    std::fstream myFile;
    myFile.open("data.txt", std::ios::out); //write mode
    if(myFile.is_open()){
        for(int i=0; i<students_info.size(); i++){
            myFile << students_info[i]->getStudentID() << "\t" << '"' << students_info[i]->getStudentName() << '"' << "\t" << students_info[i]->getStudentAge() << std::endl;
        };
        myFile.close();
    }
}
    
HardDisk::~HardDisk()
{}