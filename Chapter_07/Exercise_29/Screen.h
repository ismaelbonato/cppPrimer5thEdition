#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <ostream>
#include <string>
#include <utility>

class Screen {
public:
    using position = std::string::size_type;
    //typedef std::string::size_type position;

    Screen() = default;
    Screen(position height, position width): 
        height(height), width(width), content(height*width, ' ') 
        {};

    Screen(position height, position width, const char c): 
        height(height), width(width), content(height*width, c) 
        {};


    Screen &display(std::ostream &out) {
        do_display(out);
        return *this;};
    const Screen &display(std::ostream &out) const {
        do_display(out);
        return *this;};

    Screen set(const char ch);
    Screen set(position x, position y, const char ch);

    char get() const {return content[cursor];};
    char get(position x, position y) const;
    Screen moveCursor(position x, position y);

    inline position getCursorPos() const {return cursor;};

private:
    position height = 0;    
    position width = 0;
    position cursor = 0;

    std::string content;

    void do_display(std::ostream &out) const {
        out << content << std::endl;
    };
};

Screen Screen::set(const char ch)
{
    content[cursor] = ch;
    return *this;
}

Screen Screen::set(position x, position y, const char ch)
{
    position row = x * width;
    content[row + y];
    return *this;
}

inline char Screen::get(position x, position y) const
{
    position row = x * width;
    return content[row + y];
}

Screen Screen::moveCursor(position x, position y) 
{
    position row = x * width;
    cursor =  row + y;
    return *this;
}


#endif