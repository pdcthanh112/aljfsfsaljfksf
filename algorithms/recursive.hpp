// Đệ quy tuyến tính (chỉ gọi lại hàm 1 lần)
unsigned long long factorial(unsigned int n) {
  if (n == 0 || n == 1)
    return 1;
  return n * factorial(n - 1);
}

// fibonacci không dùng quy hoặc động
unsigned long long fibonacciWithoutDynamicPrograming(int n) {
  if (n == 1 || n == 2) return 1;
  return fibonacciWithoutDynamicPrograming(n - 1) + fibonacciWithoutDynamicPrograming(n - 2);
}

// fibonacci với quy hoặc động
unsigned long long fibonacciWithDynamicPrograming(int n) {
  int fib[n + 1];
  fib[0] = fib[1] = 1;
  for (int i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib[n];
}