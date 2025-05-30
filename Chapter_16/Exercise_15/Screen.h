#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <utility>

template<size_t ROW, size_t COL>
class Screen;

template<size_t ROW, size_t COL>
std::ostream &operator<<(std::ostream &os, const Screen<ROW, COL> &screen);
template<size_t ROW, size_t COL>
std::istream &operator>>(std::istream &is, Screen<ROW, COL> &screen);

template<size_t ROW, size_t COL>
class Screen
{
    friend std::ostream &operator<< <ROW, COL>(std::ostream &os,
                                               const Screen<ROW, COL> &screen);
    friend std::istream &operator>> <ROW, COL>(std::istream &is, Screen<ROW, COL> &screen);

public:
    using position = std::string::size_type;

    Screen(const char c = ' ')
        : height(ROW)
        , width(COL)
        , content(ROW * COL, c){};

    Screen &display(std::ostream &out)
    {
        do_display(out);
        return *this;
    };
    const Screen &display(std::ostream &out) const
    {
        do_display(out);
        return *this;
    };

    Screen &set(const char ch);
    Screen &set(position x, position y, const char ch);

    char get() const { return content[cursor]; };
    char get(position x, position y) const;
    Screen &moveCursor(position x, position y);

    inline position getCursorPos() const { return cursor; };
    inline position size() const;

private:
    position height = 0;
    position width = 0;
    position cursor = 0;

    std::string content;

    void do_display(std::ostream &out) const { out << content; };
};

template<size_t ROW, size_t COL>
std::ostream &operator<<(std::ostream &os, const Screen<ROW, COL> &screen)
{
    auto &content = screen.content;
    size_t lineCounter = 0;
    for (size_t idx = 0; idx < content.size(); idx++) {
        if (lineCounter == screen.height) {
            os << std::endl;
            lineCounter = 0;
        }
        os << content.at(idx);
        ++lineCounter;
    }

    return os;
}

template<size_t ROW, size_t COL>
std::istream &operator>>(std::istream &is, Screen<ROW, COL> &screen)
{
    auto &content = screen.content;
    for (auto &ch : content) {
        is >> ch;
    }

    return is;
}

template<size_t ROW, size_t COL>
typename Screen<ROW, COL>::position Screen<ROW, COL>::size() const
{
    return height * width;
}

template<size_t ROW, size_t COL>
Screen<ROW, COL> &Screen<ROW, COL>::set(const char ch)
{
    content[cursor] = ch;
    return *this;
}

template<size_t ROW, size_t COL>
Screen<ROW, COL> &Screen<ROW, COL>::set(position x, position y, const char ch)
{
    position row = x * width;
    content[row + y] = ch;
    return *this;
}

template<size_t ROW, size_t COL>
inline char Screen<ROW, COL>::get(position x, position y) const
{
    position row = x * width;
    return content[row + y];
}

template<size_t ROW, size_t COL>
Screen<ROW, COL> &Screen<ROW, COL>::moveCursor(position x, position y)
{
    position row = x * width;
    cursor = row + y;
    return *this;
}

#endif