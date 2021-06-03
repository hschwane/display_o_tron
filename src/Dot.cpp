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

Dot::Dot()
    : m_nextion("/dev/ttyUSB0",mpu::io::BaudRate::BAUD_9600),
    m_debugDataSource(std::bind(&Dot::newValueHandler,this,std::placeholders::_1,std::placeholders::_2) )
{
    m_ValueToDisplayObject[InputValueType::sog] = "sog";
}

void Dot::update()
{
    m_debugDataSource.update();
}

void Dot::newValueHandler(InputValueType type, InputDataType value)
{
    const std::string& obj = m_ValueToDisplayObject[type];

    // use visit to work with the currently used type in the variant
    std::visit( [this,&obj,type](auto const& v){

        // pass to display
        m_nextion.setValue(obj, v);

        logDEBUG("DOT") << "New Value for \"" << to_string(type) << "\": " << v;

    }, value);
}
