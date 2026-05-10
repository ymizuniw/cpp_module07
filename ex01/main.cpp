#include <iostream>
#include "iter.hpp"

void appendZero(std::string &str) { str.append("0"); }

void printStrArray(std::string strArray[], const size_t size)
{
  for (size_t i = 0; i < size; i++)
    std::cout << strArray[i] << std::endl;
}

void addOne(int &num) { num = num + 1; }

void printIntArray(int intArray[], const size_t size)
{
  for (size_t i = 0; i < size; i++)
    std::cout << intArray[i] << std::endl;
}

void printStr(std::string const &str) { std::cout << str << std::endl; }

void printInt(int const num) { std::cout << num << std::endl; }

int main(void)
{
    //non-const array and function
    std::cout << "\033[31;4m" << "1.non-const array and function\n"  << "\033[0m" << std::endl;
    {
        std::cout << "========String Type========" << std::endl;
        std::string strArray[] = {"str1" , "str2", "str3"};
        std::cout << "appendZero\n" << std::endl;
        ::iter(strArray, 3, appendZero);
        printStrArray(strArray, 3);
        std::cout << "========Int Type========" << std::endl;
        int intArray[] = {1,2,3};
        std::cout << "addOne\n" << std::endl;
        ::iter(intArray, 3, addOne);
        printIntArray(intArray, 3);
    }
    //non-const array and const function
    std::cout << "\033[31;4m" << "\n2.non-const array and const function\n" << "\033[0m" << std::endl;
    {
        std::cout << "========String Type========" << std::endl;
        std::string strArray2[] = {"str1" , "str2", "str3"};
        ::iter(strArray2, 3, printStr);
        //const array and non-const function
        std::cout << "========Int Type========" << std::endl;
        int intArray2[] = {1,2,3};
        ::iter(intArray2, 3, printInt);
    }
    //const array and const function
    std::cout << "\033[31;4m" << "\n3.const array and const function\n" << "\033[0m" << std::endl;
    {
        std::cout << "========String Type========" << std::endl;
        std::string const strArray3[] = {"str1", "str2", "str3"};
        ::iter(strArray3, 3, printStr);
        //const array and non-const function
        std::cout << "========Int Type========" << std::endl;
        int const intArray3[] = {1,2,3};
        ::iter(intArray3, 3, printInt);
    }
    //Cannot compile.
    // std::cout << "\n4.Cannot compile" << std::endl;
    // {
        //const array, non-const function
        // {
            // std::cout << "========String Type========" << std::endl;
            // std::string const strArray5[] = {"str1", "str2", "str3"};
            // ::iter(strArray5, 3, appendZero);
            // //const array and non-const function
            // std::cout << "========Int Type========" << std::endl;
            // int const intArray5[] = {1,2,3};
            // ::iter(intArray5, 3, addOne);
        // }
        //string args, int function
        // {
            // std::cout << "========String Type========" << std::endl;
            // std::string const strArray6[] = {"str1", "str2", "str3"};
            // ::iter(strArray6, 3, addOne);
        // }
        //int args, string function
        // {
            // std::cout << "========Int Type========" << std::endl;
            // int const intArray7[] = {1,2,3};
            // ::iter(intArray7, 3, appendZero);
        // }
    // }
    return (0);
}
