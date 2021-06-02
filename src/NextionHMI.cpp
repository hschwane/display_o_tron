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

#include "NextionHMI.h"

NextionHMI::NextionHMI(std::string portName, mpu::io::BaudRate baudRate)
    : m_portName(portName), m_baudRate(baudRate), m_sp(portName,baudRate)
{
}

