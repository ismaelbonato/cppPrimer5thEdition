#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
#include <string>

class Screen;

using position = std::string::size_type;

class WindowManager {
public:
    WindowManager(position height, position width, const char c);
    inline void clear(position idx);
    void printScreen(position idx);
private:
    std::vector<Screen> screens;
};

class Screen {
public:

    friend void WindowManager::clear(position idx);

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

    Screen &set(const char ch);
    Screen &set(position x, position y, const char ch);

    char get() const {return content[cursor];};
    char get(position x, position y) const;
    Screen &moveCursor(position x, position y);

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


WindowManager::WindowManager(position height, position width, const char c)
{
     screens.push_back(Screen(height, width,  c));
}

inline void WindowManager::clear(position idx)
{  
    if(idx >= screens.size()) {
        return;
    }
    Screen &screen = screens[idx];
    screen.content = std::string(screen.height * screen.width, ' ');
}

void WindowManager::printScreen(position idx)
{
    if(idx >= screens.size()) {
        return;
    }
    screens[idx].display(std::cout);
}

Screen &Screen::set(const char ch)
{
    content[cursor] = ch;
    return *this;
}

Screen &Screen::set(position x, position y, const char ch)
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

Screen &Screen::moveCursor(position x, position y) 
{
    position row = x * width;
    cursor =  row + y;
    return *this;
}


#endif