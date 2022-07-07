#pragma once
#include <vector>
#include <string>


class Student
{
public:
    Student();
    Student(unsigned int student_ID, std::string name, unsigned short age);  //: mStudentID(student_ID), mName(name), mAge(age) {}
    unsigned int getStudentID();
    std::string getStudentName();
    unsigned short getStudentAge();
    ~Student();
private:
    unsigned int mStudentID;
    std::string mStudentName;
    unsigned short mStudentAge;
};


class MyManager
{
public:
    MyManager();
    MyManager(std::vector<Student *> vector);
    void Add(std::vector<std::string> parsed_command); //unsigned studentID, std::string Name, unsigned short Age
    void Find(std::vector<std::string> parsed_command);
    void Remove(std::vector<std::string> parsed_command);
    void Stop();
    bool Process(std::vector<std::string> parsed_command);    //will call the above methods, check [0] for command, do if's
    std::vector<Student *> read_f(std::string line);
    ~MyManager();
private:
   std::vector<Student *> studentRecords;
};


class Parser
{
public:
    Parser();   //if given a default constructor, use sepSymbol member for your seperators
    std::vector<std::string> operator()(std::string user_command);
    ~Parser();
private:
};


class HardDisk
{
public:
    HardDisk();
    std::vector<Student *> read_f();
    void write_f(std::vector<Student *> students_info);
    ~HardDisk();
private:
};