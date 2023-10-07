#include <iostream>

class Singleton {
 private:
  static Singleton* instance;

  Singleton() {}
  ~Singleton() {}

 public:
  static Singleton* getInstance() {
    if (!instance) {
      instance = new Singleton();
    }
    return instance;
  }

  void showMessage() {
    std::cout << "Hello from Singleton!" << std::endl;
  }
};

Singleton* Singleton::instance = nullptr;

int main() {
  Singleton* singleton = Singleton::getInstance();

  singleton->showMessage();

  return 0;
}

// ví dụ, khởi tạo duy nhất 1 logger để ghi log
class Logger {
 private:
  static Logger* instance;
  Logger() {}

 public:
  static Logger* getInstance() {
    if (!instance) {
      instance = new Logger();
    }
    return instance;
  }
};

Logger* Logger::instance = nullptr;
