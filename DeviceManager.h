#pragma once
#include <iostream>
#include <string>
#include "Process.h"

using namespace std;

class Device {
public:
    string deviceName;
    bool busy;
    Process* currentProcess;  // Association

public:
    Device(string name);

    string getDeviceName() const;
    bool isBusy() const;
    Process* getCurrentProcess() const;

    bool allocate(Process* p);
    void release();

    void displayStatus() const;
};

class DeviceManager {
private:
    Device* devices[5];
    int deviceCount;

public:
    DeviceManager();

    void addDevice(Device* d);
    bool allocateDevice(string deviceName, Process* p);
    void releaseDevice(string deviceName);
    void displayAllDevices() const;

    
    friend void monitorDeviceManager(const DeviceManager& dm);
};