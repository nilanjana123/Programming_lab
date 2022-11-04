import matplotlib as mt
import matplotlib.pyplot as plt
from collections import Counter

# Definition of class PieChart
class PieChart:
    # Constructor of class Piechart which takes a dictionary arguament 
    def __init__(self , dict):

        # try except block used for exception ahndling 
        try:
            for key in dict:                                #for every key:value pair of dictionary checks 
                if type(key) != str:                        # if type of key is of type string or not . 
                    raise Exception ('Label should be string')                       #if type of key is not string raise exception
                elif type(dict[key]) != int or dict[key] < 0:                        # if value for any key is not of type <int> or not positive 
                    raise Exception('Value should be a postive numeric')             # Raise exception
            self.dict = dict                                # if no exception , intitialize dict and create object of type pieChart
        except Exception as e:                              # catches the exceptions occured in try block 
            print(format(type(e)) +"\n"+ format(e))         # prints the type of exception and message to user
    
    # Definition of show function which plots PieChart object
    def show(self):
        keys=[]                                             # Empty  list to store keys 
        vals=[]                                             # Empty List to store the values    
        
        #for every key of self.dict , append the key to keys list and the values respective to that key in vals list
        for key in self.dict:                                
            keys.append(key)
            vals.append(self.dict[key])

        # Plot a figure with figsize with width 10 unit and height 7 unit 
        fig = plt.figure(figsize = (3,3))
        # Plot the pie chart 
        plt.pie( vals , labels= keys , autopct= '%1.1f%%')
        # show the piechart
        plt.show()

    # Definition  to overload + operator , which enables adding a tuple or Piechart Object with self 
    def __add__(self, other):

        # If a tuple is being added to PieChart ,
        if type(other) == tuple:
            # flag is used to check if the key of the tuple matches with any other keys of PieChart object
            flag = 0
            for key in self.dict:                               #for every key in self.dict()
                if(key == other[0]):                            # if key mathes with first element of tuple
                    self.dict[key]= other[1] + self.dict[key]   # increment the value of that element by 2nd element / argument of tuple 
                    flag = 1                                    # set flag as 1 to indicate that the tuple matched 
            if flag == 0 :                                      # if tuple not matched
                self.dict[other[0]]= other[1]                   # add that tuple to dict dictionary
        
        # If a tuple is being added to PieChart ,
        if type(other) == PieChart:
            # used counter to add two dictionary
            op = Counter(self.dict) + Counter(other.dict)
            # set the dict attribute of PieChart object to the output of added dictionarys
            self.dict = dict(op)
        # + operator overloading will return a PieChart object or self 
        return self

    # Definition  to overload - operator , which enables Subtracting an item with specified key from self 
    def __sub__(self, other):
        self.dict.pop(other, "")                                # used pop() to delete data from self
        return self                                             # retuning self to ensure the changes made are captured properly

# TestCase 1
print("\nTestcase 1 : \n")
print("Input : ")
print("p = PieChart({1, 23})")
print("\nOutput : ")
p = PieChart({1, 23})
print('_' * 60)

# TestCase 2
print("\nTestcase 2 : \n")
print("Input : ")
print("p = PieChart({'Frog': '30'})")
print("\nOutput : ")
p = PieChart({'Frog': '30'})
print('_' * 60)

# TestCase 3
print("\nTestcase  : \n")
print("Input : ")
print("p = PieChart({'Frog': -10})")
print("\nOutput : ")
p = PieChart({'Frog': -10})
print('_' * 60)

# TestCase 4
print("\nTestcase 4 : \n")
print("Input : ")
print("p = PieChart({'Frogs': 10, 'Dog': 25})\np.show()")
print("\nOutput : ")
p = PieChart({'Frogs': 10, 'Dog': 25})
p.show()
print('_' * 60)

# TestCase 5
print("\nTestcase 5 : \n")
print("Input : ")
print("p = PieChart({'Frogs': 10, 'Dog': 25})\np = p + ('Cat', 25)\np.show()")
print("\nOutput : ")
p = PieChart({'Frogs': 10, 'Dog': 25})
p = p + ('Cat', 25)
p.show()
print('_' * 60)

# TestCase 6
print("\nTestcase 6 : \n")
print("Input : ")
print("p = PieChart({'Frogs': 10, 'Dog': 25})\np = p + ('Dog', 25)\np.show()")
print("\nOutput : ")
p = PieChart({'Frogs': 10, 'Dog': 25})
p = p + ('Dog', 25)
p.show()
print('_' * 60)

# TestCase 7
print("\nTestcase 7 : \n")
print("Input : ")
print("p = PieChart({'Frogs': 10, 'Dog': 25})\np = p + PieChart({'Frogs': 20, 'Cat': 10})\np.show()")
print("\nOutput : ")
p = PieChart({'Frogs': 10, 'Dog': 20})
p = p + PieChart({'Frogs': 20, 'Cat': 10})
p.show()
print('_' * 60)

# TestCase 8
print("\nTestcase 8 : \n")
print("Input : ")
print("p = PieChart({'Frogs': 10, 'Dog': 20, 'Cat':30})\np = p - 'Frogs'\np = p - 'Lions'\np.show()")
print("\nOutput : ")
p = PieChart({'Frogs': 10, 'Dog': 20, 'Cat':30})
p = p - 'Frogs'
p = p - 'Lions'
p.show()