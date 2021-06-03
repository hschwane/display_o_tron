/*
 * display_o_tron
 * NextionHMI.h
 *
 * @author: Hendrik Schwanekamp
 * @mail:   hendrik.schwanekamp@gmx.net
 *
 * Implements serial communication with nextion hmi
 *
 * Copyright (c) 2021 Hendrik Schwanekamp
 *
 */

#ifndef DISPLAY_O_TRON_NEXTIONHMI_H
#define DISPLAY_O_TRON_NEXTIONHMI_H

// includes
//--------------------
#include "mpUtils/mpUtils.h"
//--------------------

//-------------------------------------------------------------------
/**
 * class NextionHMI
 *
 *
 */
class NextionHMI
{
public:
    NextionHMI(std::string portName, mpu::io::BaudRate baudRate);

    /**
     * Set the value variable of the nextion-object "object" to "value"
     */
    template<class T>
    void setValue(const std::string& object, T value);

    /**
     * Check if data was received from the hmi and handle the commands
     */
    void handleRecievedData();

private:
    /**
     * Sends a command to the screen
     */
    void sendCommand(const std::string& command);

    // serial port
    std::string m_portName;
    mpu::io::BaudRate m_baudRate;
    mpu::io::SerialPort m_sp;

};

inline void NextionHMI::sendCommand(const std::string &command)
{
    m_sp.write(command.data(), command.length());
    constexpr char stopCode[] = {char(0xff),char(0xff),char(0xff)};
    m_sp.write(stopCode,3);
    logDEBUG("NextionHMI") << "Sent command: \"" << command << "\"";
}

template<class T>
void NextionHMI::setValue(const std::string &object, T value)
{
    sendCommand(object + ".value=" + std::to_string(value));
}

#endif //DISPLAY_O_TRON_NEXTIONHMI_H
