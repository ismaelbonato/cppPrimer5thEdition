#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <ostream>
#include <string>
#include <utility>

template<size_t X, size_t Y>
class Screen
{
public:
    using position = std::string::size_type;

    Screen(const position h = Y, const position w = X, const char c = ' ')
        : height(h)
        , width(w)
        , content(h * w, c){};

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
    Screen &set(position x, position y);

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

template<size_t X, size_t Y>
typename Screen<X, Y>::position Screen<X, Y>::size() const
{
    return height * width;
}

template<size_t X, size_t Y>
Screen<X, Y> &Screen<X, Y>::set(const char ch)
{
    content[cursor] = ch;
    return *this;
}

template<size_t X, size_t Y>
Screen<X, Y> &Screen<X, Y>::set(position x, position y)
{
    position row = x * width;
    content[row + y];
    return *this;
}

template<size_t X, size_t Y>
inline char Screen<X, Y>::get(position x, position y) const
{
    position row = x * width;
    return content[row + y];
}

template<size_t X, size_t Y>
Screen<X, Y> &Screen<X, Y>::moveCursor(position x, position y)
{
    position row = x * width;
    cursor = row + y;
    return *this;
}

#endif