#include "buffer.h"

#include <fstream>
#include <cstring>

Buffer::Buffer() {
  index = 0;
  memset(data, '\0', kBufSize);
}

Buffer::~Buffer() {
  writeToFile();  
}

void Buffer::add(const std::string& str) {
  int len = str.length();
  if (index + len >= kBufSize) {
    writeToFile();
    memset(data, '\0', kBufSize);
    index = 0;
  }
  str.copy(data + index, len, 0);
  index += len;
  data[index++] = '\n';
}

void Buffer::setPath(const std::string& path) {
  pathToFile = path;
}

void Buffer::writeToFile() {
  std::ofstream out(pathToFile, std::ios_base::app);
  out.write(data, index);
  out.close();
}

