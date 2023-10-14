#include <iostream>

class Device {
 public:
  std::string id;
  std::string name;
  int room;
  bool status;

  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
};

class Light : public Device {
 public:
  int brightness;
};

class BrightLight : public Light {
 private:
 public:
  void turnOn() {
    std::cout << "Bat den chieu sang";
  }
};

class SleepLamp : public Light {
 public:
  std::string color;

 public:
  void turnOn() {
    std::cout << "Bat den ngu";
  }
};

class AirConditioner {
 public:
  int temperature;
  std::string mode;
  int level;

 public:
  void turnOn() {
    std::cout << "Bat dieu hoa";
  }
};

class Television : public Device {
 public:
  int volumn;
  std::string chanel;

 public:
  void turnOn() {
    std::cout << "Bat TV";
  }
};
