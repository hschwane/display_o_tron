/*
 * display_o_tron
 * Dot.cpp
 *
 * @author: Hendrik Schwanekamp
 * @mail:   hendrik.schwanekamp@gmx.net
 *
 * Implements the Dot class
 *
 * Copyright (c) 2021 Hendrik Schwanekamp
 *
 */

// includes
//--------------------
#include "Dot.h"
//--------------------

// function definitions of the Dot class
//-------------------------------------------------------------------

Dot::Dot() : m_nextion("/dev/ttyUSB0",mpu::io::BaudRate::BAUD_9600)
{

}

void Dot::run()
{

}

void Dot::valueChangeHandler(InputValueType type, IVType value)
{
    const std::string& obj = m_ValueToDisplayObject[type];

    // use visit to work with the currently used type in the variant
    std::visit( [this,&obj,type](auto const& v){

        // pass to display
        m_nextion.setValue(obj, v);

        // log for debugging
        logDEBUG("DOT") << "Recieved " << to_string(type) << ": " << v;

    }, value);
}
