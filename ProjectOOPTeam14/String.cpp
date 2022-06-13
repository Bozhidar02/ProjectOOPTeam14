#include "String.h"//not the stl library
#include <cstring>

namespace MyString {
    String::String(size_t init_size) {
        data = new char[init_size];
        size = init_size;

        if (data != NULL) {
            for (size_t i = 0; i < init_size; i++) {
                data[i] = '\0';
            }
        }
    }

    void String::free()
    {
        delete[] data;
    }

    void String::copy(const String& string)
    {
        size = string.getLength();
        data = new char[size + 1];

        if (data != NULL) {
            strcpy_s(data, size + 1, string.data);
        }
    }

    String::String(const char* data) {
        size_t size = strlen(data);
        this->data = new char[size + 1];
        this->size = size + 1;

        if (this->data != NULL) {
            strcpy_s(this->data, size + 1, data);
        }
    }

    String::String(const String& string) {
        copy(string);
    }

    String::~String() {
        free();
    }

    const char* String::getText() const {
        return data;
    }

    void String::setText(const char* text) {
        delete[] data;

        size = strlen(text);
        data = new char[this->size + 1];

        strcpy_s(data, size + 1, text);
    }

    size_t String::getLength() const {
        return strlen(data);
    }

    void String::setLength(size_t size) {
        size_t old_length = this->getLength();
        char* old_data = data;
        this->size = size;
        data = new char[size];
        for (size_t i = 0; i < size; i++) {
            if (i < old_length) {
                data[i] = old_data[i];
            }
            else {
                data[i] = '\0';
            }
        }
        delete[] old_data;
        data[size] = '\0';
    }

    void String::add(const String& text) {
        size_t new_size = size + text.size;
        setLength(new_size);

        size_t length = getLength();
        for (size_t i = length; i < new_size; i++) {
            data[i] = text.data[i - length];
        }
    }

    char String::get(size_t pos) const {
        if (pos > getLength()) {
            return '\0';
        }
        return data[pos];
    }

    bool String::compare(const String& string) const {
        return strcmp(data, string.data) == 0;
    }

    char String::operator[](size_t pos) {
        return get(pos);
    }

    String& String::operator=(const String& rhs)
    {
        if (this != &rhs)
        {
            free();
            copy(rhs);
        }

        return *this;
    }

    String operator+(const String& string1, const String& string2) {
        String string = String(string1);
        string.add(string2);

        return string;
    }

    bool operator==(const String& string1, const String& string2) {
        return string1.compare(string2);
    }

    std::ostream& operator<<(std::ostream& ostream, const MyString::String& string) {
        return (ostream << string.data);
    }
}