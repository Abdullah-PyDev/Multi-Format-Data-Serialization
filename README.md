# Multi-Format Data Serialization System (C++)

[![C++](https://img.shields.io/badge/Language-C++-blue)](https://isocpp.org/) [![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)

This project implements a **Multi-Format Data Serialization System** in **C++**, designed to efficiently store and manage **heterogeneous sensor data**. It demonstrates a practical approach to handling **different data types in memory-efficient ways**, using **enums, unions, and dynamic memory allocation**.  

It is ideal for **scientific computing simulations, embedded systems, and backend applications**, where multiple sensor types must be processed and stored efficiently.

---

## Project Overview


In many real-world applications, such as **IoT sensor networks**, **scientific experiments**, or **embedded systems**, sensors generate **heterogeneous data** (integers, floating-point values, strings, or binary blobs). Storing these in a naive way can waste memory and reduce performance.  

This project addresses these challenges by:  

1. Using **enums** to identify the type of data safely at runtime.  
2. Using a **union** to store only the active data type, saving memory.  
3. Implementing a **struct (`SensorReading`)** to combine the type, value, sensor ID, and timestamp in a single object.  
4. Managing memory dynamically for variable-length strings, ensuring **no memory leaks**.  
5. Keeping a **global counter** of active readings to monitor usage.

By combining **low-level memory efficiency** with **object-oriented principles**, the system is **scalable, maintainable, and serialization-ready**, meaning it could easily be extended to store readings in a file or database.

---

## Features

- Stores multiple sensor data types:
  - **Integer readings (`int`)**  
  - **Floating-point readings (`double`)**  
  - **Status messages (`string`)**  
- **Type-safe design** using enums  
- **Memory-efficient storage** with unions  
- **Dynamic memory allocation** for variable-length data  
- **Global reading counter** for monitoring and debugging  
- **Serialization-ready architecture** for persistent storage  
- Demonstrates **OOP principles**: encapsulation, abstraction, and clean design  

---

## How It Works

1. **Create a new reading**: `createReading(sensorId)`  
2. **Assign a value**:  
   - `setIntValue(...)`  
   - `setDoubleValue(...)`  
   - `setStringValue(...)`  
3. **Display readings**: `displayReading(...)`  
4. **Delete readings**: `deleteReading(...)` – frees memory safely  

The program also outputs **memory usage statistics**, showing the savings from using a **union** instead of separate fields for each type.

---

## Benefits

- **Memory Efficiency**: Only the active data type occupies memory.  
- **Scalability**: Supports hundreds or thousands of sensor readings dynamically.  
- **Maintainability**: OOP design ensures easy future extensions.  
- **Flexibility**: Can be extended to store additional data types or serialize to disk.  

---

## Example Usage

```bash
g++ main.cpp -o sensor_readings
./sensor_readings
