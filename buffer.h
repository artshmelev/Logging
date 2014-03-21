#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <iostream>

class Buffer {
public:
  Buffer();
  bool add(const std::string& str);
  void writeToFile(const std::string& path);

private:
  static const int kBufSize = 4096;
  char data[kBufSize];
  int index;
};

#endif // BUFFER_H
