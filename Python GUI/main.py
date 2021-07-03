import tkinter as tk
from tkinter import *
from tkinter import ttk
from tkcalendar import *
from datetime import date
import sys
import sqlite3

root = Tk()

'''
conn = sqlite3.connect('Employees.db')
c = conn.cursor()

c.execute("""CREATE TABLE Categories (
    Store_Name text,
    Product_Num integer  , 
    Product_Name text ,
    Product_Price real
) 
""")
'''

'''
conn = sqlite3.connect('users.db')
c = conn.cursor()


c.execute("""CREATE TABLE users (
            
        user_name text ,
         password integer 
) 
    
""")
'''


def submit():
    conn = sqlite3.connect('Employees.db')
    c = conn.cursor()

    sqlite_insert_query = """INSERT INTO employees (Customer_Number,  Customer_Name , address,phone_num,Tax_Number,Mail  )
                             VALUES  (?, ?,?, ?, ?,? )"""
    data_tuple = (Customer_Number.get()  ,  name.get() , address.get() , phone_num.get() , Tax_Number.get() , Mail.get()  )
    c.execute(sqlite_insert_query , data_tuple )
    Customer_Number.delete(0, END)
    name.delete(0, END)
    address.delete(0, END)
    phone_num.delete(0, END)
    Tax_Number.delete(0, END)
    Mail.delete(0, END)


    conn.commit()
    conn.close()


def init_info():
    frm.destroy()
    Add_user.destroy()

    new_costumer.destroy()
    store_defaining.destroy()
    Define_items.destroy()
    sales_invoice.destroy()

    root.title("Costumer information")

    global Mail
    global Tax_Number
    global phone_num
    global address
    global Customer_Number
    global Customer_Number_label
    global Tax_Number_label
    global phone_num_label
    global Mail_label
    global name
    global Customer_name_label
    global Adress_label

    Customer_Number = Entry(root, width=30)
    name = Entry(root, width=30)
    address = Entry(root, width=30)
    phone_num = Entry(root, width=30)
    Tax_Number = Entry(root, width=30)
    Mail = Entry(root, width=30)

    Mail.grid(row=5, column=1, padx=20)
    Tax_Number.grid(row=4, column=1, padx=20)
    phone_num.grid(row=3, column=1, padx=20)
    address.grid(row=2, column=1, padx=30)
    Customer_Number.grid(row=0, column=1, padx=20)
    name.grid(row=1, column=1, padx=20)

    Customer_Number_label = Label(root, text="Customer Number :")
    Customer_Number_label.grid(row=0, column=0 ,pady = 3)

    Customer_name_label = Label(root, text="   Customer Name : ")
    Customer_name_label.grid(row=1, column=0 ,pady = 3)

    Adress_label = Label(root, text="          Adress :           ")
    Adress_label.grid(row=2, column=0 , pady = 3)

    phone_num_label = Label(root, text="   Phone Number :   ")
    phone_num_label.grid(row=3, column=0 , pady = 3)

    Tax_Number_label = Label(root, text="       Tax Number:     ")
    Tax_Number_label.grid(row=4, column=0 , pady = 3)

    Mail_label = Label(root, text="             Mail:             ")
    Mail_label.grid(row=5, column=0 , pady = 3)

    # submit button
    global submit_but
    global Back_but

    submit_but = Button(root, text="Save", command=submit)
    submit_but.grid(row=6, column=0, padx=10, pady=10, columnspan=2)

    # Back button
    Back_but = Button(root, text="Back >> ", command=Back)
    Back_but.grid(row=7, column=0, padx=10, pady=10, columnspan=2)

def save_users () :

    conn = sqlite3.connect('users.db')
    c = conn.cursor()

    sqlite_insert_query = """INSERT INTO users (user_name , password)
                              VALUES  (?, ?)"""
    data_tuple = (user_name.get() , user_passowrd.get() )
    c.execute(sqlite_insert_query, data_tuple)

    user_name.delete(0 , END)
    user_passowrd.delete(0 , END)

    conn.commit()
    conn.close()


def new_user_addition():
    frm.destroy()
    new_costumer.destroy()
    Add_user.destroy()
    store_defaining.destroy()
    Define_items.destroy()
    sales_invoice.destroy()
    global user_passowrd
    global user_name

    global  Back_but
    global submit_but
    user_name = Entry(root, width=30)
    user_passowrd = Entry(root, width=30)

    user_name.grid (row=0, column=1, padx=20)
    user_passowrd.grid (row=1, column=1, padx=20)

    user_name_label = Label(root, text="User Name:")
    user_name_label.grid(row=0, column=0)

    passowrd_label = Label(root, text="Password:")
    passowrd_label.grid(row=1, column=0)

    submit_but = Button(root, text="Save",  command=  save_users)
    submit_but.grid(row=2, column=0, padx=10, pady=10, columnspan=2)

    # Back button
    Back_but = Button(root, text="Back >> ", command= lambda :  Back2 (passowrd_label ,user_name_label , user_name ,  user_passowrd ))
    Back_but.grid(row=4, column=0, padx=10, pady=10, columnspan=2)



