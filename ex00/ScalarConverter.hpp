#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib> // strtod()
#include <limits> // std::numeric_limits< >::max() / min()
#include <cmath> // modf()

#define RED	    "\33[1;31m"
#define RESET	"\33[0;m"

enum ArgumentType 
{
    _undefined,
    _char,
    _int,
    _float,
    _double
};

class ScalarConverter
{
    public:
        static void    convert(const std::string& arg);

    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);
    
    private:
        static int          _checkArg(const std::string& arg);
        static ArgumentType _checkType(const std::string& arg);
        static void         _toChar(const std::string& arg);
        static void         _toInt(const std::string& arg);
        static void         _toFloat(const std::string& arg);
        static void         _toDouble(const std::string& arg);
        static void         _printMsg(void);
    
    private:
        static double   _argument;
        static char     _charArg;
        static int      _intArg;
        static float    _floatArg;
        static double   _doubleArg;

        static std::string  _charMsg;
        static std::string  _intMsg;
        static std::string  _floatMsg;
        static std::string  _doubleMsg;
};

#endif