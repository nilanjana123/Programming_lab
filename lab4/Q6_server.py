import socket , json

# creating a server socket 
s = socket.socket()
print('socket created')

# bind the server socket with IP as localhost , and port number as 8888
s.bind(('localhost', 8888))

# Server socket is listening for 5 client . here 5 is a random number however after the work done , socket will be closed manually
s.listen(1)
print('waiting for connections')

# socket accepts the connect request from client , c, addr represents the client socket and address 
c,addr = s.accept()
print('connected with ',addr)

# receive message from client .
rcv = c.recv(1024).decode('utf-8')
# print received message 
print(rcv)

# evaluate received message as list object 
recv_list= list(eval(rcv))

# Calculate a_bar , b_bar as average values of a's and b's , a_max ,a_min , b_max, b_min as the maximum and minimum values of a's and b'sin recv_list
# initialize a_bar ,b_bar , a_max, a_min ,b_max , b_min
a_bar = 0
b_bar = 0
a_max = recv_list[0][0]
a_min = recv_list[0][0]
b_max = recv_list[0][1]
b_min = recv_list[0][1]

# loop through the recv_list to calculate a_bar ,b_bar , a_max, a_min ,b_max , b_min
for item in recv_list:
    # sum all a's to a_bar and sum all b's to b_bar 
    a_bar += item[0]
    b_bar += item[1]

    # if any greater value of a is found , update a_max value to greater one 
    if item[0] > a_max:
        a_max =  item[0]
    # if any lesser value of a is found , update a_min value to lesser one 
    if item[0] < a_min:
        a_min =  item[0]
    
    # if any greater value of b is found , update b_max value to greater one 
    if item[1] > b_max:
        b_max =  item[1]
    # if any lesser value of b is found , update b_min value to lesser one 
    if item[1] < b_min:
        b_min =  item[1]

# divide a_bar and b_bar by 10 to get the average value of a's and b's
a_bar = a_bar / 10
b_bar = b_bar / 10

# create B list as B = [(a, b),(amax, bmax),(amin, bmin)]
B = [(a_bar,b_bar), (a_max , b_max), (a_min , b_min)]
# dump B as a json object to send to client 
send_json = json.dumps(B)
# send B to client 
print('Sending B :' ,B)
c.send(bytes(send_json,'utf-8'))

# close the connection after B is sent to client to ensure proper connection termination 
c.close()
