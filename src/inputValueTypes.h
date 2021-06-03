/*
 * display_o_tron
 * inputTypes.h
 *
 * @author: Hendrik Schwanekamp
 * @mail:   hendrik.schwanekamp@gmx.net
 *
 * Implements a list of all available input types
 *
 * Copyright (c) 2021 Hendrik Schwanekamp
 *
 */
#ifndef DISPLAY_O_TRON_INPUTTYPES_H
#define DISPLAY_O_TRON_INPUTTYPES_H

// includes
//--------------------
#include <string_view>
//--------------------

/**
 * @brief list of all inputs that can be recognised by any of the data inputs
 */
enum class InputValueType
{
    cog,
    sog,
    bat1,
    bat2,
    bat3,
    bat4,
    bat5,
    bat6,
    bat7
};

constexpr int numInputValueTypes = 9;
constexpr const char* InputValueType_names[numInputValueTypes] = {"cog", "sog", "bat1", "bat2", "bat3", "bat4", "bat5", "bat6", "bat7"};

/**
 * @brief convert an input type to string for storing in files and printing debug output
 * @param val the input type value to convert to string
 * @return the string form of the input type
 */
constexpr const char* to_string(InputValueType val) {return InputValueType_names[static_cast<int>(val)];}

/**
 * @brief try to convert s into an input type. Throws an illegal argument if no match is found
 * @param s the string only consisting of an input type
 * @return the input type enum corresponding to s
 */
inline InputValueType from_string(std::string_view s)
{
    int i=0;
    while(i < numInputValueTypes)
    {
        if(s == InputValueType_names[i])
            return static_cast<InputValueType>(i);
    }
    throw std::invalid_argument(std::string(s) + " is not the name of a valid input type");
}

using InputDataType = std::variant<uint32_t, double>; //!< type used for input data

#endif //DISPLAY_O_TRON_INPUTTYPES_H
