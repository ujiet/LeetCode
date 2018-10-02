import os
import numpy as np
import tkinter as tk

from tkinter import ttk
from PIL import ImageTk, Image

window = tk.Tk()
window.title('Neural Network Hw1')
window.geometry('960x640')

# image
img = ImageTk.PhotoImage(Image.open("output.png"))
panel = tk.Label(window, image = img)
panel.place(x = 20, y = 20)

# combobox
def go(*args):   
    global dataset_name 
    dataset_name = comboxlist.get() + '.txt'
    print(dataset_name)

dataset_list = ['perceptron1', 'perceptron2', 'perceptron3']
    
comvalue = tk.StringVar()
comboxlist = ttk.Combobox(window,textvariable = comvalue) 
comboxlist['values'] = dataset_list
comboxlist.current()  
comboxlist.bind("<<ComboboxSelected>>", go) 
comboxlist.place(x = 700, y = 80)

# label
tk.Label(window, text='選擇資料集').place(x = 700, y = 50)
tk.Label(window, text='設定初始鍵結值').place(x = 700, y = 150)
tk.Label(window, text='設定學習次數').place(x = 700, y = 250)
tk.Label(window, text='設定學習效率').place(x = 700, y = 350)

# box
var_w_init = tk.StringVar()
var_w_init.set('[0,1]')
entry_w_init = tk.Entry(window, textvariable = var_w_init)
entry_w_init.place(x = 700, y = 180)

var_n = tk.StringVar()
var_n.set('0')
entry_n = tk.Entry(window, textvariable = var_n)
entry_n.place(x = 700, y = 280)

var_eta = tk.StringVar()
var_eta.set('0')
entry_eta = tk.Entry(window, textvariable = var_eta)
entry_eta.place(x = 700, y = 380)

# button
data = []

def train_start():
    file_path = os.path.join('DataSet', dataset_name)
    with open(file_path) as file:
        data_str = list(file)
        global data
        temp = []
        for line in data_str:
            temp = line.split()
            temp = list(map(float, temp))
            data.append(temp)

        print(data)
        file.close

def test_start():
    pass

btn_train_start = tk.Button(window, text = '開始訓練', command = train_start)
btn_train_start.place(x = 700, y = 450)
btn_test_start = tk.Button(window, text = '開始測試', command = test_start)
btn_test_start.place(x = 800, y = 450)

window.mainloop()
