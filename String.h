#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
    char* str;
    int length;
    int capacity;
    static int object_count;
    void init(int size, const char* initial_str = nullptr);

public:
    String();
    explicit String(int size);
    String(const char* initial_str);
    String(const String& other);
    ~String();

    String& operator=(const String& other);
    bool operator==(const String& other) const;
    void read_from_keyboard();
    void display() const;
    static int get_object_count();
};