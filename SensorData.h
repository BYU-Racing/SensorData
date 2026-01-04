#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <iostream>
#include <Arduino.h>
#include <FlexCAN_T4.h>

class SensorData {
protected:
    // Instantiate attributes
    int id;
    int* data;
    unsigned long timeStamp;
    int dataLength;

public:
    // Default Constructor
    SensorData();
    // Constructor
    SensorData(int id, int* data, int dataLength, unsigned long timeStamp);
    // Constructor from CAN_message_t
    SensorData(CAN_message_t canMessage);

    // Destructor
    ~SensorData();

    int getTimeStamp() const;
    int getId() const;
    int getPriority() const;
    int* getData() const;
    int length() const;

    void setId(int id);
    void setData(int* data);
    // For changing timestamp
    void setTimeStamp(unsigned long timeStamp);

    // Converts SensorData object to a CAN_message_t object
    CAN_message_t formatCAN() const;
    void toString() const;
};

#endif // SENSORDATA_H