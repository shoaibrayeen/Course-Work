from turtle import *
import math
import random
import time

class Block(Turtle):

    def __init__(self, size):
        self.size = size
        Turtle.__init__(self, shape="square", visible=False)
        self.pu()
        self.shapesize(size * 1.5, 1.5, 2) # square-->rectangle
        self.fillcolor("black")
        self.st()

    def send(self):
        self.fillcolor("green")

    def frame(self):
        self.fillcolor("black")
                       
    def ack(self):
        self.fillcolor("red")
                

    def __repr__(self):
        return "Block size: {0}".format(self.size)

class Shelf(list):
    def __init__(self,x, y):
        "create a shelf. y is y-position of first block"
        self.y = y
        self.x = x

    def push(self, d):
        width, _, _ = d.shapesize()
        # align blocks by the bottom edge
        y_offset = width / 2 * 20
        d.sety(self.y + y_offset)
        d.setx(self.x + 34 * len(self))
        self.append(d)
        
    def pop(self, key):
        b = list.pop(self, key)
        b.send()
        #b.sety(50)
        return b

    def insert(self, key, b):
        list.insert(self, key, b)
        b.setx(self.x + 34 * key)
        width, _, _ = b.shapesize()
        # align blocks by the bottom edge
        y_offset = width / 2 * 20
        b.sety(self.y + y_offset)
        b.send()
        
    def transform(self , key , j ,  x):
        b = list.pop(self, j)
        list.insert(self ,j , b)
        b.send()
        b.sety(-150)
        b.setx(x + 34 * key)
        b.sety(0)
        
    def transform1(self , key , x):
            
        b = list.pop(self, key)
        list.insert(self ,key ,b)
        b.ack()
        b.sety(150)
        b.setx(x)
        b.sety(0)
        

def show_text(text, x , y):
    goto(x , y)
    fillcolor("red")
    write(text, align="center", font=("Courier", 16, "bold"))

def init_shelf():
    global s
    s = Shelf(-540,-15)
    for i in range(0,number_of_frames):
        s.push(Block(1))

def init_r():
    global r
    r = Shelf(520 ,-15)
    r.push(Block(1))


def receiver(i, xcord):
    time.sleep(1)
    r.transform(i , 0 ,  xcord)
    
def sender(i , xcord):
    s.transform1(i , xcord)

def text(r):
    clear()
    show_text("Sending Frame" , 0 , 100)
    show_text("Receiving Acknowledgement" , 0 , -100)
    show_text("Go-Back-N Noisy" , -25 , 350)
    show_text("Sender" , -480 , -60)
    show_text("Receiver" , 540 , -60)
    i = 0
    while i < number_of_frames:
        show_text(str(i%(window_size+1)) , -535 + i*34 , 27)
        i = i + 1
    show_text(str(r%(window_size+1)) , 525 , 27)   
def main_s():
    i = 0
    #window =  int(math.pow(2,2)) -1
    sf = 0
    sn = 0
    r = 0
    count = 0
    while r < number_of_frames:
        
        time.sleep(1)
        text(r)
        while sn - sf < window_size and r < number_of_frames:
            time.sleep(1)
            temp = random.randint(0,number_of_frames - 1)
            if temp < 5:
                tmp = Shelf(-540 + sn*34 ,-15)
                tempsn = sn
                tempr = r
                while sn - sf < window_size and tempr < number_of_frames:
                    sender(sn , 1000)
                    tempr = tempr + 1
                    sn = sn + 1
                    time.sleep(1)
                j = 0
                sn = tempsn
                i = sn - sf
                tempr = r
                while j < window_size and tempr < number_of_frames and i < window_size:
                    time.sleep(1)
                    tmp.push(Block(1))
                    tempr = tempr + 1
                    j = j + 1
                    i = i + 1
                j = 0
                sf = sf + count
                while j < len(tmp):
                    time.sleep(1)
                    tmp.transform1(j , 520)
                    time.sleep(1)
                    receiver(r , -540)
                    sf = sf + 1
                    time.sleep(1)
                    init_r()
                    r = r + 1
                    text(r)
                    j = j + 1
                del(tmp)
                count = 0 
                sn = sf
                if r < number_of_frames:
                    time.sleep(2)
                    sender(sn , 520)
                    sn = sn + 1
                else:
                    break
            else:
                sender(r , 520)
                sn = sn + 1
            if temp > 5:
                if sn - sf == window_size:
                    receiver(r , -540)
                    sf = sf + window_size
                    count = 0
                elif r == number_of_frames -1:
                    receiver(r , -540)
                    sf = r + 1
                else:
                    receiver(r , -1540)
                    count = count + 1
            else:
                receiver(r , -540)
                sf = r + 1
            r = r + 1
            if r < number_of_frames:
                init_r()
                text(r)

def start_sender():
    disable_keys()
    clear()
    global number_of_frames
    number_of_frames = input('Number of Frames to be sent\t:\t')
    number_of_frames = int(number_of_frames)
    global window_size
    window_size = input('Window Size\t:\t')
    window_size = int(window_size)
    show_text("Red for sending data , Green for Ack and black for frames" , 0 , -300)
    init_shelf()
    init_r()
    main_s()
    clear()
    show_text("All Frame has been sent successfully!" , 0 , -350)
    show_text("press q to quit" , 0 , 0)
    enable_keys()
    
    
def disable_keys():
    onkey(None, "s")
    
def enable_keys():
    onkey(start_sender, "s")
    onkey(bye, "q")

def main():
    getscreen().clearscreen()
    ht(); penup()
    show_text("press s for start sending data , q to quit" , 0 , 0)
    enable_keys()
    listen()
    return "EVENTLOOP"


if __name__=="__main__":
    msg = main()
    mainloop()
