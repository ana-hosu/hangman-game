#include <iostream>
#include <cmath>
#include "hangman.h"

    Hangman::Hangman( std::wstring w)
        :word(w.begin(),w.end()), wordShown(w.length(), '_'), mistake{0}, scaffold{L"___", L"|", L"----------"},
        hangedman{L"     |", L"   //////", L"   (* *)", L"     |", L">---   ---<", L"   (   )", L"    | |", L"    | |", L"  ==   =="}
    {
        std::wcout << L"The Game Is Begun\n";
    }

    std::wostream& operator<< ( std::wostream& stream, const Hangman& game)
    {
    stream << L"\n\n\n";
    if ( game.mistake!=0)
    {
        if ( game.mistake>3)
            { stream << L"\t" << game.scaffold[2] << L"\n";}
        if ( game.mistake>4)
        {
            auto i = 0;
            int max = std::min( ( game.mistake - 4)*2, 9);
            for ( ; i< max; i++)
            {
                stream << L"\t"<< game.scaffold[1] << L"   " << game.hangedman[i] << L"\n";
            }
            for( ; i<10; i++)
            {
                stream << L"\t" << game.scaffold[1] << L"\n";
            }
        }
        else for(auto i=0 ; i<game.mistake-1; i++)
        {
            stream << L"\t" << game.scaffold[1] << L"\n";
            stream << L"\t" << game.scaffold[1] << L"\n";
            stream << L"\t" << game.scaffold[1] << L"\n";
        }
        stream << L"\t" << game.scaffold[0] << L"\n";
    }
    for ( auto x: game.wordShown)
        stream << x;
    return stream;
    }

    void Hangman::countMistake()
    {
        mistake++;
    }

    void Hangman::reveal( wchar_t lt)
    {
        const std::locale locale;
        for ( auto i=0; i!=static_cast<int>(word.size()); i++)
            if ( word[i]==std::tolower(lt, locale))
                wordShown[i] = word[i];
    }

    boost::optional<std::wstring> Hangman::isFinished()
    {
        if ( mistake>9 || mistake<0)
            throw std::invalid_argument( "negative or too large mistake value ");
        if ( mistake==9) { std::wstring s = L"\nYou lost. Obviously.\n"; return s;}
        if ( word==wordShown) { std::wstring s = L"\n~~~Pffft... won this time I guess~~~\n"; return s;}
        return boost::none;
    }

    bool Hangman::check( wchar_t lt)
    {
        const std::locale locale;
        for ( auto x: word)
            if ( x==std::tolower( lt, locale)) return 1;
        return 0;
    }

    void Hangman::showWord()
    {
        std::wcout <<"\n";
        for ( const auto& l: word){ std::wcout<< l;}
    }
