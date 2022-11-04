from matplotlib import animation
import numpy as np
from numpy.lib.histograms import histogram
import scipy.stats as sc
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# let, n and k as number of randon variables of bernaulli's equation and size of random sample respectively
n=500
k=1000

# initialize data 
data=None  

# initialize the figure and axis subplot
fig, ax=plt.subplots(figsize=(10,10))

# Bernoulli's Equation with probability 0.5
distribution=sc.bernoulli(0.5)

# function to produce animation for histogram 
def animate(frames):

    # Clear the plot
    plt.cla()

    # increasing the n for each animation function call done by FuncAnimation
    n=500*(frames+1)

    # data is taken as random variables of bernoulli's distribution with k rows and each rows containing n random variables
    data = distribution.rvs((k,n))

    # u, s are mean and standard daviation of data sample 
    u, s = data.mean(), data.std()

    # sample_means is the mean of each axis of data 
    sample_means = data.mean(axis=1)

    # Y is the final numpy array to plot in histogram
    Y =(sample_means-u) / s * np.sqrt(n)

    # set the Linespace for histogram plot
    xmin, xmax = -10*s, 10*s
    X=np.linspace(xmin, xmax, 100)
    # set the limit of plot
    plt.xlim(xmin,xmax)

    # take a normal distribution and fit it with Y 
    mu, std = sc.norm.fit(Y)

    # Plot a dashed standard normal curve in orange color with line width 3
    ax.plot(X,sc.norm.pdf(X,mu ,std), '--',color = 'orange', lw=3, label="Standard Normal Distribution")

    # add legend of normal curve
    plt.legend(loc='upper right')

    # create histogram with Y data with line width 1 and color green 
    h, bins,rects = ax.hist(Y,X,lw=1, ec='yellow',fc="green" , alpha = 0.7)
    
    # set the height of each rectangles of the histogram as a percentage value to fit in the normal curve 
    for r in rects:
        r.set_height(r.get_height()/100)
    
    # update title of histogram plot with each iteration of animate function
    title = "Histogram of " + r" $\frac{(\bar{X_{n}}-\mu) }{\frac{ \sigma}{\sqrt{n}}}}$" + " for n = " + format(n) + " where , " + r"$\bar{X_{n}}$" + " = " + r"$\frac{1}{n}$" + r"$\sum_{i=0}^{n} {X_i}$"
    ax.set_title(title)

    # fix the top value of the plot 
    plt.ylim(top=0.6)
    return ax

# Creates animation of histogram ani is the animation output
ani  = FuncAnimation(fig, animate,frames=200, interval=250, repeat=False)

# save the histogram in gif format in CLT.gif file
#ani.save('CLT.gif',  writer='imagemagick', fps=30)

# show the plot 
plt.show()

