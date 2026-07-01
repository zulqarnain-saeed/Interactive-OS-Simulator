#pragma once
#include "Scheduler.h"

class PriorityScheduler : public Scheduler {
public:
    PriorityScheduler(int capacity);

  
    void addProcess(Process* p) override;
    void schedule() override;

    
    void sortByPriority();
};