#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <regex>

class Word{
private:
    std::vector<std::wstring> dictionary;

public:
    Word(): dictionary{L"zero"} {}

    Word( std::wifstream& ifs)
    {
        std::wstring line;
        while ( std::getline(ifs, line))
        {
            std::wregex pat {LR"(([\wăîșțâ-]+))"};
            for ( std::wsregex_iterator p( line.begin(), line.end(), pat); p!=std::wsregex_iterator{}; ++p)
            {
                dictionary.push_back((*p)[1]);
            }
        }
    }

    std::wstring get()
    {
        std::random_device rd;
        int i = rd() % dictionary.size();
        std::wstring word = dictionary[i];
        return word;
    }

    static std::wstring set()
    {
        std::wstring word;
        std::wcin >> word;
        return word;
    }
};
