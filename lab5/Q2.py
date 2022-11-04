# Python progressbar

from tkinter import *
from tkinter.ttk import *
import time , math, random

# strat function is invoked on start button click 
def start():
    print('button clicked')
    # set the percent stringvar
    percent.set("Current Progress : 0.0%")
    # no_of files is value got from entry box
    no_of_files = int(no_of_files_entry.get())
    # disable button and entrybox 
    button["state"] = DISABLED
    no_of_files_entry["state"] = DISABLED
    # done denotes already downloaded files 
    done = 0
    # set bar value to 0 initially 
    bar['value'] = 0
    # update window for each button click 
    window.update()
    while True:
        # sleep time is a random time required for downloading the file 
        sleep_time = math.floor(random.uniform(1,5))
        # sleep 
        time.sleep(sleep_time)
        # set bar value with the percentage completed 
        bar['value']+=(1/no_of_files)*100
        # increment done 
        done += 1
        # set percent stringvar with correct percentage of download completed 
        percent.set("Current Progress : "+ "{0:.2f}".format((done/no_of_files)*100) + "%")
        # update window to see the changes made 
        window.update()
        # when all files are downloaded break the loop
        if done == no_of_files:
            break

    # update the percent stringvar to download completed  
    percent.set("Download Completed.")
    # set state of button and entrybox to normal 
    button["state"] = NORMAL
    no_of_files_entry["state"] = NORMAL

# create window 
window = Tk()
# give window a title
window.title('Progressbar Demo')
# set size of window 
window.geometry('500x200')

# let percent as the string variable which denotes percentage of progress in progressbar
percent = StringVar()

# create a progressbar 
bar = Progressbar(window,orient=HORIZONTAL,length=400 , mode='determinate')
# place the bar at correct place 
bar.place(relx=0.05,rely=0.1, relwidth=0.9,relheight=0.1)

# set percent initially to 0.0
percent.set("Current Progress : "+str(0.0)+ '%' )
# create a label to show percent variable 
percentLabel = Label(window, textvariable= percent , font =("Arial" , 14)).place(relx= 0.5, rely = 0.35, anchor=CENTER)

# let a variable
no_of_files_text = StringVar()
# set the variable 
no_of_files_text.set('No of files : ')
# create lable to show the string 
no_of_files_label = Label(window, textvariable= no_of_files_text , font =("Arial" , 14) )
# place the label at appropriate location 
no_of_files_label.place(relx= 0.05,rely=0.6,relwidth=0.3,relheight=0.15)

# create a entry to give input 
no_of_files_entry = Entry(window , font =("Arial" , 14) )
# place the entry box 
no_of_files_entry.place(relx= 0.37,rely=0.6,relwidth=0.3,relheight=0.15)

# set style of button 
st = Style()
st.configure('W.TButton', background='black', foreground='blue', font=('Arial', 12 ))
# create a button which is responsible for starting the progressbar progress
button = Button(window , text="Start", command=start , state= NORMAL , style='W.TButton')
# place the button at appropriate location 
button.place(relx= 0.7,rely=0.6,relwidth=0.25,relheight=0.15)

# mainloop for the window 
window.mainloop()