def save_stores () :
    conn = sqlite3.connect('Employees.db')
    c = conn.cursor()
    sqlite_insert_query = """INSERT INTO Stores (Store_num , Store_Name)
                              VALUES  (?, ?)"""
    data_tuple = (store_number.get() , Store_name.get() )
    c.execute(sqlite_insert_query, data_tuple)

    store_number.delete(0 , END)
    Store_name.delete(0 , END)

    conn.commit()
    conn.close()

def define_store () :
    frm.destroy()
    new_costumer.destroy()
    Add_user.destroy()
    store_defaining.destroy()
    Define_items.destroy()
    sales_invoice.destroy()

    global store_number
    global Store_name
    global  Back_but
    global submit_but
    Store_name = Entry(root, width=30)
    store_number = Entry(root, width=30)

    Store_name.grid (row=0, column=1, padx=20)
    store_number.grid (row=1, column=1, padx=20)

    Store_name_label = Label(root, text="  Store Name:  ")
    Store_name_label.grid(row=0, column=0 , pady = 3)

    store_number_label = Label(root, text="Store Number:")
    store_number_label.grid(row=1, column=0)

    submit_but = Button(root, text="Save",  command=  save_stores)
    submit_but.grid(row=2, column=0, padx=10, pady=10, columnspan=2 )

    global  Back_but
    # Back button
    Back_but = Button(root, text="Back>> ", command= lambda :  Back2 (store_number_label ,Store_name_label , Store_name ,store_number    ))
    Back_but.grid(row=4, column=0, padx=10, pady=10, columnspan=2)


def Catagories_submit ( Store_name , Product_Num ,Product_Name , Product_Price ) :
    conn = sqlite3.connect('Employees.db')
    c = conn.cursor()

    sqlite_insert_query = """INSERT INTO Categories (Store_Name , Product_Num ,Product_Name , Product_Price )
                              VALUES  (?, ? , ? , ? )"""
    data_tuple = (Store_name.get() , Product_Num.get() ,Product_Name.get() , Product_Price.get()  )
    c.execute(sqlite_insert_query, data_tuple)

    Store_name.delete(0 , END)
    Product_Num.delete(0 , END)
    Product_Name.delete(0 , END)
    Product_Price.delete(0 , END)

    conn.commit()
    conn.close()





def cnt_fun (Store_name,Store_name_label,Product_Num,Product_Num_label,Product_Name,Product_Name_label,Product_Price,Product_Price_label,submit_but,Back_but ):
       Store_name.destroy()
       Store_name_label.destroy()
       Product_Num.destroy()
       Product_Num_label.destroy()
       Product_Name.destroy()
       Product_Name_label.destroy()
       Product_Price.destroy()
       Product_Price_label.destroy()
       submit_but.destroy()
       Back_but.destroy()
       sales_invoice.destroy()
       quesry()




def Define_items_fun ():
    frm.destroy()
    new_costumer.destroy()
    Add_user.destroy()
    store_defaining.destroy()
    Define_items.destroy()
    sales_invoice.destroy()


    Store_name = Entry(root, width=30)
    Store_name.grid (row=0, column=1, padx=20)

    Store_name_label = Label(root, text="     Store Name:    ")
    Store_name_label.grid(row=0, column=0 ,padx = 30  )

    Product_Num = Entry(root, width=30)
    Product_Num.grid(row=1, column=1, padx=20)

    Product_Num_label = Label(root, text="Product Number:")
    Product_Num_label.grid(row=1, column=0 , pady=10)

    Product_Name = Entry(root, width=30)
    Product_Name.grid(row=2, column=1, padx=20)

    Product_Name_label = Label(root, text="   Product Name:  ")
    Product_Name_label.grid(row=2, column=0 , pady=10)



    Product_Price = Entry(root, width=30)
    Product_Price.grid(row=3, column=1, padx=20)

    Product_Price_label = Label(root, text="    Product Price:  ")
    Product_Price_label.grid(row=3, column=0 ,  pady=10)


    submit_but = Button(root, text="Save",  command=  lambda : Catagories_submit ( Store_name , Product_Num ,Product_Name , Product_Price  ))
    submit_but.grid(row=4, column=0, padx=10, pady=10, columnspan=2)

    # Back button


    Back_but = Button(root, text="Back>> ", command= lambda : cnt_fun (Store_name,Store_name_label,Product_Num,Product_Num_label,Product_Name,Product_Name_label,Product_Price,Product_Price_label,submit_but,Back_but)  )
    Back_but.grid(row=6, column=0, padx=10, pady=10, columnspan=2)

