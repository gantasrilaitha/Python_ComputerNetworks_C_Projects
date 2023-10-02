import csv
def add():
    f=open('animal.csv','a',newline='')
    stwriter=csv.writer(f)
    name=input('enter name of pet owner')
    n=int(input('how many pets you want to register'))
    for i in range(n):
        slno=int(input('enter slno'))
        name=input('enter name of your pet')
        age=int(input('enter age of your pet'))
        g=input('enter gender of your pet')
        b=input('enter breed of your pet')
        d=[slno,name,age,g,b]
        stwriter.writerow(d)
    f.close()
def update():
    n=input('enter name of your pet to udate its age')
    g=int(input('enter new age'))
    o=int(input('enter old age'))
    f1=open('animal.csv','r')
    f1=''.join([i for i in f1])\
        .replace(str(o),str(g))
    f2=open('animal.csv','w')
    f2.writelines(f1,)
    f2.close()
def search():
    n=input('enter name of your pet')
    l=[];c=[]
    f=open('animal.csv','r')
    try:
        found=0
        streader=csv.reader(f)
        for rec in streader:
            if n in rec:
                found=1
                break
        if found==1:
            print('record found')
        else:
            print('record not found')
    except EOFError:
        f.close()
import tkinter
window = tkinter.Tk()
window.geometry('1000x80')
label = tkinter.Label(window, text = "WELCOME TO PET MANAGEMENT",font=5).pack()
window.mainloop()
import pandas as pd
c='y'
while c=='y':
    print('1)To register your pet')
    print('2)Book an appointment with a veterarian')
    print('3)Enjoy Salon Services')
    print('4)Buy someting for your pet')
    ch=int(input('enter choice'))
    if ch==1:
        a=input('áre you a new visitor and want to register youur pet?enter yes/no')
        if a=='yes':
            add()
            df=pd.read_csv('animal.csv',names=('slno','name','age','gender','breed'))
            print(df)
            window = tkinter.Tk()
            window.geometry('1000x80')
            label = tkinter.Label(window, text = " SUCESSFULLY REGISTERED",font=5).pack()
            window.mainloop()
        else:
            window = tkinter.Tk()
            window.geometry('1000x80')
            label = tkinter.Label(window, text = "YOU ARE ALREADY REGISTERED",font=5).pack()
            window.mainloop()
            update()
            df=pd.read_csv('animal.csv',names=('slno','name','age','gender','breed'))
            window = tkinter.Tk()
            window.geometry('1000x80')
            label = tkinter.Label(window, text = "RECORD UPDATED",font=5).pack()
            window.mainloop()
    elif ch==2:
        search()
        print('Available Doctors--------->')
        df=pd.read_csv('doctor.csv',names=('slno','name','fee','time of availability','room no'))
        print(df)
        d=input('enter doctor with whom yoou want to book an appointment')
        window = tkinter.Tk()
        window.geometry('1000x80')
        label = tkinter.Label(window, text = " APPONITMENT BOOKED ",font=5).pack()
        window.mainloop()
        f=open('doctor.csv','r')
        streader=csv.reader(f)
        for rec in streader:
            if d in rec:
                print('Consultancy Fee:',rec[2])
                print('Room No.',rec[4])
        window = tkinter.Tk()
        window.geometry('1000x80')
        label = tkinter.Label(window, text = " FEE PAID",font=5).pack()
        label = tkinter.Label(window, text = " PLEASE WAIT FOR YOUR TURN",font=5).pack()
        window.mainloop()
    elif ch==3:
        search()
        print('Available Salon Services--->')
        df=pd.read_csv('salon.csv',names=('slno','service','price','time of availability','counter no'))
        print(df)
        a=int(input('enter how many services you want for your pet'))
        s=0;l=[]
        for i in range(a):
            d=input('enter service')
            l.append(d)
        f=open('salon.csv','r')
        streader=csv.reader(f)
        for rec in streader:
            for i in l:
                if i in rec:
                    s+=int(rec[2])
                    print('COUNTER NO:',rec[4],'for',i)
        print('BILL:',s)
        window = tkinter.Tk()
        window.geometry('1000x80')
        label = tkinter.Label(window, text = " BILL PAID",font=5).pack()
        label = tkinter.Label(window, text = " PLEASE WAIT FOR YOUR TURN",font=5).pack()
        window.mainloop()
    elif ch==4:
        window = tkinter.Tk()
        window.geometry('1000x80')
        label = tkinter.Label(window, text = "WELCOME TO PET STORE \n BUY FOR YOUR PET",font=5).pack()
        window.mainloop()
        print('Available Products--->')
        df=pd.read_csv('store.csv',names=('slno','products','price','section no'))
        print(df)
        s=0;l=[]
        a=int(input('how many products you want'))
        for i in range(a):
            d=input('enter product')
            l.append(d)
        f=open('store.csv','r')
        streader=csv.reader(f)
        for rec in streader:
            for i in l:
                if i in rec:
                    s+=int(rec[2])
        print('BILL:',s)
        window = tkinter.Tk()
        window.geometry('1000x80')
        label = tkinter.Label(window, text = " BILL PAID",font=5).pack()
        label = tkinter.Label(window, text = " THANK YOU AND VISIT AGAIN",font=5).pack()
        window.mainloop()
    c=input('Do you want to continue? enter y/n')
