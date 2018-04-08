#include <vector>
#include <string>
#include <array>
#include <boost/optional.hpp>

class Hangman{
private:
    const std::vector<wchar_t> word;
    std::vector<wchar_t> wordShown;
    int mistake;
    const std::array<std::wstring, 3> scaffold;
    const std::array<std::wstring, 9> hangedman;
public:
    Hangman( std::wstring w);
    friend std::wostream& operator << (std::wostream& stream, const Hangman& game);
    void countMistake();
    void reveal( wchar_t lt);
    boost::optional<std::wstring> isFinished();
    bool check( wchar_t lt);
    void showWord();
};
