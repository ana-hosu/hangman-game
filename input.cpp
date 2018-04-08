#include "input.h"
#include <locale>
#include <iostream>

wchar_t Input::get()
{
    std::wcout << "\nGuess: ";
    wchar_t input;
    std::wcin >> input;
    return input;
}

bool Input::isValid( wchar_t input)
{
    //std::setlocale(LC_ALL, "ro_RO.UTF-8");
    //std::locale::global(std::locale("ro_RO.UTF-8"));
    if ( !std::isalpha(input, std::locale())){
        std::wcout << "\nHint: Try a letter next time\n";
        return 0;
    }
    for ( auto & elem : letters){
        if ( input == elem)
        {
            std::wcout << "\nAlready tried that once silly\n";
            return 0;
        }
    }
    letters.push_back( input);
    return 1;
}
