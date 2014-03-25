#ifndef BUFFER_H_
#define BUFFER_H_

#include <string>
#include <mutex>

class Buffer {
public:
  Buffer();
  ~Buffer();
  void Add(const std::string& str);
  void set_path(const std::string& path);
  
private:
  void WriteToFile();
  static const int kBufSize = 4096;
  char data_[kBufSize];
  int index_;
  std::string path_to_file_;
  std::mutex mutex_;
};

#endif // BUFFER_H_
