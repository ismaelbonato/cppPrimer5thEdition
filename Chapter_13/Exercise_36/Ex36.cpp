#include <iostream>
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
    Message &operator=(const Message &);
    ~Message();

    void swap(Message &lhs, Message &rhs);
    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
    void removeFromMessage(Folder &);
};

void Message::removeFromMessage(Folder &f)
{
    folders.erase(&f);
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message &m)
    : contents(m.contents)
    , folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::remove_from_Folders()
{
    for (auto f : folders) {
        f->remMsg(this);
    }
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;

    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

Folder::Folder(const Folder &origin)
    : messages(origin.messages)
{
    addMessages(origin);
}

Folder &Folder::operator=(const Folder &rhs)
{
    if (this == &rhs) {
        return *this;
    }

    removeFromMessages();
    messages = rhs.messages;
    addMessages(rhs);
    return *this;
}

void Folder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Folder::remMsg(Message *msg)
{
    messages.erase(msg);
}

void Folder::addMessages(const Folder &f)
{
    for (auto &msg : f.messages) {
        msg->save(*this);
    }
}

Folder::~Folder()
{
    removeFromMessages();
}

void Folder::removeFromMessages()
{
    for (auto &msg : messages) {
        msg->removeFromMessage(*this);
    }
}

int main()
{
    Message msg1("Hello");
    Message msg2("World");

    Folder folder1;
    Folder folder2;

    msg1.save(folder1);
    msg2.save(folder2);

    swap(msg1, msg2);

    folder1 = folder2;

    return 0;
}