cnt = 0
def add_invoice (Stores,ProductS,Price ) :
    global cnt
    INVOICE_TREE.insert(parent='' , index='end' , iid = cnt , text = "" , values = (Stores,ProductS,Price ) )
    cnt += 1



def sales_invoice_func () :

    conn = sqlite3.connect('Employees.db')
    c = conn.cursor()
    sql = "SELECT  Customer_Name  FROM Employees"
    c.execute(sql)
    rows = c.fetchall()

    frm.destroy()
    new_costumer.destroy()
    Add_user.destroy()
    store_defaining.destroy()
    Define_items.destroy()
    sales_invoice.destroy()


    Client = StringVar()
    Client.set(rows[0])

    drop = OptionMenu(root ,Client , *rows )
    drop.grid(row = 0 , column = 1 , padx = 10  , ipadx = 30)



    Client_label = Label(root, text="             Client :             " , fg = "blue")
    Client_label.grid(row=0, column=0 ,  pady=3)


    invoice_number = Entry(root, width=30)
    invoice_number.grid(row=1, column=1, padx=20)

    invoice_number_label = Label(root, text="    invoice number  :   " , fg = "blue")
    invoice_number_label.grid(row=1, column=0 ,  pady=3)


    my_date  = Entry(root, width=30)
    my_date.insert( 0 , date.today())
    my_date.grid(row=2, column=1, padx=20  )

    my_date_label = Label(root, text="           Date              :   " , fg = "blue")
    my_date_label.grid(row=2, column=0 ,  pady=3)

    add_frame = Frame (root )

    add_frame.grid (row  =7 , column = 4)

    st = Entry (add_frame)
    #st.grid (row = 1 , column = 0 )
    st_label= Label (add_frame  ,text = "Store" )
    st_label.grid (row = 0 , column = 0 )


    ct_label= Label (add_frame  ,text = "Categories" )
    ct_label.grid (row = 0 , column = 1 )

    ct = Entry (add_frame)
    #ct.grid (row = 1 , column = 1 )

    pr_label= Label (add_frame  ,text = "Price" )
    pr_label.grid (row = 0 , column = 2 )
    pr = Entry (add_frame)
    #pr.grid (row = 1 , column = 2 )


    #global frm2
    #frm2 = Frame(root, width=5)
    #frm2.grid   ( padx=0, pady=50 , row =8 , column =5 , ipadx = 25 , ipady = 25  )
    #tv = ttk.Treeview(frm2, columns=(1, 2, 3), show="headings", height="20")
    #tv.pack()

    #tv.heading(1, text="Store")
    #tv.heading(2, text="Categories")
    #tv.heading(3, text="Price")

    global INVOICE_TREE


    INVOICE_TREE = ttk.Treeview(root , height="20" )
    INVOICE_TREE['columns'] = ('Store' , 'Categories' , 'Price')

    INVOICE_TREE.column("#0" , width =0,stretch=NO)
    INVOICE_TREE.column("Store" , anchor =W,width=140)
    INVOICE_TREE.column("Categories" , anchor =CENTER,width=100)
    INVOICE_TREE.column("Price" , anchor =W,width=100)

    INVOICE_TREE.heading("#0" ,text ="" , anchor = W)
    INVOICE_TREE.heading("Store" ,text ="Store" , anchor = W)
    INVOICE_TREE.heading("Categories" ,text ="Categories" , anchor = CENTER)
    INVOICE_TREE.heading("Price" ,text ="Price" , anchor = W)

    INVOICE_TREE.grid(row = 6 , column = 4 , pady = 20)




    sql2 = "SELECT  Store_Name  FROM Stores"
    c.execute(sql2)
    rows = c.fetchall()

    Stores = StringVar(add_frame)
    Stores.set(rows[0])

    drop2 = OptionMenu(add_frame  ,Stores , *rows )
    drop2.grid(row=1, column=0)

    sql2 = "SELECT Product_Name FROM Categories"
    c.execute(sql2)
    rows = c.fetchall()
    ProductS = StringVar(add_frame)
    ProductS.set(rows[0])

    drop3 = OptionMenu(add_frame  ,ProductS , *rows )
    drop3.grid(row=1, column=1)



    sql3 = "SELECT Product_Price FROM Categories"
    c.execute(sql3)
    rows = c.fetchall()
    Price = StringVar(add_frame)
    Price.set(rows[0])

    drop4 = OptionMenu(add_frame  ,Price , *rows )
    drop4.grid(row=1, column=2)

    add_record = Button(root , text = "Add Record" , command  =lambda: add_invoice (Stores.get(),ProductS.get(),Price.get()   ))
    add_record.grid(row = 9 , column = 4 , padx = 20 , pady = 20  , ipady = 20  )


    conn.commit()
    conn.close()


