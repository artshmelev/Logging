#ifndef BUFFER_H
#define BUFFER_H

#include <string>

class Buffer {
public:
  Buffer();
  ~Buffer();
  void add(const std::string& str);
  void setPath(const std::string& path);
  
private:
  void writeToFile();
  static const int kBufSize = 4096;
  char data[kBufSize];
  int index;
  std::string pathToFile;
};

#endif // BUFFER_H
