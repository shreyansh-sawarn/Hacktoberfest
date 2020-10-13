// Program make a simple calculator
import 'dart:io';

main() {
  print("Select operation.\n1.Add\n2.Subtract\n3.Multiply\n4.Divide");
  while (true) {
    print("Enter choice(1/2/3/4): ");
    var choice = stdin.readLineSync();
    print("Enter number: ");
    int num1 = int.parse(stdin.readLineSync());
    print("Enter other number: ");
    int num2 = int.parse(stdin.readLineSync());
    switch (int.parse(choice)) {
      case 1:
        print(add(num1, num2));
        break;
      case 2:
        print(subtract(num1, num2));
        break;
      case 3:
        print(multiply(num1, num2));
        break;
      case 4:
        print(divide(num1, num2));
        break;
    }
  }
}

// This function adds two numbers
int add(x, y) => x + y;

// This function subtracts two numbers
int subtract(x, y) => x - y;

// This function multiplies two numbers
int multiply(x, y) => x * y;

// This function divides two numbers
int divide(x, y) => x / y;
