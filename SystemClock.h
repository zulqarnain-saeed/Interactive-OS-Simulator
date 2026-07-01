#pragma once
#include <iostream>

using namespace std;

class SystemClock {
private:
    static SystemClock* instance; 
    int time;

   
    SystemClock();

public:
   
    static SystemClock* getInstance();

    
    SystemClock(const SystemClock&) = delete;
    void operator=(const SystemClock&) = delete;

   
    int getTime() const;

    
    void tick(int increment = 1);

   
    void reset();
};