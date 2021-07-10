from tkinter import *
root =Tk()
root.title("Simple calculator")

e = Entry(root , width = 35 ,borderwidth = 5 , bg = "light blue")
e.grid(row = 0 , column = 0 ,  columnspan = 3 , padx = 10 , pady = 10   )


def add_bot (n) :
    current = e.get()
    e.delete(0 , END)
    e.insert(0 ,current +  n  )
    return



def clear_sc () :
    e.delete(0 , END)


def Button_add () :
    first_number =  e.get()
    global f_num
    f_num = int (first_number)
    global math
    math = "addition"
    e.delete(0 , END)
    return





def multi_fun () :
    first_number =  e.get()
    global temp
    temp = 1
    global f_num
    f_num = int  (first_number) * temp
    temp = f_num
    global math
    math = "multiplication"
    e.delete(0 , END)

    return



def sub_fun () :
    first_number = e.get()
    global f_num
    f_num = int(first_number)
    global math
    math = "subtraction"
    e.delete(0, END)
    return

def div_fun () :
    first_number = e.get()
    global f_num
    f_num = float(first_number)
    global math
    math = "division"
    e.delete(0, END)

    return



def Buttom_equal () :
   global  second_number
   second_number = e.get()
   e.delete(0,END)
   global result
   if (math == "addition") :
       result   = (int (second_number) + f_num)


   elif (math == "subtraction") :
       result   = ( float ( f_num ) - float (second_number))

   elif (math == "division"):
       result = (float ( f_num)/float(second_number) )


   elif (math == "multiplication"):
       result = ( f_num * int (second_number))






   e.insert(0 ,result)




bottun_1 = Button (root , text = "1" ,command = lambda : add_bot ("1") , padx = 40 , pady = 20 , bg = "yellow" )
bottun_2 = Button (root , text = "2",command = lambda : add_bot ("2"), padx = 40 , pady = 20 , bg = "yellow")
bottun_3 = Button (root , text = "3",command = lambda : add_bot ("3"), padx = 40 , pady = 20 , bg = "yellow")
bottun_4 = Button (root , text = "4",command = lambda : add_bot ("4") , padx = 40 , pady = 20 , bg = "yellow")
bottun_5 = Button (root , text = "5",command = lambda : add_bot ("5") , padx = 40 , pady = 20 , bg = "yellow")
bottun_6 = Button (root , text = "6",command = lambda : add_bot ("6"), padx = 40 , pady = 20 , bg = "yellow")
bottun_7 = Button (root , text = "7",command = lambda : add_bot ("7"), padx = 40 , pady = 20  , bg = "yellow")
bottun_8 = Button (root , text = "8",command = lambda : add_bot ("8"), padx = 40 , pady = 20 , bg = "yellow")
bottun_9 = Button (root , text = "9",command = lambda : add_bot ("9"), padx = 40 , pady = 20 , bg = "yellow")
bottun_0 = Button (root , text = "0",command = lambda : add_bot ("0"), padx = 40 , pady = 20 , bg = "yellow")
bottun_dot = Button (root , text = ".",command = lambda : add_bot ("."), padx = 40 , pady = 20 , bg = "yellow")


bottun_multi = Button (root , text = "x",command =  multi_fun , padx = 40 , pady = 20 , bg = "light blue")
bottun_sub = Button (root , text = "-",command =  sub_fun , padx = 40 , pady =20 ,bg =  "light blue")
bottun_div = Button (root , text = "/",command =  div_fun, padx = 40 , pady = 20 , bg =  "light blue")


bottun_add = Button (root , text = "+ ",command =  Button_add , padx = 37 , pady = 20 , bg =  "light blue")
bottun_equal = Button (root , text = "=",command =  Buttom_equal, padx = 90 , pady = 20 , bg =  "light blue")
bottun_clear = Button (root , text = "C",command =  clear_sc, padx = 90 , pady = 20  , bg =  "light blue")


bottun_1.grid (row =3  , column =  0 )
bottun_2.grid (row =3  , column =  1  )
bottun_3.grid (row =3  , column =  2  )

bottun_4.grid (row =2  , column =  0  )
bottun_5.grid (row =2  , column =  1  )
bottun_6.grid (row =2  , column =  2  )

bottun_7.grid (row =1  , column =  0   )
bottun_8.grid (row =1  , column =  1   )
bottun_9.grid (row =1  , column =  2   )

bottun_0.grid (row =4  , column =  0   )
bottun_add.grid (row =5  , column =  0   )


bottun_clear.grid (row=4  , column =  1  , columnspan = 2 )
bottun_equal.grid (row=5  , column =  1  , columnspan = 2 )

bottun_div.grid (row=6  , column =  0  )
bottun_multi.grid (row=6  , column =  1   )
bottun_sub.grid (row=6  , column =  2  )


root.mainloop()


