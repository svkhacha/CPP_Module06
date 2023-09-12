#include "ScalarConverter.hpp"

double  ScalarConverter::_argument;
char    ScalarConverter::_charArg;
int     ScalarConverter::_intArg;
float   ScalarConverter::_floatArg;
double  ScalarConverter::_doubleArg;

std::string ScalarConverter::_charMsg;
std::string ScalarConverter::_intMsg;
std::string ScalarConverter::_floatMsg;
std::string ScalarConverter::_doubleMsg;

ScalarConverter::ScalarConverter(void) { }
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& other) 
{ 
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(void) { }

int ScalarConverter::_checkArg(const std::string& arg)
{
    if (arg.empty())
        return 1;
    if (arg.compare("nan") == 0 || arg.compare("nanf") == 0)
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: nanf"<<std::endl;
        std::cout<<"double: nan"<<std::endl;
        return 1;
    }
    else if (arg.compare("+inf") == 0 || arg.compare("+inff") == 0)
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: +inff"<<std::endl;
        std::cout<<"double: +inf"<<std::endl;
        return 1;
    }
    else if (arg.compare("-inf") == 0 || arg.compare("-inff") == 0)
    {
        std::cout<<"char: impossible"<<std::endl;
        std::cout<<"int: impossible"<<std::endl;
        std::cout<<"float: -inff"<<std::endl;
        std::cout<<"double: -inf"<<std::endl;
        return 1;
    }
    return 0;
}

ArgumentType    ScalarConverter::_checkType(const std::string& arg)
{
    char*   end;
    _argument = strtod(arg.c_str(), &end);
    if (arg.length() == 1 && isprint((int)arg[0]) && !isdigit((int)arg[0]))
    {
        return _char;
    }
    if (!arg.empty() && (*end == '\0' || (*end == 'f' && *(end + 1) == '\0')))
    {
        if (arg.find('.') != std::string::npos && arg[arg.length() - 1] == 'f')
        {
            return _float;
        }
        if (arg.find('.') != std::string::npos)
        {
            return _double;
        }
        else
            return _int;
    }
    return _undefined;
}

void    ScalarConverter::_toChar(const std::string& arg)
{
    _charArg = arg[0];
    _intArg = static_cast<int>(_charArg);
    _floatArg =  static_cast<float>(_charArg);
    _doubleArg = static_cast<double>(_charArg);
    return ;
}

void    ScalarConverter::_toInt(const std::string& arg)
{
    char*   end;
    _argument = strtod(arg.c_str(), &end);

    if (_argument < std::numeric_limits<int>::min() || _argument > std::numeric_limits<int>::max())
    {
        _intMsg = "impossible";
    }
    _intArg = static_cast<int>(_argument);
    if ((_intArg < std::numeric_limits<char>::min()) || (_intArg > std::numeric_limits<char>::max()))
    {
        _charMsg = "impossible";
    }
    else if (isprint(_intArg))
    {
        _charArg = static_cast<char>(_argument);
    }
    else
        _charMsg   = "Non displayable";
    _floatArg   = static_cast<float>(_argument);
    _doubleArg  = static_cast<double>(_argument);
    return ;
}

void    ScalarConverter::_toFloat(const std::string& arg)
{
    char*   end;

    if (arg.find('.') != arg.rfind('.') && *(arg.end() - 1) == 'f')
    {
        return ;
    }
    _argument = strtod(arg.c_str(), &end);
    _floatArg = static_cast<float>(_argument);
    if ((static_cast<int>(_floatArg) < std::numeric_limits<char>::min()) 
    || (static_cast<int>(_floatArg) > std::numeric_limits<char>::max()))
        _charMsg = "impossible";
    else if (!isprint(static_cast<int>(_floatArg)))
        _charMsg = "Non displayable";
    else
        _charArg = static_cast<char>(_argument);
    if (_floatArg != _floatArg || _floatArg < std::numeric_limits<int>::min() 
    || _floatArg > std::numeric_limits<int>::max())
        _floatMsg = "impossible";
    if (_floatArg < std::numeric_limits<int>::min() || _floatArg > std::numeric_limits<int>::max())
        _intMsg = "impossible";
    else
    _intArg = static_cast<int>(_argument);
    _doubleArg =  static_cast<double>(_argument);
    return ;
}

void    ScalarConverter::_toDouble(const std::string& arg)
{
    char    *end;
    if (arg.empty())
    {
        return ;
    }
    _argument = strtod(arg.c_str(), &end);
    _doubleArg = static_cast<double>(_argument);

    if (_doubleArg != _doubleArg || _doubleArg < std::numeric_limits<double>::min()
        || _double > std::numeric_limits<double>::max())
        _doubleMsg = "impossible";
    if (arg.find('.') != std::string::npos)
    {
        if ((static_cast<double>(_doubleArg) < std::numeric_limits<char>::min())
            || (static_cast<double>(_doubleArg) > std::numeric_limits<char>::max()))
            _charMsg = "impossible";
        else if (!isprint(static_cast<int>(_doubleArg)))
            _charMsg = "Non displayable";
        else
            _charArg = static_cast<char>(_argument);
        if (_doubleArg < std::numeric_limits<int>::min() || _doubleArg > std::numeric_limits<int>::max())
            _intMsg = "impossible";
        else
        _intArg = static_cast<int>(_argument);
        _floatArg = static_cast<float>(_argument);
    }
    return ;
}

void    ScalarConverter::convert(const std::string& arg)
{
    if (arg.empty())
        return ;
    if (_checkArg(arg))
        return ;
    switch (_checkType(arg))
    {
        case _char:
            _toChar(arg);
        break;
        case _int:
            _toInt(arg);
        break ;
        case _float:
            _toFloat(arg);
        break ;
        case _double:
            _toDouble(arg);
        break ;
        case _undefined:
            std::cout<<RED<<"ERROR: Not valid type of argument"<<RESET<<std::endl;
        return ;
    }
    _printMsg();
}

void    ScalarConverter::_printMsg(void)
{
    double integerPart;

    std::cout<<"char: ";
    if (_charMsg.empty())
        std::cout<<"'"<<_charArg<<"'"<<std::endl;
    else
        std::cout<<_charMsg<<std::endl;

    std::cout<<"int: ";
    if (_intMsg.empty())
        std::cout<<_intArg<<std::endl;
    else
        std::cout<<_intMsg<<std::endl;

    std::cout<<"float: ";
    if (_floatArg < std::numeric_limits<float>::min() 
        || _floatArg > std::numeric_limits<float>::max())
        {
            std::cout<<_floatArg;
            if (modf(_floatArg, &integerPart) == 0)
                std::cout<<".0";
        std::cout<<"f"<<std::endl;
        }
    else if (_floatMsg.empty())
    {
        std::cout<<_floatArg;
        if (modf(_floatArg, &integerPart) == 0)
            std::cout<<".0";
        std::cout<<"f"<<std::endl;
    }
    else
        std::cout<<_floatMsg<<std::endl;

    std::cout<<"double: ";
    if (_doubleArg < std::numeric_limits<double>::min() 
        || _doubleArg > std::numeric_limits<double>::max())
        {
            std::cout<<_doubleArg;
            if (modf(_doubleArg, &integerPart) == 0)
                std::cout<<".0";
        std::cout<<std::endl;
        }
    else if (_doubleMsg.empty())
    {
        std::cout<<_doubleArg;
        if (modf(_doubleArg, &integerPart) == 0)
            std::cout<<".0";
        std::cout<<std::endl;
    }
    else
      std::cout<<_doubleMsg<<std::endl;
      //return ;
}