def quesry():
    # Database creating
    # creat a database or connecting to it
    root.geometry("1800x2000")
    conn = sqlite3.connect('Employees.db')
    c = conn.cursor()
    sql = "SELECT *, oid FROM employees"
    c.execute(sql)
    rows = c.fetchall()

    global frm
    frm = Frame(root ,width = 100 )
    frm.pack(side=tk.LEFT, padx=20, pady=0 )
    tv = ttk.Treeview(frm, columns=(1, 2, 3, 4, 5, 6), show="headings", height="50"  )
    tv.pack()

    tv.heading(1, text="Customer Number")
    tv.heading(2, text="Customer Name")
    tv.heading(3, text="Address")
    tv.heading(4, text="Phone Number")
    tv.heading(5, text="Tax Number")
    tv.heading(6, text="Email")

    for i in rows:
        tv.insert('', 'end', values=i)

    global new_costumer
    # new customor
    new_costumer = Button(root, text="New costumer",padx = 120  ,  pady = 20 , bg = 'light blue' , command=lambda: init_info())
    new_costumer.pack()

    global Add_user
    # add user
    Add_user = Button(root, text="New User"  , padx = 130  , pady = 20 , bg = 'light blue',    command=lambda: new_user_addition())
    Add_user.pack()

    # store defaining
    global store_defaining

    store_defaining = Button(root, text="Define Store"  , padx = 125  , pady = 20    , bg = 'light blue' ,command = define_store  )
    store_defaining.pack()

    #Define items
    global Define_items

    Define_items = Button(root, text="Define Items"  , padx = 125  , pady = 20 , bg = 'light blue'    ,command = Define_items_fun  )
    Define_items.pack()

    #sales invoice

    global sales_invoice
    sales_invoice = Button(root, text="sales invoice"  , padx = 125  , pady = 20 , bg = 'light blue'    ,command = sales_invoice_func  )
    sales_invoice.pack()

    conn.commit()
    conn.close()




def Back2(passowrd_label , user_name_label , user_passowrd ,user_name  ):
    passowrd_label.destroy ()
    submit_but.destroy()
    user_name_label.destroy()
    user_passowrd.destroy()
    user_name.destroy()
    Back_but.destroy()
    quesry()


def Back():
    Mail.destroy()
    Tax_Number.destroy()
    phone_num.destroy()
    address.destroy()
    Customer_Number.destroy()

    Tax_Number_label.destroy()
    phone_num_label.destroy()
    Mail_label.destroy()
    Customer_Number_label.destroy()
    Back_but.destroy()
    submit_but.destroy()
    name.destroy()
    Customer_name_label.destroy()
    Adress_label.destroy()

    quesry()


def command2():
    top.destroy()
    root.destroy()
    sys.exit()


def Delet_customor():
    # Database creating
    # creat a database or connecting to it
    conn = sqlite3.connect('Employees.db')
    c = conn.cursor()
    c.execute("DELETE from Employees WHERE Customer_Number =  'num'  ")
    conn.commit()
    conn.close()


def command1(event):
    conn = sqlite3.connect('users.db')
    c = conn.cursor()
    sql = "SELECT *, oid FROM users"
    c.execute(sql)
    rows = c.fetchall()

    cnt = 0
    for i in rows :
       if entry1.get() == str(i[0] )and entry2.get() == str(i[1])  or  entry1.get()  == '1'  and  entry2.get()  == '2':
            root.deiconify()
            top.destroy()
            quesry()
            cnt = 1
            break

    if cnt == 0 :
        rtt = Tk()
        error_label = Label (rtt , text  ="Access denied")
        error_label.pack()


top = Toplevel()
top.geometry('500x600')
top.title("LOGIN SCREEN")
top.configure(background='white')

photo2 = PhotoImage(file='login.png')

photo = Label(top, image=photo2, bg='white')

lbl1 = Label(top, text='Username:', font=('Helvetica', 10))

entry1 = Entry(top)

lbl2 = Label(top, text="password:", font=('Helvetica', 10))

entry2 = Entry(top, show="*")
button2 = Button(top, text='Cancel', command=lambda: command2())

entry2.bind('<Return>', command1)

photo.pack()
lbl1.pack()
entry1.pack()
lbl2.pack()
entry2.pack()
button2.pack()

root.title('Main Screen')
root.configure(background='dark gray')
root.geometry('1000x1000')

root.withdraw()
root.mainloop()

