from turtle import *
import random
import time

class Block(Turtle):
    """
        Objective : for size of each frame and color of each
    """
    def __init__(self, size):
        self.size = size
        Turtle.__init__(self, shape="square", visible=False)
        self.pu()
        self.shapesize(size * 1.5, 1.5, 2) # square-->rectangle
        self.fillcolor("black")
        self.st()

    def color2(self):
        self.fillcolor("green")
                       
    def color1(self):
        self.fillcolor("red")
                

    def __repr__(self):
        return "Block size: {0}".format(self.size)

class Shelf(list):
    def __init__(self,x, y):
        "create a shelf. y is y-position of first block"
        self.y = y
        self.x = x

    def push(self, d):
        """
            Objective : pushing frame
        """
        width, _, _ = d.shapesize()
        # align blocks by the bottom edge
        y_offset = width / 2 * 20
        d.sety(self.y + y_offset)
        d.setx(self.x + 34 * len(self))
        self.append(d)
        
    def pop(self, key):
        """
            Objective : popping frame
        """
        b = list.pop(self, key)
        b.color2()
        return b

    def insert(self, key, b):
        """
            Objective : inseting frames
        """
        list.insert(self, key, b)
        b.setx(self.x + 34 * key)
        width, _, _ = b.shapesize()
        # align blocks by the bottom edge
        y_offset = width / 2 * 20
        b.sety(self.y + y_offset)
        b.color2()
        
    def ack(self , key , j ,  x):
        b = list.pop(self, j)
        list.insert(self ,j , b)
        b.color2()
        b.sety(-150)
        b.setx(x + 34 * (key+1))
        b.sety(0)
        
    def sending(self , key , x):
        b = list.pop(self, key)
        list.insert(self ,key ,b)
        b.color1()
        b.sety(150)
        b.setx(x)
        b.sety(0)
        

def show_text(text, x , y):
    """
        Objective : displaying text at (x , y)
    """
    goto(x , y)
    write(text, align="center", font=("Courier", 16, "bold"))

def init_shelf():
    """
        Objective : displaying initial windows for sender
    """
    global s
    s = Shelf(-540,-15)
    for i in range(0,number_of_frames):
        s.push(Block(1))

def init_r():
    """
        Objective : displaying initial window for receiver
    """
    global r
    r = Shelf(520 ,-15)
    r.push(Block(1))


def text(r):
    time.sleep(2)
    clear()
    printframe_sender = "Sender : Current Frame Sequence No :- " + str(r%2)
    printnext_frame_receiver = "Receiver : Next Frame Sequence No :- " + str((r+1)%2)
    show_text("Stop-N-Wait ARQ ", -25 , 350)
    show_text("Sending Frame" , 0 , 100)
    show_text("Receiving Acknowledgement" , 0 , -100)
    show_text("Frame Dicarded/Frame Lost" , 450 ,  200)
    show_text("Sender" , --540 + (number_of_frames/2)*30  , -60)
    show_text("Receiver" , 540 , -60)
    show_text( printframe_sender , -500  , 230)
    show_text( printnext_frame_receiver , -500 , 200)
    i = 0
    while i < number_of_frames:
        show_text(str(i%2) , -535 + i*34 , 27)
        i = i + 1
    show_text(str(i%2) , -535 + i*34 , 27)
    show_text(str((r+1)%2) , 525 , 27)
    
def receiver(i, xcord):
    """
        Objective : Receiving Frame and sending acknowledgement
    """
    time.sleep(1)
    r.ack(i , 0 ,  xcord)

def sender(s):
    i = 0
    time.sleep(2)
    while i < number_of_frames:
        text(i)
        time.sleep(1)
        #generating random number
        temp = random.randint(0,number_of_frames-1)
        if temp == 0:
            #frame lost
            s.sending( i , 1000)
            time.sleep(2)
            #inserting duplicate frame
            s.push(Block(1))
            s.insert(i,s.pop(number_of_frames))
            time.sleep(3)
            #sending duplicate frame
            s.sending(i  , 520)
            del(s[i])
        else:
            time.sleep(2)
            #sending frame
            s.sending(i , 520)
        if temp == 1:
            #ack lost
            time.sleep(2)
            receiver(i, -1500)
            time.sleep(2)
            s.push(Block(1))
            #sending duplicate frame
            s.insert(i,s.pop(number_of_frames))
            time.sleep(2)
            #discarded by receiver
            s.sending(i  , 1000)
            del(s[i])
            init_r()
            #sending ack 
            receiver(i,-540)
        else:
            #sending ack
            time.sleep(2)
            receiver(i , -540)
        if i < number_of_frames - 1:
            #next frame on the receiver side
            init_r()
        i = i + 1
        time.sleep(2)
    

def start_sender():
    disable_keys()
    clear()
    global number_of_frames
    number_of_frames = input('Enter Number of Frames to sent\t:\t')
    number_of_frames = int(number_of_frames)
    show_text("Red for Sending Frame , Green for Acknowledgement and Black for Frame" , 0 , -300)
    init_shelf()
    init_r()
    sender(s)
    time.sleep(5)
    clearscreen()
    show_text("All Frame has been sent successfully!" , 0 , 0)
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
