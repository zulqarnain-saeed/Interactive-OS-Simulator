#pragma once
#include <iostream>
#include <string>
#include "Process.h"

using namespace std;

// Abstract base class (Concept 12)
class Scheduler {
protected:
    Process** processQueue;  
    int queueCapacity;
    int processCount;

public:
    
    Scheduler(int capacity);

    
    virtual ~Scheduler();

    virtual void addProcess(Process* p) = 0;  
    virtual void schedule() = 0; 

    
    virtual void displayQueue() const;

   
    int getProcessCount() const;

   
    static int schedulerCreatedCount;
};