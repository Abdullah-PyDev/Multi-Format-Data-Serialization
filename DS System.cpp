#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// 1. Enum to identify data type
enum DataType {
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_STRING
};

// 2. Union to store the value
union DataValue {
    int intValue;
    double doubleValue;
    char* stringValue;
};

// 3. Structure combining everything
struct SensorReading {
    DataType type;
    DataValue value;
    unsigned long timestamp;
    int sensorId;
};

// 4. Global counter
int g_totalReadings = 0;

// 5. Typedef pointer
typedef SensorReading* ReadingPtr;

// Function: Create a new reading
ReadingPtr createReading(int sensorId) {
    ReadingPtr r = new SensorReading;
    r->sensorId = sensorId;
    r->timestamp = static_cast<unsigned long>(time(nullptr));
    g_totalReadings++;
    return r;
}

// Functions to set values
void setIntValue(ReadingPtr r, int val) {
    r->type = TYPE_INT;
    r->value.intValue = val;
}

void setDoubleValue(ReadingPtr r, double val) {
    r->type = TYPE_DOUBLE;
    r->value.doubleValue = val;
}

void setStringValue(ReadingPtr r, const char* val) {
    r->type = TYPE_STRING;
    size_t len = strlen(val) + 1;
    r->value.stringValue = new char[len];
    strcpy(r->value.stringValue, val);
}

// Display reading
void displayReading(const ReadingPtr r) {
    cout << "Sensor ID: " << r->sensorId << ", Timestamp: " << r->timestamp << ", ";
    switch (r->type) {
        case TYPE_INT:
            cout << "Type: INT, Value: " << r->value.intValue << endl;
            break;
        case TYPE_DOUBLE:
            cout << "Type: DOUBLE, Value: " << r->value.doubleValue << endl;
            break;
        case TYPE_STRING:
            cout << "Type: STRING, Value: " << r->value.stringValue << endl;
            break;
    }
}

// Delete reading
void deleteReading(ReadingPtr r) {
    if (r->type == TYPE_STRING && r->value.stringValue) {
        delete[] r->value.stringValue;
    }
    delete r;
    g_totalReadings--;
}

int main() {
    cout << "=== Sensor Readings Program ===\n\n";

    int nInt, nDouble, nString;
    cout << "How many integer readings? ";
    cin >> nInt;
    cout << "How many double readings? ";
    cin >> nDouble;
    cout << "How many string readings? ";
    cin >> nString;

    int total = nInt + nDouble + nString;
    ReadingPtr* readings = new ReadingPtr[total];

    int sensorCounter = 1;

    // Input integer readings
    for (int i = 0; i < nInt; i++) {
        readings[i] = createReading(sensorCounter++);
        int val;
        cout << "Enter integer value for reading " << i+1 << ": ";
        cin >> val;
        setIntValue(readings[i], val);
    }

    // Input double readings
    for (int i = 0; i < nDouble; i++) {
        readings[nInt + i] = createReading(sensorCounter++);
        double val;
        cout << "Enter double value for reading " << i+1 << ": ";
        cin >> val;
        setDoubleValue(readings[nInt + i], val);
    }

    // Input string readings
    cin.ignore(); // clear newline from previous input
    for (int i = 0; i < nString; i++) {
        readings[nInt + nDouble + i] = createReading(sensorCounter++);
        char buffer[100];
        cout << "Enter string value for reading " << i+1 << ": ";
        cin.getline(buffer, 100);
        setStringValue(readings[nInt + nDouble + i], buffer);
    }

    cout << "\n=== All Readings ===\n";
    for (int i = 0; i < total; i++) {
        displayReading(readings[i]);
    }

    cout << "\n=== Memory Information ===\n";
    cout << "Size of enum: " << sizeof(DataType) << " bytes\n";
    cout << "Size of union: " << sizeof(DataValue) << " bytes\n";
    cout << "Size of struct: " << sizeof(SensorReading) << " bytes\n";
    cout << "Memory saved by union: "
         << (sizeof(int) + sizeof(double) + sizeof(char*)) - sizeof(DataValue)
         << " bytes (approximate)\n";

    // Cleanup
    for (int i = 0; i < total; i++) {
        deleteReading(readings[i]);
    }
    delete[] readings;

    cout << "\nTotal readings after cleanup: " << g_totalReadings << endl;

    return 0;
}