
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


# Definition of Paper class 
class Paper:

    # __init__ method or constructor to do initialization of class attributes                                                         
    def __init__(self , area):

        # try except block for Exception Handling                           
        try:

            # If area is negetive , raise an exception 
            if(area < 0):
                raise Exception("Paper should have a positive area")
            
            # Only if area is greater than zero , initialize Paper object 
            else:
                self.area=area                              # Initializes class attribute 'area' represents empty area of the paper
                self.full_area=area                         # Initializes class attribute 'full_area' represents whole area of the paper 
                self.objList = []                           # Initializes class attribute 'objList' which is a python list and stores other objects added to the paper

        # Catches the exceptions occured in try block
        except Exception as e:
            # print the type of exception and message to user                                           
            print(format(type(e)) +"\n"+ format(e))                     

     # __str__() function is used to convert an object to string , so that the object can be printed as a string 
   
    # __str__() function is used to convert an object to string , so that the object can be printed as a string 
    def __str__(self):

        # A temporary variable str1 is created for object to string conversion of Paper object
        str1 = "Paper has free area " + format(self.area) +" out of " + format(self.full_area) + ", and contains: "
        
        # Iterate the objList[] which contains all the objects added with Paper and add them to str1 string  
        for i in self.objList : 

            # specify the classtype as Triangle when a polygon has 3 sides
            classType = "Triangle" if i.numSides == 3 else "Polygon"
            str1 += "\n" + classType + " with " + format(i.numSides) + " sides and area " + format(i.area) 
        
        # str1 is now the string representation of Paper class with all the objects it contains. 
        return str1

    # __add__() is used to overload '+' operator . This will allow us to add objects of Paper or triangle class with Paper class object 
    def __add__(self,other):

        # try except block for exception handling 
        try:

            # If Paper has enough area to fit an object, the object will be added to objList arrtibute of Paper class and area of Ppaer will reduce by the area of added object 
            if (self.area >= other.area):
                self.area -= other.area
                self.objList.append(other)
            
            # If Paper doesnot have enough space to fit an object , it will raise an exception
            else :
                raise Exception("Paper does not have sufficient free area to fit the polygon")
        
        # Catches the exceptions occured in try block
        except Exception as e:
            # print the type of exception and message to user                                           
            print(format(type(e)) +"\n"+ format(e))                     

        return self
    

    # merge() function will merge the polygons with same numSides and make a big Polygon with bigger area
    def merge(self):
        i=0  # loop variable initialization 
        
        # iterate objList[] : for each element present in objlist,   
        while i < len(self.objList):
            j = i + 1  # loop variable initialization
            while j < len(self.objList):

                #if any other obj in objList[] has the same numsides, increase the area of the object by the other objects area
                if(self.objList[i].numSides == self.objList[j].numSides): 
                    self.objList[i].area += self.objList[j].area
                    # delete the other object with same numSides
                    self.objList.remove(self.objList[j])
                # loop variable incrementation 
                j += 1
            # loop variable incrementation 
            i += 1        
        return self


    # erase() function will erase every object present in paper 
    def erase(self):

        # Clear the objList[] to delete all the polygon objects that was previously added to paper 
        self.objList.clear()

        # after clearing objList[] set area of Paper to its initial size or full area
        self.area = self.full_area

        return self
    
    
# TestCase 1
print("\nTestcase 1 : \n")
print("Input : \npap = Paper(-1))")
print("\nOutput : ")
pap = Paper(-1)
print('_' * 60)

# TestCase 2
print("\nTestcase 2 : \n")
print("Input : ")
print("pap = Paper(200)\np = Polygon(10, 100)\npap = pap + p\npap = pap + Polygon(5, 45)\nprint(type(pap).__name__)")
print("\nOutput : ")
pap = Paper(200)
p = Polygon(10, 100)
pap = pap + p
pap = pap + Polygon(5, 45)
print(type(pap).__name__)
print('_' * 60)

# TestCase 3
print("\nTestcase 3 : \n")
print("Input : ")
print("pap = Paper(200)\np1 = Polygon(10, 100)\np2 = Polygon(20, 150)\npap = (pap + p1) + p2")
print("\nOutput : ")
pap = Paper(200)
p1 = Polygon(10, 100)
p2 = Polygon(20, 150)
pap = (pap + p1) + p2
print('_' * 60)

# TestCase 4
print("\nTestcase 4 : \n")
print("Input : ")
print("pap = Paper(200)\npap = pap + Polygon(10, 100)\npap = pap + Polygon(20, 50)\npap = pap + Triangle(3, 4, 5)\nprint(pap)")
print("\nOutput : ")
pap = Paper(200)
pap = pap + Polygon(10, 100)
pap = pap + Polygon(20, 50)
pap = pap + Triangle(3, 4, 5)
print(pap)
print('_' * 60)

# TestCase 5
print("\nTestcase 5 : \n")
print("Input : ")
print("pap = Paper(200)\npap = pap + Polygon(3, 100)\nprint(pap)")
print("\nOutput : ")
pap = Paper(200)
pap = pap + Polygon(3, 100)
print(pap)
print('_' * 60)

# TestCase 6
print("\nTestcase 6 : \n")
print("Input : ")
print("pap = Paper(2000)\npap = pap + Polygon(10, 100)\npap = pap + Polygon(20, 50)\npap = pap + Polygon(10, 200)\npap = pap + Polygon(3,24)\npap = pap + Triangle(3, 4, 5)\nprint(pap)\npap.merge()\nprint(pap)\npap = pap + Polygon(10, 123)\nprint(pap)")
print("\nOutput : ")
pap = Paper(2000)
pap = pap + Polygon(10, 100)
pap = pap + Polygon(20, 50)
pap = pap + Polygon(10, 200)
pap = pap + Polygon(3,24)
pap = pap + Triangle(3, 4, 5)
print(pap)
pap.merge()
print(pap)
pap = pap + Polygon(10, 123)
print(pap)
print('_' * 60)

# TestCase 7
print("\nTestcase 7 : \n")
print("Input : ")
print("pap = Paper(200)\npap = pap + Polygon(10, 100)\npap = pap + Polygon(20, 50)\npap = pap + Triangle(3, 4, 5)\nprint(pap)\npap.erase()\nprint(pap)")
print("\nOutput : ")
pap = Paper(200)
pap = pap + Polygon(10, 100)
pap = pap + Polygon(20, 50)
pap = pap + Triangle(3, 4, 5)
print(pap)
pap.erase()
print(pap)
print('_' * 60)

