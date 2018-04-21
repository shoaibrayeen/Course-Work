from turtle import *
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

def init_shelf(total):
    total = int(total)
    global s
    s = Shelf(-540,-15)
    for i in range(0,total):
        s.push(Block(1))

def init_r(i):
    global r
    r = Shelf(520 ,-15)
    r.push(Block(1))


def receiver(i, xcord):
    time.sleep(1)
    r.transform(i , 0 ,  xcord)
    
def sender(i , xcord):
    s.transform1(i , xcord)

def main_s(s):
    show_text("Sending Frame" , 0 , 100)
    show_text("Receiving Acknowledgement" , 0 , -100)
    length = len(s)
    i = 0
    while i < length:
        time.sleep(1)
        temp = random.randint(0,length-1)
        if temp == 0:
            sender( i , 1000)
            time.sleep(2)
            s.push(Block(1))
            s.insert(i,s.pop(length))
            time.sleep(1)
            sender(i  , 520)
            del(s[i])
        else:
            sender(i , 520)
        if temp == 1:
            receiver(i, -1500)
            time.sleep(2)
            s.push(Block(1))
            s.insert(i,s.pop(length))
            time.sleep(1)
            sender(i  , 1000)
            del(s[i])
            if i == 0:
                init_r(2)
            else:
                init_r(1)
            receiver(i,-540)
        else:
            receiver(i , -540)
        if i < length - 1:
            init_r(1)
        i = i + 1
    

def start_sender():
    disable_keys()
    clear()
    number_of_frames = input('Enter Number of Frames to sent\t:\t')
    show_text("Red for sending data , Green for Ack and black for frames" , 0 , -300)
    show_text("Stop-n-Wait Noisy" , -25 , 350)
    init_shelf(number_of_frames)
    init_r(2)
    show_text("Sender" , -510 , -60)
    show_text("Receiver" , 540 , -60)
    main_s(s)
    #clear()
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
