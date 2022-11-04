import socket , math , random , time, threading

# create server socket 
s = socket.socket()
# bind server socket with localhost and port 8888
s.bind(('localhost', 8888))
# listen for connections
s.listen(5)

# accept connection. c,addr represents the cient socket and address of client 
c, addr = s.accept()

# que1 represents the list for received messages as tuple of '(message, threadname)' form
que1 = []
# que1 is rearranged in que in the order of sleep complition 
que = []

# using lock to avoid race conditions 
lock1 = threading.Lock()
lock2 = threading.Lock()
# represents all messages from client threads are received or not 
que1Full = False

# loop for receiving all messages sent from client threads
i=0
while i<10 : 
    # decode received message 
    rcv = c.recv(1024).decode()
    # evaluate message as list 
    rcv1 = list(eval(rcv))
    # store message as str and threadname ad th 
    str = rcv1[0]
    th = rcv1[1]
    # append the (str , th) tuple to que list 
    que1.append((str , th ))
    print(str , ' received from client thread :', th)
    i+=1

    # when all messages received , set que1Full to true
    if i == 10 :
        que1Full = True

# sleepingTh represents behaviour of each thread at server side .
def sleepingTh():
    # start sleeping after all messages from server is received .
    if que1Full:
        # sleep for random time ,  uniformly choosen from {1,2,3,4,5} (in sec) list 
        time.sleep(math.floor(random.uniform(1,5)))
        # acquire lock
        lock1.acquire()
        
        # pop from que1 and append to que to ensure que1 is rearranged in que in the order of sleep complition 
        q = que1.pop()
        que.append(q)

        # release lock 
        lock1.release()

# create threads for councurrent sleeping 
arr =[]
for i in range(10):
    # create thread with target to sleepingTh
    t = threading.Thread(target= sleepingTh )
    # append threads in arr list
    arr.append(t)

# start all threads in arr 
for t in arr:
    t.start()

# this portion of code checks for que list , if it contains any element , that represents that for that element , sleep is completed , hence send it back to client.
i=0
# try to send message till all the 10 messages receives from client is not sent back.
while i<10 or len(que)>0:
    # if que has element , sent back the message to client 
    if len(que) > 0:
        # the message which will be sent to client , remove that from que 
        q = que.pop()
        # an intentional delay is given to avoid out of order  message delivery
        time.sleep(1)
        print('Sending to client :', q[1])
        # send a check the message to client so that client enables the proper thread to accept the message which was sent by the client earlier
        c.send(bytes(q[1],'utf-8'))
        # send message to client to be received by appropriate thread when the client is ready
        if c.recv(1024).decode('utf-8') == 'ready':
            c.send(bytes(q[0],'utf-8'))
            print('Sent message :', q[0] , 'to ',q[1])
        i+=1

# close the connection 
c.close()
