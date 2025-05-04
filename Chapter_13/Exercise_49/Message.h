#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Message;

class Folder
{
    friend void swap(Message &lhs, Message &rhs);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder &);

    Folder &operator=(const Folder &);

    ~Folder();

private:
    void addMsg(Message *msg);
    void remMsg(Message *msg);
    void removeFromMessages();

    void addMessages(const Folder &);
    std::set<Message *> messages;
};

class Message
{
    friend void swap(Message &lhs, Message &rhs);
    friend class Folder;

public:
    explicit Message(const std::string &str = "")
        : contents(str)
    {}
    Message(const Message &);
    Message(Message &&) noexcept;
    Message &operator=(const Message &);
    Message &operator=(Message &&);

    ~Message();

    void swap(Message &lhs, Message &rhs);
    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();

    void insertFromMessage(Folder &);
    void removeFromMessage(Folder &);
};

#endif