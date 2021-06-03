/*
 * display_o_tron
 * DebugDataSource.h
 *
 * @author: Hendrik Schwanekamp
 * @mail:   hendrik.schwanekamp@gmx.net
 *
 * Implements the DebugDataSource class
 *
 * Copyright (c) 2021 Hendrik Schwanekamp
 *
 */

#ifndef DISPLAY_O_TRON_DEBUGDATASOURCE_H
#define DISPLAY_O_TRON_DEBUGDATASOURCE_H

// includes
//--------------------
#include <functional>
#include <mpUtils/mpUtils.h>
#include "inputValueTypes.h"
//--------------------

//-------------------------------------------------------------------
/**
 * class DebugDataSource
 *
 * Randomly generates newValue events for selected valueTypes for debugging and demo purpose
 *
 */
class DebugDataSource
{
public:
    DebugDataSource(std::function<void(InputValueType,InputDataType)> newValueCallback);

    /**
     * @brief update data source be generating new debug values
     */
    void update();

private:
    std::function<void(InputValueType,InputDataType)> m_newValueCallback;

};


#endif //DISPLAY_O_TRON_DEBUGDATASOURCE_H
