from tkinter import *
import sys
import time
def times():
    current_time=time.strftime("%H:%M:%S")
    clock.config(text=current_time)
    clock.after(100, times)

root=Tk()
root.geometry("330x195")
clock=Label(root, font=("Comic Sans MS", 50, "bold"), bg="red")
clock.grid(row=3, column=2, pady=0, padx=10)
times()

digi=Label(root, text='Digital Clock', font=('Comic Sans MS', 24, 'bold'))
digi.grid(row=0, column=2)

notation=Label(root, text=" hours      minutes     seconds", font=('Comic Sans MS', 15, 'bold'))
notation.grid(row=2, column=2)

root.mainloop()
