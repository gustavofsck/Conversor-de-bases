
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#define DEC_TO_HEX 1
#define DEC_TO_BIN 2
#define DEC_TO_OCT 3

#define BIN_TO_DEC 4
#define BIN_TO_HEX 5
#define BIN_TO_OCT 6

#define HEX_TO_DEC 7
#define HEX_TO_BIN 8
#define HEX_TO_OCT 9

#define OCT_TO_DEC 10
#define OCT_TO_BIN 11
#define OCT_TO_HEX 12

std::string convert_any_to_dec(std::string& value, int base)
{
    std::vector<int> digits;
    
    for(int i = value.length() - 1; i > -1; i--)
    {
        // make it all uppercase
        value[i] = std::toupper(value[i]);
        
        switch(value[i])
        {
            case 'A':
            digits.emplace_back(10);
            break;
            
            case 'B':
            digits.emplace_back(11);
            break;
            
            case 'C':
            digits.emplace_back(12);
            break;
            
            case 'D':
            digits.emplace_back(13);
            break;
            
            case 'E':
            digits.emplace_back(14);
            break;
            
            case 'F':
            digits.emplace_back(15);
            break;
            
            default:
            digits.emplace_back(value[i] - '0');
        }
    }
    
    const int size = digits.size() - 1;
    
    
    int result = 0;
    
    for(int i = size; i > -1; i--)
        result += (digits[i] * (int)(std::pow((float)base, i)));

    std::string result_str(std::to_string(result));
    return result_str;
}

inline std::vector<int> get_digits(std::string& value, const int base)
{
    std::vector<int> digits;
    
    
    // trasnform the string into a int
    int int_v = std::stoi(value);
    
    // separate the value into a vector of digits
    while(int_v != 0)
    {
        // get the remainder
        int current_digit = int_v % base;
                
        digits.emplace_back(current_digit);
        int_v /= base;
    }
    
    return digits;
}

std::string convert_dec_to_hex(std::string& value)
{
    constexpr int base = 16;
    
    const std::vector<int> digits = get_digits(value, base);
    const int size = digits.size() - 1;
    
    std::string result;
    
    for(int i = size; i > -1; i--)
    {
        if(digits[i] > 9)
        {
            // since the remainder will always be < 16 we can do a switch case
            switch (digits[i])
            {
                case 10:
                result.push_back('A');
                break;
                
                case 11:
                result.push_back('B');
                break;
                
                case 12:
                result.push_back('C');
                break;
                
                case 13:
                result.push_back('D');
                break;
                
                case 14:
                result.push_back('E');
                break;
                
                case 15:
                result.push_back('F');
                break;
                
                default:
                std::cout << "ERROR \n";
                exit(1);
            }
            
            continue;
        }
        
        result.push_back(digits[i] + '0');
    }
    
    result.push_back('\0');
    return result;     
}

std::string convert_dec_to_bin(std::string& value)
{

    constexpr int base = 2;
    
    const std::vector<int> digits = get_digits(value, base);
    const int size = digits.size() - 1;
    
    int result = 0;
    
    for(int i = size; i > -1; i--)
        result = result * 10 + digits[i];
       
    return std::to_string(result);     
}

std::string convert_dec_to_oct(std::string& value)
{

    constexpr int base = 8;
    
    const std::vector<int> digits = get_digits(value, base);
    const int size = digits.size() - 1;
    
    int result = 0;
    
    for(int i = size; i > -1; i--)
        result = result * 10 + digits[i];

    return std::to_string(result);      
}

std::string convert_bin_to_hex(std::string& value)
{

    std::string number(convert_any_to_dec(value, 2));
    return convert_dec_to_hex(number);

}

std::string convert_bin_to_oct(std::string& value)
{    
    
    std::string number(convert_any_to_dec(value, 2));
    return convert_dec_to_oct(number);
}


std::string convert_hex_to_bin(std::string& value)
{
    std::string number(convert_any_to_dec(value, 16));
    return convert_dec_to_bin(number);
    
}

