import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as tck
import matplotlib.animation as animation

# definition of class Sines
class Sines:
    #definition of init constructor
    def __init__(self):
        # ys stores list of tuples of (rad, y) where rad is radian value for a sine curve y
        self.ys =[]
        # rads will store all the radian values of the plots present 
        self.rads = []
        
        #Taking range of X-axis
        self.x = np.linspace( -1000*np.pi ,1000*np.pi,100000)
       
        #Taking the sub plots
        self.f, self.ax=plt.subplots(figsize=(10,10))
        
        #Plotting the values of X axis
        self.ax.xaxis.set_major_formatter(tck.FormatStrFormatter('%g $\pi$'))
        self.ax.xaxis.set_major_locator(tck.MultipleLocator(base=0.25))
        
        #Setting X and Y Co-ordinate limits in initial frame
        plt.xlim(0,2)
        plt.ylim(-2.0 , +2.0)
        
        #Adding grids
        plt.grid(True, which= 'both' ,linestyle='--' )
        
        #Adding Maximum,Minimum,0 values of Sine curve as a Straight line
        plt.axhline(y=1, color='g', linestyle='-')
        plt.axhline(y= -1, color='r', linestyle='-')
        plt.axhline(y=0, color='k', linestyle='-')
        self.max_text=self.ax.text(1,1.1,'Maximum value')
        self.min_text=self.ax.text(0.25,-1.15,'Minimum value')    
        
        #Giving Title of the curve  
        plt.title("Interactive sinusoidal functions")
        
        #Labelling the axes
        plt.xlabel("θ")
        plt.ylabel("sin(θ + ɸ)")
        
        # variables used to make the plot interactive
        self.paused = False             # indicates the plot is paused or not
        self.right = False              # indicates the plot is moving towards right or not
        self.left = False               # indicates the plot is moving towards right or not
    
    # definition of interact function
    def interact(self):

        # mpl_connect method is used for event hangling and for keypress event it will call interaction() method 
        self.cid = self.f.canvas.mpl_connect('key_press_event' , self.interaction)
        
        # FuncAnimation is used for creating animation which will call animate() function every 5ms and continue for 10000 frames
        self.ani = animation.FuncAnimation(self.f, self.animate, frames=10000 ,interval = 5)
        
        # call the show() method for showing output
        self.show()
    
    # definition of interaction() method which is used to capture the keypress events
    def interaction(self , event):
        
        # if spacebar is pressed toggle the paused variable and pause or resume the plot
        if event.key == ' ':
            print('spacebar')
            if self.paused:
                self.ani.resume()
                self.paused=False           # when plot is resumed, paused is False
            else:
                self.ani.pause()
                self.paused=True            # when plot is paused, paused is False

        # if 'a' key is pressed , set right value as true so that animate() will move the plot towards right                          
        if event.key == 'a':
            print("right")
            if self.paused :                # if the plot is paused then resume it
                self.ani.resume()
            self.left = False               # set left to false
            self.right = True               # set right to true
            self.paused = False             # set paused to false
        
        # if 'd' key is pressed , set left value as true so that animate() will move the plot towards left                          
        if event.key == 'd':
            print("left")
            if self.paused :                # if the plot is paused then resume it
                self.ani.resume()
            self.right = False              # set right to false
            self.left = True                # set left to true
            self.paused = False             # set paused to false
        
        # if 'r' key is pressed , reset left, right , paused to false
        if event.key == 'r':
            print("Reset")
            self.right = False
            self.left = False
            self.paused = False

    # Definition of animate() method which is called by FuncAnimation, it takes frame number as 'frame' parameter
    def animate(self,frame):
        
        # v variable is used to set the x-limit and x-ticks to move the plot horizontally
        # if left is true , decrement v
        if self.left == True:
            self.v -= 0.01

        # else if right is true , increment v        
        elif self.right == True:
            self.v += 0.01

        # else if right and left both are false , set v to 0
        elif self.right==False and self.left==False:
            self.v=0

        # set x-limit , x-ticks , position of max_text,min_text variable     
        self.ax.set_xlim(left= 0 + self.v , right=self.v+2)
        self.ax.set_xticks([round(0 + self.v , 2) ,0.25 + self.v,0.50 + self.v,0.75 + self.v,1.00 + self.v,1.25 + self.v,1.50 + self.v,1.75 + self.v,2.00 + self.v])
        self.max_text.set_position((1+self.v, 1.1))
        self.min_text.set_position((0.25 + self.v, -1.15))                                 
        
        return self.v 

    #Defining the addSine Function to add phase angle in degree    
    def addSine(self, deg): 
        rad = deg/180 * np.pi            #Converting degree to radian
        self.rads.append(rad)            #Appending to radian vaue
        y = np.sin(rad + self.x)         #Generating the Sine curve in y value
        self.ys.append((rad,y))          #Appending all the curves
        return self
    
    # definition of show method to  show the plot output
    def show(self):
        # loop through the ys list and plot each plot
        i=0
        while i < len(self.ys):
            # plot
            self.ax.plot(self.x/np.pi,self.ys[i][1] , label = 'ɸ = '+ format(int(np.rad2deg(self.rads[i])))+ '°')
            # adding legends for each plot
            plt.legend(loc='upper right', fontsize=12, ncol=3)
            i+=1
        
        # show the plot 
        plt.show()

        return plt

# Testcase 1 : 

print("\nTestcase 1 : \n")
print("Input : \ns = Sines()\ns.addSine(0)\ns.addSine(45)\ns.addSine(90)\ns.interact()")
print("\nOutput : ")
s = Sines()
s.addSine(0)
s.addSine(45)
s.addSine(90)
s.interact()
