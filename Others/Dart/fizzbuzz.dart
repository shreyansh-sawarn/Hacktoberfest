// Shortest fizzbuzz program which can be written in dart language
void main() {
  for (int i = 1; i < 101; i++) print("${i%3 == 0 ? "Fizz": ""}${i%5 == 0 ? "Buzz": ""}".padLeft(1, "$i"));
}
