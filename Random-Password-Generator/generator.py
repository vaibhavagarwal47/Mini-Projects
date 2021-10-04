from tkinter import *
import random
import array
import os
import json

global root
global generated_pass
global submit
global randomPassword
global password_size
global frame

def create_password():
    DIGITS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    LOCASE_CHARACTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                        'i', 'j', 'k', 'm', 'n', 'o', 'p', 'q',
                        'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
                        'z']

    UPCASE_CHARACTERS = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'M', 'N', 'O', 'p', 'Q',
                        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
                        'Z']

    SYMBOLS = ['@', '#', '$', '%', '=', ':', '?', '.', '/', '|', '~', '>',
               '*', '(', ')', '<']

    COMBINED_LIST = DIGITS + UPCASE_CHARACTERS + LOCASE_CHARACTERS + SYMBOLS

    rand_digit = random.choice(DIGITS)
    rand_upper = random.choice(UPCASE_CHARACTERS)
    rand_lower = random.choice(LOCASE_CHARACTERS)
    rand_symbol = random.choice(SYMBOLS)
    temp_pass = rand_digit + rand_upper + rand_lower + rand_symbol

    for x in range(int(password_size.get())-4):
        temp_pass = temp_pass + random.choice(COMBINED_LIST)
        temp_pass_list = array.array('u', temp_pass)
        random.shuffle(temp_pass_list)

    password = ""
    for x in temp_pass_list:
            password = password + x
            
    return password  

def on_click():
    randomPassword.set(create_password())

if __name__=='__main__':
    root = Tk()
    root.geometry('400x600')
    root.configure(background = '#424543')
    root.title('Password Application')
    randomPassword = StringVar(root)
    password_size = StringVar(root, value='16')
    Font_tuple = ("Comic Sans MS",12 ,'bold')
    generate_random_password = Label(root, text = 'Generate Strong Random Password !', font =("Comic Sans MS",15 ,'bold'), bg='#424543', fg='white')
    generate_random_password.place(x=20, y=20)
    Pasword_length = Label(root, text = 'Password Length: ', bg = '#424543', fg = 'white', font = Font_tuple)
    Pasword_length.place(x=25, y=103)
    generated_pass = Entry(root, textvariable = randomPassword, width=30, bg='white')
    generated_pass.place(x=110, y=70)
    submit = Button(root, text='Generate', command = on_click,  width=10, font = ("Comic Sans MS",10 ,'normal') ,bg='#a2a6a4', fg = 'white')
    submit.place(x=150, y=150)
    length = Spinbox(root, from_ = 8, to_ = 120, textvariable = password_size , width = 8)
    length.place(x=170, y=110)

    root.resizable(False, False)
    root.mainloop()
