
import random , math, time
from threading import Barrier, Thread

# A barrier for 5 thraeds 
barrier = Barrier(5)
start_time = math.floor(time.perf_counter())                  

# person_in_mall is target of threads created to represent persons 
def person_in_mall(name, arrival, visit):
    # sleep for 'arrival' amount of time , which represents the arrival time of a person in mall 
    time.sleep(arrival)
    # print as the person reached the mall .
    current_time = math.floor(time.perf_counter()) - start_time              # Current time  
    print('Time '+format(current_time)+'s : '+name +' reached the mall\n',end='')
    # wait for other threads or person to enter mall . All persons enters the mall at the same time
    barrier.wait()
    # as the barrier breaks , all 5 persons enters the mall at the same time .
    current_time = math.floor(time.perf_counter()) - start_time              # Current time  
    print('Time '+format(current_time)+'s : '+name +' enters the mall\n',end='')
    # sleep for 'visit' amount of time  , which represents the visit time of a person in the mall 
    time.sleep(visit)
    # after visiting done, the person leaves the mall .
    current_time = math.floor(time.perf_counter()) - start_time              # Current time  
    print('Time '+format(current_time)+'s : '+name +' leaves the mall\n',end='')

# arr is the list of threads 
arr=[] 

# create 5 threads 
for i in range(5):
    # arrival represents the arrival time of the Person or thread 
    arrival = random.uniform(1,20)
    # visit represents the amount of time a person will visit in mall
    visit = random.uniform(1,10)
    # name represents the name of the person 
    name = "Person "+format(i+1)

    # create thread with target to person_in_mall and arguments name, arrival , visit
    t = Thread(target= person_in_mall , args=[name , arrival,visit])
    # append threads in arr list
    arr.append(t)

# start all threads in arr 
for t in arr:
    t.start()

    
