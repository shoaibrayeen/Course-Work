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
        if (key%2) == 1:
            b.sety(15)
        else:
            b.sety(0)
        
    def transform1(self , key , x):
            
        b = list.pop(self, key)
        list.insert(self ,key ,b)
        b.ack()
        b.sety(150)
        b.setx(x)
        if (key%2) == 1:
            b.sety(15)
        else:
            b.sety(0)
        

def show_text(text, x , y):
    goto(x , y)
    write(text, align="center", font=("Courier", 16, "bold"))

def init_shelf():
    global s
    s = Shelf(-540,-15)
    vals = (1, 2, 1, 2)
    for i in vals:
        s.push(Block(i))

def init_r(i):
    global r
    r = Shelf(520 ,-15)
    r.push(Block(i))


def receiver(i , length):
    time.sleep(1)
    r.transform(i , 0 ,  -540)
    
def sender(s):
    length = len(s)
    i = 0
    show_text("Sending Frame" , 0 , 100)
    show_text("Receiving Acknowledgement" , 0 , -100)
    while i < length:
        s.transform1(i , 520)
        receiver(i , length)
        if (i%2) == 0:
            k = 2
        else:
            k = 1
        if i < length - 1:
            init_r(k)
        i = i + 1



def start_sender():
    disable_keys()
    clear()
    show_text("Stop-n-wait noiseless" , -25 , 350)
    init_shelf()
    init_r(1)
    show_text("Sender" , -510 , -50)
    show_text("Receiver" , 540 , -50)
    sender(s)
    clear()
    show_text("press s for start sending data , q to quit" , 0 , 0)
    enable_keys()
    
    
def disable_keys():
    onkey(None, "s")
    
def enable_keys():
    onkey(start_sender, "s")
    onkey(bye, "q")

def main():
    getscreen().clearscreen()
    ht(); penup()
    show_text("Green for sending data , Red for Ack and black for frames , press s for start sending data , q to quit" , 0 , 0)
    enable_keys()
    listen()
    return "EVENTLOOP"


if __name__=="__main__":
    msg = main()
    mainloop() 
