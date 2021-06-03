/*
 * display_o_tron
 * DebugDataSource.cpp
 *
 * @author: Hendrik Schwanekamp
 * @mail:   hendrik.schwanekamp@gmx.net
 *
 * Implements the DebugDataSource class
 *
 * Copyright (c) 2021 Hendrik Schwanekamp
 *
 */

// includes
//--------------------
#include "DebugDataSource.h"
//--------------------

// function definitions of the DebugDataSource class
//-------------------------------------------------------------------
DebugDataSource::DebugDataSource(std::function<void(InputValueType, InputDataType)> newValueCallback)
    : m_newValueCallback(newValueCallback)
{
}

void DebugDataSource::update()
{
    m_newValueCallback(InputValueType::sog,15.2);
}
