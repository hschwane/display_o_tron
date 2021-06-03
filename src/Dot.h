/*
 * display_o_tron
 * Dot.h
 *
 * @author: Hendrik Schwanekamp
 * @mail:   hendrik.schwanekamp@gmx.net
 *
 * Implements the Dot class, main class of display_o_tron software
 *
 * Copyright (c) 2021 Hendrik Schwanekamp
 *
 */

#ifndef DISPLAY_O_TRON_DOT_H
#define DISPLAY_O_TRON_DOT_H

// includes
//--------------------
#include <variant>
#include <string>
#include <map>
#include <mpUtils/mpUtils.h>
#include "inputValueTypes.h"
#include "NextionHMI.h"
#include "DebugDataSource.h"
//--------------------

//-------------------------------------------------------------------
/**
 * class Dot
 *
 * usage:
 *
 */
class Dot
{
public:
    /**
     * @brief initializes the display_o_tron software
     */
    Dot();

    /**
     * @brief call in endless loop to run the software
     */
    void update();

private:
    /**
     * @brief handles a value change by a data source
     */
    void newValueHandler(InputValueType type, InputDataType value);

    // display
    NextionHMI m_nextion;

    // data sources
    DebugDataSource m_debugDataSource;

    // settings
    std::map<InputValueType,std::string> m_ValueToDisplayObject; //!< maps different ValueTypes to their name on the display
};


#endif //DISPLAY_O_TRON_DOT_H
