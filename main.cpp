#include <iostream>
#include <fstream>
#include "hangman.h"
#include "input.h"
#include "word.h"

int main()
{
    std::locale::global (std::locale (""));
    std::setlocale(LC_ALL, "");
    std::wcout << L"Choose a language:\nEnglish(e)\nRomanian(r)\n";
    wchar_t lang;
    std::wcin >> lang;
    std::string path{""};
    switch (lang) {
    case L'r':
        path = "./dictionaries/ro_dic.conf";
        break;
    case L'e':
        path = "./dictionaries/en_dic.conf";
    default:
        break;
    }
    std::wifstream my_file{path};
    if(!my_file) { std::cerr << "Could not open dictionary" << "\n"; }
    std::wstring word_to_guess = Word{ my_file}.get();
    //std::string word_to_guess = Word::set();
    Hangman hangman{ word_to_guess};
    try{
        wchar_t letter;
        Input player_input;
        std::wcout << hangman;
        while(!hangman.isFinished())
        {     
            while(!player_input.isValid(letter = player_input.get())){}
            if( hangman.check(letter)) { hangman.reveal(letter); }
            else { hangman.countMistake(); }
            try
            {
                std::wcout << hangman;
            }
            catch( std::out_of_range& e)
            {
                std::cerr << "Vector out of range: " << e.what();
            }
        }
        std::wcout << hangman.isFinished().value();
    }
    catch( const std::invalid_argument& e)
    {
        std::cerr << "Invalid argument: " << e.what();
    }
}
