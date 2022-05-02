// Copyright 2022 qqq <polyakovdd@student.bmstu.ru>

#include "../include/string.hpp"

String::~String() { delete[] Data; }

String::String() = default;

String::String(const char* data)
    : Length(strlen(data)), Data(new char[Length + 1]) {
  std::snprintf(Data, Length + 2, "%s", data);
}

String::String(const String& rhs)
    : Length(rhs.Length), Data(new char[Length + 1]) {
  std::snprintf(Data, Length + 2, "%s", rhs.Data);
}

String& String::operator=(const String& rhs) {
  if (&rhs != this) {
    Length = rhs.Length;
    delete[] Data;
    Data = new char[Length + 1];
    std::snprintf(Data, Length + 2, "%s", rhs.Data);
  }
  return *this;
}

String& String::operator+=(const String& rhs) {
  char* tempStr = new char[Length + rhs.Length + 1];
  std::snprintf(tempStr, Length + 1, "%s", Data);
  std::snprintf(tempStr + Length, rhs.Length + 2, "%s", rhs.Data);
  Length += rhs.Length;
  delete[] Data;
  Data = tempStr;
  return *this;
}

String& String::operator*=(unsigned int m) {
  char* tempStr = new char[Length + 1];
  std::snprintf(tempStr, Length + 1, "%s", Data);
  int oldLen = Length;
  Length = m * Length;
  delete[] Data;
  Data = new char[Length + 1];
  for (size_t i = 0; i < m; ++i) {
    std::snprintf(Data + i * oldLen, Length + 1, "%s", tempStr);
  }
  Data[Length] = '\0';
  delete[] tempStr;
  return *this;
}

bool String::operator==(const String& rhs) const {
  return strcmp(Data, rhs.Data) == 0;
}

bool String::operator<(const String& rhs) const {
  return strcmp(Data, rhs.Data) < 0;
}

size_t String::Find(const String& substr) const {
  if (Length >= substr.Length) {
    for (size_t i = 0; i <= Length - substr.Length; ++i) {
      for (size_t j = 0; j < substr.Length; ++j) {
        if (substr[j] != Data[i + j]) {
          continue;
        }
        if (j == substr.Length - 1) {
          return i;
        }
      }
    }
  }
  return -1;
}
size_t String::Size() const { return Length; }

bool String::Empty() const { return Data == nullptr; }

void String::Replace(char oldSymbol, char newSymbol) {
  for (size_t i = 0; i < Length; ++i) {
    if (Data[i] == oldSymbol) Data[i] = newSymbol;
  }
}

char& String::operator[](size_t index) { return Data[index]; }

char String::operator[](size_t index) const { return Data[index]; }

void String::RTrim(char symbol) {
  char* tempString = new char[Length + 1];
  std::snprintf(tempString, Length + 1, "%s", Data);
  for (size_t i = Length - 1; i != 0; --i) {
    if (tempString[i] == symbol) {
      Length--;
    } else {
      break;
    }
  }
  delete[] Data;
  Data = new char[Length + 1];
  std::snprintf(Data, Length + 1, "%s", tempString);
  Data[Length] = '\0';
  delete[] tempString;
}
void String::LTrim(char symbol) {
  char* tempString = new char[Length + 1];
  std::snprintf(tempString, Length + 1, "%s", Data);
  size_t i = 0;
  for (i = 0; i < Length; ++i) {
    if (Data[i] != symbol) break;
  }
  Length -= i;
  delete[] Data;
  Data = new char[Length + 1];
  std::snprintf(Data, Length + 1, "%s", tempString + i);
  Data[Length] = '\0';
  delete[] tempString;
}
void String::swap(String& oth) {
  std::swap(Data, oth.Data);
  std::swap(Length, oth.Length);
}

std::ostream& operator<<(std::ostream& out, const String& str) {
  out << str.Data;
  return out;
}

String operator+(const String& a, const String& b) {
  String result(a);
  result += b;
  return result;
}

String operator*(const String& a, unsigned int b) {
  String result(a);
  result *= b;
  return result;
}

bool operator!=(const String& a, const String& b) { return !(a == b); }

bool operator>(const String& a, const String& b) { return b < a; }
