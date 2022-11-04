import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as tck


#Class Sines has been added
class Sines:
    # init or constructor definition 
    def __init__(self):
        # ys stores list of tuples of (rad, y) where rad is radian value for a sine curve y
        self.ys =[]
        # rads will store all the radian values of the plots present 
        self.rads = []
        
        #Taking range of X-axis
        self.x = np.linspace( -1000*np.pi ,1000*np.pi,100000)
       

    #Defining the addSine Function to add phase angle in degree    
    def addSine(self, deg): 
        rad = deg/180 * np.pi           #Converting degree to radian
        self.rads.append(rad)           #Appending to radian vaue
        y = np.sin(rad + self.x)        #Generating the Sine curve in y value
        self.ys.append((rad,y))         #Appending all the curves
        return self

    #Defining the shiftRight Function to shift all the curves by an angle in degree 
    def shiftRight(self, deg):
        rad = deg/180* np.pi            #degree to radian conversion
        i=0
        #Modifying the plots and degree previously added
        while i < len(self.ys):
            # for shifting right , the new degree is lesser than previous one
            d = self.ys[i][0] - np.deg2rad(deg)
            z = np.sin( self.x + d )
            self.ys[i] = (d,z)
            i+=1
    
    #Defining the shiftLeft Function to shift all the curves by an angle in degree , subtract deg from previous plot's degree
    def shiftLeft(self, deg):
        rad = deg/180* np.pi #degree to radian conversion
        i=0
        #Modifying the plots and degree previously added
        while i < len(self.ys):
            # for shifting left , the new degree is greater than previous one . Add deg with previous plot's degree 
            d = self.ys[i][0] + np.deg2rad(deg)
            z = np.sin( self.x + d )
            self.ys[i] = (d,z)
            i+=1

    #Defining the show Function to display/plot all the curves and labels
    def show(self):
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
        plt.text(1,1.1,'Maximum value')
        plt.text(0.25,-1.15,'Minimum value') 
        #Giving Title of the curve  
        plt.title("Interactive sinusoidal functions")
        #Labelling the axes
        plt.xlabel("θ")
        plt.ylabel("sin(θ + ɸ)")
        
        # loop through the ys list and plot each plot
        i=0
        while i < len(self.ys):
            # plot
            self.ax.plot(self.x/np.pi,self.ys[i][1] , label = 'ɸ = '+ format(int(np.rad2deg(self.rads[i])))+ '°')
            # adding legends for each plot
            plt.legend(loc='upper right', fontsize=12, ncol=3)
            i+=1
        plt.show()
        

# TestCase 1
print("\nTestcase 1 : \n")
print("Input : \ns = Sines() \ns.addSine(0) \ns.addSine(90)")
print("\nOutput : ")
s = Sines()
s.addSine(0)
s.addSine(90)

# TestCase 2
print("\nTestcase 2 : \n")
print("Input : \ns = Sines() \ns.addSine(0) \ns.addSine(90) \ns.show()")
print("\nOutput : ")
s = Sines()
s.addSine(0)
s.addSine(90)
s.show()

# TestCase 3
print("\nTestcase 3 : \n")
print("Input : \ns = Sines() \ns.addSine(0) \ns.addSine(90) \ns.show() \ns.shiftRight(45)")
print("\nOutput : ")
s = Sines()
s.addSine(0)
s.addSine(90)
s.shiftRight(45)
s.show()

# TestCase 4
print("\nTestcase 4 : \n")
print("Input : \ns = Sines() \ns.addSine(0) \ns.addSine(90) \ns.show() \ns.shiftRight(45)\ns.shiftLeft(45)")
print("\nOutput : ")
s = Sines()
s.addSine(0)
s.addSine(90)
s.shiftRight(45)
s.shiftLeft(45)
s.show()
