int main() {

  int n;
  std::cout << "enter n";
  std::cin >> n;

  // main loop of patterns start here
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << "* ";
    }
    std::cout << '\n';
  }
  return 0;
}

basic triangle
