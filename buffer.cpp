#include "buffer.h"

Buffer::Buffer() {
  index = 0;
}

bool Buffer::add(const std::string& str) {
  int len = str.length();
  if (index + len >= kBufSize)
    return false;
  str.copy(data, len, index);
  index = len;
  data[index++] = '\n';
  return true;
}

void Buffer::writeToFile(const std::string& path) {
  std::cout << data;
}

