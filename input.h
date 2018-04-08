#include <vector>

class Input{
private:
    std::vector<wchar_t> letters;
public:
    Input() = default;
    wchar_t get();
    bool isValid( wchar_t input);
};
