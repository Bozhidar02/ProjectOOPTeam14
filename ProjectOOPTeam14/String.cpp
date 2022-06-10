#include "String.h"//not the stl library
#include <cstring>

namespace MyString {
    String::String(size_t init_size) {
        this->data = new char[init_size];
        this->size = init_size;

        if (this->data != NULL) {
            for (size_t i = 0; i < init_size; i++) {
                data[i] = '\0';
            }
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
        this->size = string.getLength();
        this->data = new char[this->size + 1];

        if (this->data != NULL) {
            strcpy_s(this->data, this->size + 1, string.data);
        }
    }

    String::~String() {
    }

    char* String::getText() const {
        return data;
    }

    void String::setText(const char* text) {
        delete[] this->data;

        this->size = strlen(text);
        this->data = new char[this->size + 1];

        strcpy_s(this->data, this->size + 1, text);
    }

    size_t String::getLength() const {
        return strlen(this->data);
    }

    void String::setLength(size_t size) {
        size_t old_length = this->getLength();
        char* old_data = this->data;
        this->size = size;
        this->data = new char[size];
        for (size_t i = 0; i < size; i++) {
            if (i < old_length) {
                this->data[i] = old_data[i];
            }
            else {
                this->data[i] = '\0';
            }
        }
        delete[] old_data;
        this->data[size] = '\0';
    }

    void String::add(const String& text) {
        size_t new_size = this->size + text.size;
        setLength(new_size);

        size_t length = getLength();
        for (size_t i = length; i < new_size; i++) {
            this->data[i] = text.data[i - length];
        }
    }

    char String::get(size_t pos) const {
        if (pos > getLength()) {
            return '\0';
        }
        return data[pos];
    }

    bool String::compare(const String& string) const {
        return strcmp(this->data, string.data) == 0;
    }

    char String::operator[](size_t pos) {
        return this->get(pos);
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