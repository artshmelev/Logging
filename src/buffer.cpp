#include <cstring>
#include <fstream>

#include "buffer.h"

Buffer::Buffer() {
  index_ = 0;
  memset(data_, '\0', kBufSize);
}

Buffer::~Buffer() {
  WriteToFile();  
}

void Buffer::Add(const std::string& str) {
  int len = str.length();
  mutex_.lock();
  if (index_ + len >= kBufSize) {
    WriteToFile();
    memset(data_, '\0', kBufSize);
    index_ = 0;
  }
  str.copy(data_ + index_, len, 0);
  index_ += len;
  data_[index_++] = '\n';
  mutex_.unlock();
}

void Buffer::set_path(const std::string& path) {
  path_to_file_ = path;
}

void Buffer::WriteToFile() {
  std::ofstream out(path_to_file_, std::ios_base::app);
  out.write(data_, index_);
  out.close();
}

