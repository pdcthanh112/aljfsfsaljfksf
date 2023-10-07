#include <iostream>

class Shape {
 public:
  virtual void draw() = 0;
};

class Circle : public Shape {
 public:
  void draw() override {
    std::cout << "Drawing Circle" << std::endl;
  }
};

class Square : public Shape {
 public:
  void draw() override {
    std::cout << "Drawing Square" << std::endl;
  }
};

class Rectangle : public Shape {
 public:
  void draw() override {
    std::cout << "Drawing Rectangle" << std::endl;
  }
};

class ShapeFactory {
 public:
  static Shape* createShape(int type) {
    switch (type) {
      case 1:
        return new Circle();
      case 2:
        return new Square();
      case 3:
        return new Rectangle();
      default:
        return nullptr;
    }
  }
};
