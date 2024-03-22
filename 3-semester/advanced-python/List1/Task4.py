from turtle import *
import random
import math 

size = 100
iter = 1000 

speed(2)


def draw_setup(s):
    forward(s)
    left(90) 
    forward(s)
    left(90) 
    forward(s) 
    left(90) 
    forward(s) 
    left(90)
    penup()
    goto(s//2, 0)
    pendown()
    circle(s//2)

def in_circle(x, y):
    distance = math.sqrt((x - (size//2))**2 + (y - (size//2))**2)
    r = size//2
    return distance < r

def draw_dot(x, y, color):
    penup()
    goto(x, y)
    pendown()
    dot(3, color)

def calc_pi():
    draw_setup(size)
    ltwo = 0
    cltwt = 0
    for i in range (0, iter):
        p1 = random.randint(0, 100)
        p2 = random.randint(0, 100)
        if in_circle(p1, p2):
            ltwo += 1
            draw_dot(p1, p2, "green")
        else:
            draw_dot(p1, p2, "red")
        cltwt += 1
        pi = (4 * ltwo) / cltwt
        print(pi)
    

calc_pi()

done()