#include "String.h"
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;


int String::object_count = 0;

void String::init(int size, const char* initial_str) {
    if (size < 0) size = 0;

    this->capacity = size;
    this->str = new char[this->capacity + 1];

    if (initial_str != nullptr) {
        int initial_len = strlen(initial_str);

        this->length = (initial_len <= this->capacity) ? initial_len : this->capacity;
        strncpy_s(this->str, this->capacity + 1, initial_str, this->length);
        this->str[this->length] = '\0';
    }
    else {
        this->str[0] = '\0';
        this->length = 0;
    }

    String::object_count++;
}

String::String()
    : String(80)
{
}

String::String(int size)
{
    init(size);
}

String::String(const char* initial_str)
{
    int required_capacity = (initial_str != nullptr) ? strlen(initial_str) : 0;
    init(required_capacity, initial_str);
}

String::String(const String& other) {
    init(other.capacity, other.str);
}

String::~String() {
    delete[] this->str;
    this->str = nullptr;
    this->length = 0;
    this->capacity = 0;
    String::object_count--;
}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }

    delete[] this->str;
    this->capacity = other.capacity;
    this->length = other.length;
    this->str = new char[this->capacity + 1];
    strcpy_s(this->str, this->capacity + 1, other.str);

    return *this;
}

bool String::operator==(const String& other) const {
    return (strcmp(this->str, other.str) == 0);
}

void String::read_from_keyboard()
{
    cout << "Print string (till " << this->capacity << " symbols):\n> ";

    cin.getline(this->str, this->capacity + 1);
    this->length = strlen(this->str);
    cout << "The length is: " << this->length << "\n";
}

void String::display() const {
    cout << "String: \"" << this->str << "\" ";
    cout << "(Length: " << this->length << ", Capacity: " << this->capacity << ")\n";
}

int String::get_object_count() {
    return String::object_count;
}