

class Debug {
public:
    constexpr Debug(bool b = true): 
        video(b), audio(b), input(b), etc(b) {}

    constexpr Debug(bool v, bool a, bool i, bool e):
        video(v), audio(a), input(i), etc(e) {}

    constexpr bool any() { return video || audio || input || etc; }
    void set_video(constexpr bool b) { video = b; }
    void set_audio(bool b) { audio = b; }
    void set_input(bool b) { input = b; }
    void set_etc(bool b) { etc = b; }
private:
    bool video;
    bool audio; 
    bool input;
    bool etc; 
};

int main()
{
    Debug debug{true};

    return 0;
}