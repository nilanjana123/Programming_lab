from threading import Semaphore, Thread
import time , random ,math

# A semaphore that allows only 2 threads to be inside critical section . 
# It represents that at a given time no more that 2 person can enter the shop
semaphore = Semaphore(2)
start_time = math.floor(time.perf_counter())                  

# person_in_shop is target of threads , it is created to represent persons and their activity
def person_in_shop(name , arrival , visit):
    # sleep for 'arrival' amount of time , which represents the arrival time of a person in shop 
    time.sleep(arrival)
    # print as the person reached the shop .
    current_time = math.floor(time.perf_counter()) - start_time
    print('Time '+format(current_time)+'s : '+name +' reached the shop\n',end='')
    # A thread can acquire a semaphore only if there is less than 2 person inside the shop
    semaphore.acquire()
    # after acquiring the semaphore , a person enters the shop , hence print it 
    current_time = math.floor(time.perf_counter()) - start_time
    print('Time '+format(current_time)+'s : '+name +' entered the shop\n',end='')
    # sleep for 'visit' amount of time  , which represents the visit time of a person in the shop 
    time.sleep(visit)
    # after visiting done, the person leaves the shop and release the semaphore so that other person can enter .
    current_time = math.floor(time.perf_counter()) - start_time
    print('Time '+format(current_time)+'s : '+name +' left the shop\n',end='')
    semaphore.release()


# arr is the list of threads 
arr=[] 

# create 5 threads 
for i in range(5):
    # arrival represents the arrival time of the Person or thread 
    arrival = random.uniform(1,5)
    # visit represents the amount of time a person will visit in shop
    visit = random.uniform(5,10)
    # name represents the name of the person 
    name = "Person "+format(i+1)

    # create thread with target to person_in_shop and arguments name, arrival , visit
    t = Thread(target= person_in_shop , args=[name , arrival,visit])
    # append threads in arr list
    arr.append(t)

# start all threads in arr 
for t in arr:
    t.start()
