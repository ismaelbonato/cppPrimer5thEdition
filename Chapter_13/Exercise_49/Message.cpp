#include "Message.h"
#include <iostream>
#include <set>
#include <string>

void Message::removeFromMessage(Folder &f)
{
    folders.erase(&f);
}

void Message::insertFromMessage(Folder &f)
{
    folders.insert(&f);
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

Message::Message(Message &&origin) noexcept
    : contents(std::move(origin.contents))
    , folders(std::move(origin.folders))
{
    for (auto folder : folders) {
        folder->remMsg(&origin);
        folder->addMsg(this);
    }

    origin.folders.clear();
}

Message &Message::operator=(Message &&rhs)
{
    if (this == &rhs) {
        return *this;
    }
    remove_from_Folders();

    contents = std::move(rhs.contents);
    folders = std::move(rhs.folders);

    for (auto folder : folders) {
        folder->remMsg(&rhs);
        folder->addMsg(this);
    }
    
    rhs.folders.clear();
    return *this;
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
        msg->insertFromMessage(*this);
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
