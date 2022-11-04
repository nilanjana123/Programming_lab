# Definition of Polygon class
class Polygon: 

    # __init__ method or constructor to do initialization of class attributes                                                         
    def __init__( self , numSides , area ): 

        # try except block for Exception Handling                           
        try:

            # A new polygon object will be created only if it has more than 2 sides and positive area                                                             
            if( numSides > 2 and area > 0 ):                            
                self.numSides = numSides                                # Initialize class attribute numSides 
                self.area = area                                        # Initialize class attribute area
            
            # If numSides < 3 an exception will be raised as a polygon should have atleast 3 sides
            if( numSides < 3 and area > 0 ):                            
                raise Exception("Number of sides should be atleast 3")
            
            # If area < 0 an exception will be raised as a polygon should have atleast 3 sides
            elif( numSides > 2 and area < 0 ):                          
                raise Exception("Polygon should have postive area")
        
        # Catches the exceptions occured in try block
        except Exception as e:
            # print the type of exception and message to user                                           
            print(format(type(e)) +"\n"+ format(e))                     

    
    # __str__() function is used to convert an object to string , so that the object can be printed as a string 
    def __str__(self):                                                  
            return "Polygon with "+ format(self.numSides) + " sides and area " + format(self.area)      

# TestCase 1
print("\nTestcase 1 : \n")
print("Input : \np = Polygon(1, 23)")
print("\nOutput : ")
p = Polygon(1, 23)
print('_' * 60)

# TestCase 2
print("\nTestcase 2 : \n")
print("Input : ")
print("p = Polygon(10, -23)")
print("\nOutput : ")
p = Polygon(10, -23)
print('_' * 60)

# TestCase 3
print("\nTestcase 3 : \n")
print("Input : ")
print("p = Polygon(13, 123)\nprint(p)")
print("\nOutput : ")
p = Polygon(13, 123)
print(p)
print('_' * 60)

