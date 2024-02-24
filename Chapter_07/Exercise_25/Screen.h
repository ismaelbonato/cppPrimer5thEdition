#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
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

    char get() const {return content[cursor];};
    char get(position x, position y) const;
    Screen &moveCursor(position x, position y);

    inline position getCursorPos() const {return cursor;};

private:
    position height = 0;    
    position width = 0;
    position cursor = 0;

    std::string content;
};

inline char Screen::get(position x, position y) const
{
    int row = x * y;
    return content[row + y];
}

Screen &Screen::moveCursor(position x, position y) 
{
    position row = x * y;
    cursor =  row + y;
    return *this;
}


#endif