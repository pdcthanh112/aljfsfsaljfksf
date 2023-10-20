// Allow only 1 instance:
#include <iostream>
#include <string>

class Singleton {
 public:
  std::string name;
  static Singleton *GetInstance() {
    static Singleton *singleton = new Singleton();
    return singleton;
  }

 private:
  Singleton() = default;
};

int main() {
  Singleton *s1 = Singleton::GetInstance();
  Singleton *s2 = Singleton::GetInstance();
  s1->name = "aaa";
  s2->name = "bbb";
  std::cout << s1->name << std::endl;
}

// Limit the number of instances
#include <iostream>
#include <string>

#define LIMIT_MAX_INSTANCE 5

class Singleton {
 public:
  std::string name;
  static int instance_count;
  static Singleton *GetInstance() {
    if (instance_count >= LIMIT_MAX_INSTANCE)
      return NULL;
    Singleton *singleton = new Singleton();
    instance_count++;
    return singleton;
  }

 private:
  Singleton() = default;
};

int Singleton::instance_count = 0;

int main() {
  Singleton *s1 = Singleton::GetInstance();
  Singleton *s2 = Singleton::GetInstance();
  Singleton *s3 = Singleton::GetInstance();
  if (s3 == NULL)
    std::cout << "s3 is NULL" << std::endl;
  s1->name = "aaa";
  s2->name = "bbb";
  std::cout << s1->name << std::endl;
}