std::string convert_hex_to_oct(std::string& value)
{
    std::string number(convert_any_to_dec(value, 16));
    return convert_dec_to_oct(number);
    
}

std::string convert_oct_to_bin(std::string& value)
{
    std::string number(convert_any_to_dec(value, 8));
    return convert_dec_to_bin(number);
    
}

std::string convert_oct_to_hex(std::string& value)
{
    std::string number(convert_any_to_dec(value, 8));
    return convert_dec_to_hex(number);
    
}

int main()
{
    
    constexpr const char* str1(" 1: decimal to hexadecimal \n 2: decimal to binary \n 3: decimal to octal \n \n " 
    "4: binary to decimal \n 5: binary to hexadecimal \n 6: binary to octal \n \n "
    "7: hexadecimal to decimal \n 8: hexadecimal to binary \n 9: hexadecimal to octal \n \n "
    "10: octal to decimal \n 11: octal to binary \n 12: octal to hexadecimal \n \n"
    "Type in an option (1 - 12): ");
    
    constexpr const char* str2("Type in your number: ");
    
    constexpr const char* converted_to_dec(" converted to decimal is: ");
    constexpr const char* converted_to_hex(" converted to hexadecimal is: ");
    constexpr const char* converted_to_bin(" converted to binary is: ");
    constexpr const char* converted_to_oct(" converted to octal is: ");

    
    int u_option;
    std::string u_n1_str;
   
    std::cout << str1;
    
    for(;;)
    {
        if(std::cin >> u_option)
        {
            std::cout << str2;
            
            std::string u_number;
            std::string result;
            
            if(std::cin >> u_number)
            {
                switch (u_option)
                {
                    case DEC_TO_HEX:
                    result = convert_dec_to_hex(u_number);
                    std::cout << u_number << converted_to_hex << result << std::endl;
                    return 0;                  
                        
                    case DEC_TO_BIN:
                    result = convert_dec_to_bin(u_number);
                    std::cout << u_number << converted_to_bin << result << std::endl; 
                    return 0;
                        
                    case DEC_TO_OCT:
                    result = convert_dec_to_oct(u_number);
                    std::cout << u_number << converted_to_oct << result << std::endl;     
                    return 0;

                    /* ================================================================================= */
                        
                    case BIN_TO_DEC:
                    result = convert_any_to_dec(u_number, 2);
                    std::cout << u_number << converted_to_dec << result << std::endl; 
                    return 0;

                    case BIN_TO_HEX:
                    result = convert_bin_to_hex(u_number);
                    std::cout << u_number << converted_to_hex << result << std::endl; 
                    return 0;    

                    case BIN_TO_OCT:
                    result = convert_bin_to_oct(u_number);
                    std::cout << u_number << converted_to_oct << result << std::endl; 
                    return 0;
                     
                    /* ================================================================================= */
                        
                    case HEX_TO_DEC:
                    result = convert_any_to_dec(u_number, 16);
                    std::cout << u_number << converted_to_dec << result << std::endl; 
                    return 0;
                        
                    case HEX_TO_BIN:
                    result = convert_hex_to_bin(u_number);
                    std::cout << u_number << converted_to_bin << result << std::endl; 
                    return 0;
                        
                    case HEX_TO_OCT:
                    result = convert_hex_to_oct(u_number);
                    std::cout << u_number << converted_to_oct << result << std::endl; 
                    return 0;
                    
                    /* ================================================================================= */
                    
                    case OCT_TO_DEC:
                    result = convert_any_to_dec(u_number, 8);
                    std::cout << u_number << converted_to_dec << result << std::endl; 
                    return 0;
                        
                    case OCT_TO_BIN:
                    result = convert_oct_to_bin(u_number);
                    std::cout << u_number << converted_to_bin << result << std::endl; 
                    return 0;
                        
                    case OCT_TO_HEX:
                    result = convert_oct_to_hex(u_number);
                    std::cout << u_number << converted_to_hex << result << std::endl; 
                    return 0;    
                }
            }
            
            std::cout << "ERROR: Invalid input\n";
        }
    }
    
    return 0;
}
