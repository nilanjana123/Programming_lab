import json
import socket , math  , time, threading

# create client socket and connect to server 
c = socket.socket()
c.connect(('localhost', 8888))

# 'arr' list stores the threads 
arr=[]  
# 'flag1arr' is a list of all flags 
flag1arr = []
flag1arr.append(False)
# 'namearr' is a list of all thraed
namearr = []
# initialize 'lock' variable
lock = threading.Lock()
start_time = math.floor(time.perf_counter())                  

# 'sends' is the target of threads which exchanges data with server
def sends(name):
    str_send = 'Hello from '+ format(name)
    send_tuple = (str_send,name)
    send_json = json.dumps(send_tuple)
    
    # send data  to server 
    c.send(bytes(send_json,'utf-8'))
    
    # print messages 
    current_time = math.floor(time.perf_counter()) - start_time
    print('Time ' +format(current_time)+'s : '+ name + ' sent message to server' + '\n',end='')
    print('Msg sent by '+ name +': '+str_send+ '\n',end='')
    index = namearr.index(name)
    flag1arr[index+1]= False
    
    # busy wait till receives wakeup message for current thread 
    while not flag1arr[index+1]:
        pass  

    # As busy wait completes ,  receive message from server 
    # receive message when flag1arr[index] and flag1arr[0] both are True
    if flag1arr[index+1] and flag1arr[0]:
        # Acquire lock
        lock.acquire()
        # receive message 
        str_recv = c.recv(1024).decode()
        # prints messages
        current_time = math.floor(time.perf_counter()) - start_time
        print('Time ' +format(current_time)+'s : '+ name + ' received message from server' + '\n',end='')
        print('Msg received by '+ name +': '+str_recv+ '\n',end='')
        
        # set appropriate flag values to False
        flag1arr[0] = False
        flag1arr[index+1] = False
        # release lock
        lock.release()

# checker receives message from server and wakesup appropriate thread by setting corresponding flag value to True 
def checker():
    while True :
        # if flag1arr[0] is not True , activate thread by setting flag value of that thread from flag1arr[]
        if not flag1arr[0] :
            # 'activate'  represents the name of the thread to be activated for consuming server message 
            activate = c.recv(1024).decode()
            
            # break when activate receives blank string
            if activate == '':
                break
            
            # find index 
            index = namearr.index(activate)
            # set flags 
            flag1arr[index+1] = True
            flag1arr[0] = True
            # send ready signal when client thread is ready 
            c.send(bytes('ready' ,'utf-8'))
            
# create 10 threads and append them in arr list , flag1arr , namearr lists contains flag value and name of corresposnding thread 
for i in range(10):
    name = 'Thread ' + format(i+1)
    t = threading.Thread(target= sends , args=[name ])
    arr.append(t)
    flag1arr.append(True)
    namearr.append(name)

# create checker thread to check for which thread to activate to consume server reply 
checkr  = threading.Thread(target= checker , args=[])
# start checkr()
checkr.start()

# start threads 
for t in arr:
    t.start()
