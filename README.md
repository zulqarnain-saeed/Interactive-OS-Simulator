# Interactive OS Simulator

A modular **Operating System Simulator** developed in **C++** using **Object-Oriented Programming (OOP)** principles. The project simulates fundamental operating system components, including **process scheduling**, **memory management**, **device management**, **file system operations**, and a **system clock**, providing an interactive environment to understand how an operating system manages system resources.

---

## Overview

The Interactive OS Simulator is an educational project designed to demonstrate the internal workings of an operating system through a command-line interface.

Instead of interacting with actual hardware, the simulator models how an operating system coordinates processes, allocates memory, schedules CPU execution, manages devices, and organizes files.

The project emphasizes clean software architecture, modular design, and object-oriented programming concepts.

---

# Features

### Process Management

* Create and manage multiple processes.
* Assign unique Process IDs (PID).
* Track process states:

  * Ready
  * Running
  * Waiting
  * Terminated
* Configure execution cycles and memory requirements.

### CPU Scheduling

Supports multiple scheduling algorithms:

* First Come First Served (FCFS)
* Priority Scheduling

The scheduler selects the next process according to the currently selected scheduling policy.

### Memory Management

* Dynamic RAM allocation
* Memory block management
* Memory deallocation
* Allocation validation
* Memory usage visualization

### Device Management

Simulates hardware devices and I/O operations.

Features include:

* Device registration
* Device locking
* I/O request handling
* Waiting queues
* Resource release

### File System Simulation

Provides a simplified virtual file system capable of:

* Creating files
* Reading files
* Writing files
* Managing directories
* Tracking file sizes

### System Clock

The simulator operates using a centralized system clock that:

* Advances simulation time
* Updates process execution
* Synchronizes all subsystems
* Controls execution cycles

### Interactive Command-Line Interface

Users can:

* Select scheduling algorithms
* Create processes
* Execute simulation cycles
* Monitor memory usage
* Inspect devices
* View process states
* Interact with the virtual operating system

---

# System Architecture

```text
                     +----------------------+
                     |     SystemClock      |
                     +----------+-----------+
                                |
                                v
                     +----------------------+
                     |     Main Simulator   |
                     +---+-----------+------+
                         |           |
         +---------------+           +----------------+
         |                                    |
         v                                    v
+--------------------+              +--------------------+
|    Scheduler       |              |   MemoryManager    |
+--------------------+              +--------------------+
         |                                    |
         |                                    |
         v                                    v
+--------------------+              +--------------------+
|      Process       |              |    MemoryBlock     |
+--------------------+              +--------------------+
         |
         |
         +----------------+
                          |
                          v
                 +--------------------+
                 |   DeviceManager    |
                 +--------------------+
                          |
                          v
                 +--------------------+
                 |    FileSystem      |
                 +--------------------+
```

---

# Project Structure

```text
.
├── DeviceManager.cpp
├── DeviceManager.h
├── FCFSScheduler.cpp
├── FCFSScheduler.h
├── FileSystem.cpp
├── FileSystem.h
├── MemoryBlock.cpp
├── MemoryBlock.h
├── MemoryManager.cpp
├── MemoryManager.h
├── PriorityScheduler.cpp
├── PriorityScheduler.h
├── Process.cpp
├── Process.h
├── Scheduler.cpp
├── Scheduler.h
├── SystemClock.cpp
├── SystemClock.h
├── main11.cpp
└── README.md
```

---

# Technologies Used

* C++
* Object-Oriented Programming (OOP)
* Standard Template Library (STL)
* Dynamic Memory Allocation
* Command-Line Interface (CLI)

---

# Object-Oriented Concepts Implemented

The project demonstrates the following OOP principles:

* Encapsulation
* Abstraction
* Inheritance
* Polymorphism
* Composition
* Modular Design

---

# Scheduling Algorithms

## First Come First Served (FCFS)

Processes are executed in the order they arrive.

Characteristics:

* Non-preemptive
* Simple implementation
* Fair execution order

---

## Priority Scheduling

Processes with higher priority execute before lower-priority processes.

Characteristics:

* Priority-based execution
* Supports different workload importance
* Faster execution of critical processes

---

# Memory Management

The Memory Manager is responsible for:

* Allocating memory to new processes
* Releasing memory after process termination
* Tracking available memory blocks
* Preventing invalid allocations
* Displaying current memory usage

---

# Device Management

The Device Manager simulates hardware resources including:

* I/O devices
* Device allocation
* Waiting queues
* Resource locking
* Device release

---

# File System

The virtual file system supports:

* File creation
* File deletion
* File reading
* File writing
* Directory management

---

# System Clock

Every simulation cycle represents one operating system clock tick.

During each tick:

* Running processes execute
* Waiting processes are updated
* Completed processes terminate
* Memory is released
* Device queues are refreshed

---

# Getting Started

## Prerequisites

* C++11 or later
* GCC / G++ / Clang / MSVC

---

## Compilation

Compile the project using G++:

```bash
g++ -std=c++11 *.cpp -o OSSimulator
```

---

## Run

Linux / macOS

```bash
./OSSimulator
```

Windows

```bash
OSSimulator.exe
```

---

# Example Workflow

1. Launch the simulator.
2. Select a scheduling algorithm.
3. Create one or more processes.
4. Allocate memory.
5. Execute simulation ticks.
6. Observe process scheduling.
7. Monitor memory usage.
8. Perform file operations.
9. Simulate device requests.
10. Continue until all processes terminate.

---

# Learning Outcomes

This project helps demonstrate concepts from:

* Object-Oriented Programming
* Operating Systems
* Process Scheduling
* Memory Management
* File Systems
* Device Management
* Software Design
* Data Structures

---

# Future Improvements

Potential enhancements include:

* Round Robin Scheduling
* Shortest Job First (SJF)
* Multi-Level Queue Scheduling
* Paging
* Virtual Memory
* Deadlock Detection
* Process Synchronization
* Multithreading
* GUI Version (Qt or SFML)
* Persistent File Storage
* Logging System

---

# License

This project is intended for educational purposes.

You are welcome to study, modify, and extend the project for learning and academic use.

---

# Authors

**Zulqarnain Saeed**

Bachelor of Science in Computer Science

Object-Oriented Programming Semester Project
