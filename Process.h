#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Process {
private:
    int pid;
    string name;
    int priority;
    int memoryRequired;
    int burstTime;

public:
    
    Process();  
    Process(int id, string n, int p, int mem, int bt);  
    Process(const Process& other);  

    
    ~Process();

    int getPID() const;
    string getName() const;
    int getPriority() const;
    int getMemoryRequired() const;
    int getBurstTime() const;

    void setPID(int id);
    void setName(string n);
    void setPriority(int p);
    void setMemoryRequired(int mem);
    void setBurstTime(int bt);

    
    bool operator==(const Process& other) const;
    Process operator+(const Process& other) const;

    
    friend void displayProcessDetails(const Process& p);

   
    void display() const;

    
    static int processCount;
    static int getTotalProcessCount();
};