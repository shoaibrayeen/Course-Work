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
        
    def ack(self , key  ,  x , y , flag = True):
        b = list.pop(self, key)
        list.insert(self ,key , b)
        b.color2()
        b.sety(y)
        if flag == True:    
            b.setx(x + 34 * (key+1))
        else:
            b.setx(x + 34 * (key))
        b.sety(0)

        
    def sending(self , key , x ):      
        b = list.pop(self, key)
        list.insert(self ,key ,b)
        b.color1()
        b.sety(150)
        b.setx(x + 34 * (key))
        b.sety(0)
        

def show_text(text, x , y):
    """
        Objective : displaying text at (x , y)
    """
    goto(x , y)
    write(text, align="center", font=("Courier", 16, "bold"))

def init_shelf():
    """
        Objective : displaying initial windows
    """
    dummy  = Shelf(266 ,-15)
    dummy.push(Block(1))
    del(dummy)
    global s
    s = Shelf(-540,-15)
    global r
    r = Shelf(300 ,-15)
    for i in range(0,number_of_frames):
        s.push(Block(1))
        r.push(Block(1))


def text():
    """
        Objective : Printing Information
    """
    printwindow_size = "Window Size : " + str(window)
    show_text("Selective Repeat ARQ" , -25 , 350)
    show_text("Sending Frame" , 0 , 100)
    show_text("Receiving Acknowledgement" , 0 , -100)
    show_text("Negative Acknowledgement" , 0 , -350)
    show_text("Frame Dicarded/Frame Lost" , 450 ,  200)
    show_text( printwindow_size , -540 , 200)
    show_text("Sender" , -540 + (number_of_frames/2)*30  , -60)
    show_text("Receiver" , 300 + (number_of_frames/2)*30 , -60)
    i = 0
    while i < number_of_frames:
        show_text(str(i%(2*window)) , -535 + i*34 , 27)
        show_text(str(i%(2*window)) , 271 + i*34, 27) 
        i = i + 1
    show_text(str(i%(2*window)) , -535 + i*34 , 27)
    show_text(str(i%(2*window)) , 271 + i*34, 27)

def receiver(i, xcord , ycord = -150 , flag = True):
    """
        Objective : Receiving Frame and sending acknowledgement
    """
    time.sleep(1)
    if flag == False:
        #incrementing receiver window
        i = i + 1
        return i
    if ycord == -150:
        #sending acknowledgement
        r.ack(i ,  xcord , ycord)
    else:
        #sending negative acknowledgement
        r.ack(i ,  xcord , ycord , False)
    i = i + 1
    return i
    

    
def sender():
    """
        Objective : Sending Frame and receiving acknowledgement
    """
    i = 0
    text()
    sf = 0 #First Outstanding
    sn = 0 #next Frame to send
    flag = False
    time.sleep(3)
    while sn - sf < window and sf < number_of_frames:
        time.sleep(2)
        #generating random number for losing frame
        temp = random.randint(0,number_of_frames - 1)
        if temp < 2 and sf < number_of_frames - 1 and flag == False:
            tempsn = sn
            #Frame Lost
            s.sending(sn , 1000)
            sn = sn + 1
            time.sleep(1)
            if sf < number_of_frames:
                time.sleep(3)
                #Sending Next Frame
                s.sending(sn , 266)
                sn = sn + 1
                time.sleep(1)
                flag = True
            else:
                break
        else:
            time.sleep(2)
            #Sending frame
            s.sending(sn , 266)
            sn = sn + 1
        if flag == True:
            #Negative Acknowledgement
            i = receiver(sf , -540 , -300)
            time.sleep(3)
            #Duplicate Frame
            tmpsender = Shelf(-540 + tempsn*34 ,-15)
            tmpsender.push(Block(1))
            while sn - sf < window and sf < number_of_frames - 1 :
                time.sleep(3)
                #Sending frames till sn - sf is less than window size
                s.sending(sn , 266)
                sn = sn + 1
                #increment receiver window
                i = receiver(i , -540 , -150 , False)
            sf = i
            time.sleep(2)
            #sending frame which was lost
            tmpsender.sending(0 , 266 + tempsn*34)
            del(tmpsender)
            time.sleep(2)
            #receiving ack for next frame
            sf = receiver(sf , -540)
            flag = False
        else:
            time.sleep(2)
            #receiving ack and incrementing sf
            sf = receiver(sf , -540)
    time.sleep(3)
    
def start_sender():
    disable_keys()
    clear()
    #input for number of frames to be sent
    global number_of_frames
    number_of_frames = input('Number of Frames to be sent\t:\t')
    number_of_frames = int(number_of_frames)
    global window
    #input for size of sequence Number
    window = input('Enter Size of Sequence Number\t:\t')
    window = int(window)
    #computing window size
    window = int(math.pow(2,window-1))
    print("window size\t\t\t:\t" , window)
    show_text("Red for Sending Frame , Green for Acknowledgement and Black for Frame" , 0 , -300)
    init_shelf()
    clear()
    sender()
    clearscreen()
    show_text("All Frame has been sent successfully!" , 0 , 0)
    enable_keys()
    
    
def disable_keys():
    #for disable keys
    onkey(None, "s")
    
def enable_keys():
    #for enable keys
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
