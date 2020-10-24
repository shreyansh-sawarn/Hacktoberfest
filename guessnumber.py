# importing module
import random

number = random.randint(0, 5)
guessing = 0

while guessing < 3:
    player = int(input("Enter Your Guess : "))
    if player == number:
        print("Your Guess is right")
        break
    else:
        print("Your guess is wrong")
        guessing += 1

print("Your Game has ended")
print("The guess number is " + str(number))