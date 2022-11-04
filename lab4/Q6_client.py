import socket , math , random , json

# create client socket 
c = socket.socket()
print('Socket created...')

# Connect client socket with server 
c.connect(('localhost', 8888))
print('Socket connected...')

# A is an array of 10 (i.e lenA) tuples.where, A = [(a1, b1), . . . ,(a10, b10)].
A = []
lenA = 10

# form A as A = [(a1, b1), . . . ,(a10, b10)]
for _ in range(lenA):
    # value of 'a' and 'b' ranges from 1 to 100 (an assumption)
    a = math.floor(random.uniform(1,100))
    b = math.floor(random.uniform(1,100))
    # append (a,b) tuple in A list
    A.append((a,b))

# print A in client side 
print( 'A created : ', A)
# dump A as a json object to send to client
json_data =  json.dumps(A)

# send A to client as json string 
c.send(bytes(json_data,'utf-8'))
print('A sent to server...')

# receive reply from server 
rcv = c.recv(1024).decode()
print('B received...')
# evaluate received recv object as a list object 
recv_list= list(eval(rcv))
# recv_list contains each element as list format , make B as a list of tuple format 
# create the B list from recv , as  B = [(a, b),(amax, bmax),(amin, bmin)]
B = []

# make B in tuple format from recv_list 
for item in recv_list:
    B.append((item[0],item[1]))

# print B in client side 
print('B : ', B)
