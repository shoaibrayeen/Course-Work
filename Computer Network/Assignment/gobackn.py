from turtle import *
import math
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


def receiver(i, xcord):
    """
        Objective : Receiving Frame and sending acknowledgement
    """
    time.sleep(1)
    r.ack(i , 0 ,  xcord)
    

def text(r):
    clear()
    printframe_sender = "Sender : Current Frame Sequence No :- " + str(r%(window_size+1))
    printnext_frame_receiver = "Receiver : Next Frame Sequence No :- " + str((r+1)%(window_size+1))
    printwindow_size = "Window Size : " + str(window_size)
    show_text("Go-Back-N ARQ" , -25 , 350)
    show_text("Sending Frame" , 0 , 100)
    show_text("Receiving Acknowledgement" , 0 , -100)
    show_text("Frame Dicarded/Frame Lost" , 450 ,  200)
    show_text( printwindow_size , -500 , 260)
    show_text( printframe_sender , -500  , 230)
    show_text( printnext_frame_receiver , -500 , 200)
    show_text("Sender" , -540 + (number_of_frames/2)*30 , -60)
    show_text("Receiver" , 540 , -60)
    i = 0
    while i < number_of_frames:
        show_text(str(i%(window_size+1)) , -535 + i*34 , 27)
        i = i + 1
    show_text(str(i%(window_size+1)) , -535 + i*34 , 27)
    show_text(str((r+1)%(window_size+1)) , 525 , 27)
    
def sender():
    i = 0
    sf = 0
    sn = 0
    r = 0
    count = 0
    text(r)
    time.sleep(2)
    while sn - sf < window_size and r < number_of_frames:
        time.sleep(1)
        #generating random number
        temp = random.randint(0,number_of_frames - 1)
        if temp == 0:
            tmp = Shelf(-540 + sn*34 ,-15)
            tempsn = sn
            tempr = r
            while sn - sf < window_size and tempr < number_of_frames:
                #frame lost
                time.sleep(2)
                s.sending(sn , 1000)
                tempr = tempr + 1
                sn = sn + 1
                #discarding frame till window size
                time.sleep(1)
            j = 0
            sn = tempsn
            i = sn - sf
            tempr = r
            while j < window_size and tempr < number_of_frames and i < window_size:
                #duplicate frame

                time.sleep(2)
                tmp.push(Block(1))
                tempr = tempr + 1
                j = j + 1
                i = i + 1

            j = 0
            sf = sf + count
            while j < len(tmp):
                #sending duplicate frames
                time.sleep(2)
                tmp.sending(j , 520)
                time.sleep(2)
                #receiving ack
                receiver(r , -540)
                sf = sf + 1
                time.sleep(2)
                init_r()
                r = r + 1
                text(r)
                j = j + 1
            del(tmp)
            count = 0
            sn = sf
            if r < number_of_frames:
                #sending next frame
                time.sleep(2)
                s.sending(sn , 520)
                sn = sn + 1
            else:
                #end of loop
                break
        else:
            time.sleep(2)
            #sending frame
            s.sending(r , 520)
            sn = sn + 1
        if temp == 1:
            if sn - sf == window_size:
                #receiving ack
                time.sleep(2)
                receiver(r , -540)
                sf = sf + window_size
                count = 0
            elif r == number_of_frames -1:
                #sending ack for last frame
                time.sleep(2)
                receiver(r , -540)
                sf = r + 1
            else:
                #ack lost
                time.sleep(2)
                receiver(r , -1540)
                count = count + 1
        else:
            time.sleep(2)
            #sending ack
            receiver(r , -540)
            sf = r + 1
        r = r + 1
        if r < number_of_frames:
            time.sleep(2)
            #next frame on the receiver side
            init_r()
            text(r)

def start_sender():
    disable_keys()
    clear()
    global number_of_frames
    number_of_frames = input('Number of Frames to be sent\t:\t')
    number_of_frames = int(number_of_frames)
    global window_size
    window_size = input('Enter Size of Sequence Number\t:\t')
    window_size = int(window_size)
    window_size = int(math.pow(2,window_size)) -1
    show_text("Red for sending data , Green for Ack and black for frames" , 0 , -300)
    init_shelf()
    init_r()
    sender()
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
