from time import sleep
import tkinter as tk
from tkinter.constants import ANCHOR 

# class for the bar square game 
class BarSquareGame:
    # function for initialization 
    def __init__(self):
        # a window to hold the canvas 
        self.window = tk.Tk()
        self.window.title('Canvas Demo')
        # a canvas to draw recangles
        self.canvas = tk.Canvas(self.window, height=250, width=300)
        # created rectangle bar 
        self.bar = self.canvas.create_rectangle(0, 0, 100, 12, fill='blue', tags="bar" , )
        # placed at desired position
        self.canvas.move(self.bar, 0, 150)
        # created rectangle box
        self.box = self.canvas.create_rectangle(0, 0, 50, 50, fill='red', tags="box")
        # placed at desired position
        self.canvas.move(self.box, 150, 20)
        # pack the canvas to ensure all drawings are shown properly
        self.canvas.pack()
        # start the initial freefall after 1 ms 
        self.canvas.after(1, self.initial_freefall)
        # bind moveBar() functions with bar rectangle which works on buttonclick and drag 
        self.canvas.tag_bind('bar' , '<B1-Motion>' , self.moveBar)
        # bind binder() to box which works on buttonclick on box
        self.canvas.tag_bind('box' , '<Button-1>' , self.binder)
        # bind freefall_buttonrelease() with canvas on button release 
        self.canvas.bind('<ButtonRelease-1>' , self.freefall_buttonrelease)
        # bind freefall() with canvas on <<collision>> , a custom event 
        self.canvas.bind('<<collision>>', self.freefall)
        # canvas.bind('<Motion>' , print_pos)
        

        # stop_box denotes the state of the box is stopped or not 
        self.stop_box = False
        # ffv denotes wheather the box is freefalling or not 
        self.ffv = 0
        # ii is used to track initial freefall
        self.ii = 0
        # fall is used to track box is falling or not 
        self.fall = False
        # bc , lc , rc denotes bottom .  left and right  collision 
        self.bc , self.lc , self.rc  = False, False , False
        
        # mainloop for window 
        self.window.mainloop()
    
    # function for binding mouse movement with box
    def binder(self, event):
        print("binder")
        # bind box with moveBox function 
        self.canvas.tag_bind('box' , '<B1-Motion>' , self.moveBox)

    # function for finding top collision 
    def top_collision(self):
        # find box position
        box_pos = self.canvas.coords(self.box)
        # find bar position 
        bar_pos = self.canvas.coords(self.bar)
        # find the top collision is happened or not 
        if  box_pos[3] == bar_pos[1] and (bar_pos[0] <= box_pos[0] <= box_pos[2] <= bar_pos[2] or  bar_pos[0] <= box_pos[0] <= bar_pos[2] or bar_pos[0] <= box_pos[2] <= bar_pos[2]) :
            # if top collision happened , stop the box 
            print('top collision')
            self.stop_box  = True
            self.canvas.coords(self.box , box_pos)

    # function responsible for box movement in canvas 
    def moveBox(self, event):
        print('box')
        # change ii to 1 when buttonclick on box happened , it ends the initial freefall 
        self.ii = 1
        # stop_box is set to false initially at every drag operation on box 
        self.stop_box = False
        # know the box and bar position
        box_pos = self.canvas.coords(self.box)
        bar_pos = self.canvas.coords(self.bar)
        
        # if mouse position is in the canvas and it doesnot overlaps the bar , move the bar accordingly
        if 0 <= event.x <= 250 and 0 <= event.y <= 200 and (event.y< bar_pos[1] - 50 or event.y> bar_pos[3] or (( bar_pos[1] - 50 < event.y < bar_pos[3]) and (event.x>bar_pos[2])  or (( bar_pos[1] - 50 < event.y < bar_pos[3]) and event.x+49<bar_pos[0]))): 
            event.widget.coords(self.box , event.x , event.y , event.x +50 , event.y +50 )
        # find the right collision 
        if event.x == bar_pos[2] and (event.y <= bar_pos[1] <= bar_pos[3] <= box_pos[3] or  bar_pos[1] <= event.y <= bar_pos[3] or bar_pos[1] <= box_pos[3] <= bar_pos[3]):
            print('right side collision')
            # set right collision rc as True 
            self.rc = True
            # generate collision event only if the box is already not falling 
            if not self.fall:
                self.canvas.event_generate("<<collision>>")
            # if no collision , increment ffv 
            else:
                self.ffv += 1
        
        elif bar_pos[0] == box_pos[2] and (box_pos[1] <= bar_pos[1] <= bar_pos[3] <= box_pos[3] or  bar_pos[1] <= box_pos[1] <= bar_pos[3] or bar_pos[1] <= box_pos[3] <= bar_pos[3]) :
            print('left side collision')
            # set left collision lc as True 
            self.lc = True
            # generate collision event only if the box is already not falling 
            if not self.fall:
                self.canvas.event_generate("<<collision>>")
            # if no collision , increment ffv 
            else:
                self.ffv += 1
        
        elif bar_pos[1] <= event.y <= bar_pos[3] and (bar_pos[0] <= box_pos[0] <= box_pos[2] <= bar_pos[2] or  bar_pos[0] <= box_pos[0] <= bar_pos[2] or bar_pos[0] <= box_pos[2] <= bar_pos[2]) :
            print('bottom collision')
            # self.canvas.tag_unbind(self.box , '<B1-Motion>')
            # generate collision event only if the box is already not falling 
            if not self.fall:
                self.canvas.event_generate("<<collision>>")
            # set bottom collision bc as True 
            self.bc = True
        return

    # function responsible for moving bar in canvas                            
    def moveBar(self, event):
        print('bar')
        # know the box and bar position
        box_pos = self.canvas.coords(self.box)
        bar_pos = self.canvas.coords(self.bar)
        # bar movement possible only within window
        if 0 <= event.x <= 200 and 0 <= event.y <= 250 :#and ( ((box_pos[1] < event.y < box_pos[3]) and (event.x+100 < box_pos[0])) or ((box_pos[1] <event.y <box_pos[3]) and (event.x > box_pos[2]))): 
            
            # if bar do not collide with box , place the bar at approproate location 
            event.widget.coords(self.bar , event.x , 150 , event.x + 100 , 162 )
            #if the bar stopped the box previously and now it is moved to different location , freefall the box by generating collision event 
            if bar_pos[1] == box_pos[3] and (bar_pos[2] < box_pos[0] or bar_pos[0] > box_pos[2]):
                # set stop_box  to false to ensure box is not in stop state 
                self.stop_box = False
                # generate collision event to freefall the box
                self.canvas.event_generate("<<collision>>")

    # function responsible for initial free fall of box 
    def initial_freefall(self):
        print('initial freefall')
        # set ii to 0 , ii denotes the initial freefall , it is used to check when the initial freefall breaks
        self.ii = 0
        # find box position 
        pos = self.canvas.coords(self.box)
        print(pos)
        # while box doesnot touches maximum y boundary fall the box
        i = 1
        while pos[3]+i != 253 : 
            # if top collision happens, stop the box above bar and break the loop
            self.top_collision()
            # if ii increments , denotes initial freefall ended by mouseclick on box
            if self.ii > 0 or self.stop_box:
                break
            # change box posiition by incrementing its y value only
            self.canvas.coords( self.box, pos[0] , pos[1]+i , pos[2] , pos[3]+i )
            i += 1
            # sleep time for a smooth freefall
            sleep(0.01)
            # update changes in window
            self.window.update()
            

    # function responsible for freefall on collision 
    def freefall(self, event):
        print('freefall')
        # set ffv to 1 
        self.ffv = 1
        # set fall to true , fall= true denotes the box is in falling state 
        self.fall = True
        # find position of box 
        pos = self.canvas.coords(self.box)
        print(pos)
        # while box doesnot touches maximum y boundary fall the box
        i = 1
        while pos[3]+i != 253 : 
            # change box posiition by incrementing its y value only
            self.canvas.coords( self.box, pos[0] , pos[1]+i , pos[2] , pos[3]+i )
            i += 1
            # sleep time for a smooth freefall
            sleep(0.001)
            # update changes in window
            self.window.update()
            # break the loop if ffv incremented of box stopped
            if self.ffv > 1 or self.stop_box:
                # set fall to false , as the box stopped 
                self.fall = False
                break
        # set fall to false , as the box stopped 
        self.fall = False

    # function responsible for freefall on buttonrelease event 
    def freefall_buttonrelease(self,event):
        print('freefall button release')
        # only if the box is not already on falling state freefall on button release 
        if self.fall == False: 
            # set ffv to 1
            self.ffv = 1
            # find position of box 
            pos = self.canvas.coords(self.box)
            print(pos)
            # while box doesnot touches maximum y boundary fall the box
            i = 1
            while pos[3]+i != 253 : 
                # if top collision happens, stop the box above bar and break the loop
                self.top_collision()
                # break the loop if ffv incremented of box stopped
                if self.ffv > 1 or self.stop_box:
                    break
                # change box posiition by incrementing its y value only
                self.canvas.coords( self.box, pos[0] , pos[1]+i , pos[2] , pos[3]+i )
                i += 1
                # sleep time for a smooth freefall
                sleep(0.01)
                # update changes in window
                self.window.update()

#object creation of BarSquareGame Class            
bs = BarSquareGame()
