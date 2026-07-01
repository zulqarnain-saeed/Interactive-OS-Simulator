#include "DeviceManager.h"


Device::Device(string name) : deviceName(name), busy(false), currentProcess(nullptr) {}

string Device::getDeviceName() const { return deviceName; }
bool Device::isBusy() const { return busy; }
Process* Device::getCurrentProcess() const { return currentProcess; }

bool Device::allocate(Process* p) {
    if (!busy && p != nullptr) {
        busy = true;
        currentProcess = p;  
        cout << "Device " << deviceName << " allocated to Process "
            << p->getPID() << endl;
        return true;
    }
    return false;
}

void Device::release() {
    busy = false;
    if (currentProcess != nullptr) {
        cout << "Device " << deviceName << " released from Process "
            << currentProcess->getPID() << endl;
    }
    currentProcess = nullptr;
}

void Device::displayStatus() const {
    cout << "Device: " << deviceName
        << ", Status: " << (busy ? "Busy" : "Free");
    if (busy && currentProcess != nullptr) {
        cout << ", Used by Process: " << currentProcess->getPID();
    }
    cout << endl;
}


DeviceManager::DeviceManager() : deviceCount(0) {
    for (int i = 0; i < 5; i++) {
        devices[i] = nullptr;
    }
}

void DeviceManager::addDevice(Device* d) {
    if (deviceCount < 5) {
        devices[deviceCount] = d;
        deviceCount++;
    }
}

bool DeviceManager::allocateDevice(string deviceName, Process* p) {
    for (int i = 0; i < deviceCount; i++) {
        if (devices[i]->getDeviceName() == deviceName) {
            return devices[i]->allocate(p);
        }
    }
    return false;
}

void DeviceManager::releaseDevice(string deviceName) {
    for (int i = 0; i < deviceCount; i++) {
        if (devices[i]->getDeviceName() == deviceName) {
            devices[i]->release();
            return;
        }
    }
}

void DeviceManager::displayAllDevices() const {
    cout << "\n=== Device Status ===" << endl;
    for (int i = 0; i < deviceCount; i++) {
        devices[i]->displayStatus();
    }
}


void monitorDeviceManager(const DeviceManager& dm) {
    cout << "\n=== Friend Function Access ===" << endl;
    cout << "Total Devices: " << dm.deviceCount << endl;
    for (int i = 0; i < dm.deviceCount; i++) {
        if (dm.devices[i] != nullptr) {
            cout << "Device " << i << ": " << dm.devices[i]->deviceName;
            if (dm.devices[i]->busy) {
                cout << " (BUSY)" << endl;
            }
            else {
                cout << " (FREE)" << endl;
            }
        }
    }
}