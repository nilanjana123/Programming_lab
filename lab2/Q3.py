
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


# Definition of Triangle class which inherits Polygon class 
class Triangle(Polygon):

    # __init__ method or constructor to do initialization of class attributes                                                                                                       
    def __init__(self,a,b,c):  

        # try except block for Exception Handling                                                                    
        try: 

            # All the 3 sides of a triangle should have positive values , otherwise raise an exception . No triangle can have negetive side-length                                                           
            if(a <= 0 or b <= 0 or c <= 0):                             
                raise Exception("Triangle should have postive side-lengths")
            
            # In a Triangle, sum of any two side-lengths is greater than the side-length of 3rd one 
            # If the property holds a triangle object will be created . 
            elif((a < b+c) and  (b < a+c) and (c < b+a)):

                # Triangle class have only numSides and area attribute inherited from its parent Polygon 
                # Invoking the __init__() of parent class Polygon using super() 
                super(Triangle,self).__init__(3,(((a+b+c)/2)*(((a+b+c)/2)-a)*(((a+b+c)/2)-b)*(((a+b+c)/2)-c))**(1/2))
            
            # If Triangle properties are not satisfied , raise exception 
            else:
                raise Exception("Side-lengths do not form a triangle")
        
        # except block catches the exception occured in try block
        except Exception as e:
            # print the type of exception and message to user                                           
            print(format(type(e)) +"\n"+ format(e))                            

    # __str__() function is used to convert an object to string , so that the object can be printed as a string 
    def __str__(self):
        return "Triangle with area "+ format(self.area)



# TestCase 1
print("\nTestcase 1 : \n")
print("Input : \nt = Triangle(1, -2, 3)")
print("\nOutput : ")
t = Triangle(1, -2, 3)
print('_' * 60)

# TestCase 2
print("\nTestcase 2 : \n")
print("Input : ")
print("t = Triangle(3, 2, 1)")
print("\nOutput : ")
t = Triangle(3, 2, 1)
print('_' * 60)

# TestCase 3
print("\nTestcase 3 : \n")
print("Input : ")
print("t = Triangle(3, 4, 5)\nprint(t)")
print("\nOutput : ")
t = Triangle(3, 4, 5)
print(t)
print('_' * 60)


