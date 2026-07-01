#pragma once
#include "Scheduler.h"


class FCFSScheduler : public Scheduler {
public:
    
    FCFSScheduler(int capacity);

   
    void addProcess(Process* p) override;
    void schedule() override;

    
    void displayQueue() const override;
};