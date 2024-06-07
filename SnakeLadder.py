#Design a mini project to implement Snake and 
#Ladders Game using Python.

def board(l):
    turn = 2
    for i in range(0,100):
        l.insert(i,i+1)
    for j in range(99,-1,-10):
        if(turn%2==0):
            print(l[j],"|",l[j-1],"|",l[j-2],"|",l[j-3],"|",l[j-4],"|",l[j-5],"|",l[j-6],"|",l[j-7],"|",l[j-8],"|",l[j-9])
            print("------------------------------------------------")
            turn-=1
        else:
            print(l[j-9],"|",l[j-8],"|",l[j-7],"|",l[j-6],"|",l[j-5],"|",l[j-4],"|",l[j-3],"|",l[j-2],"|",l[j-1],"|",l[j])
            print("------------------------------------------------")
            turn+=1

def snakeandladder():
    print("SNAKES\n 95-18\n 77-45\n 60-28\n 34-10\n 20-2\n")
    print("LADDERS\n 3-24\n 14-42\n 30-86\n 37-57\n 50-96\n 66-74\n")

def climb(x):
    if(x==3):
        x=24
    if(x==14):
        x=42
    if(x==30):
        x=86
    if(x==37):
        x=57
    if(x==50):
        x=96
    if(x==66):
        x=74
    return(x)

def fall(y):
    if(y==95):
        y=18
    if(y==77):
        y=45
    if(y==60):
        y=28
    if(y==34):
        y=10
    if(y==20):
        y=2
    return(y)

def accept_from_user(move1, move2):
    import random
    dice=[1,2,3,4,5,6]
    whoo = input("Enter name of player 1: ")
    wh = input("Enter name of player 2: ")
    who = int(input("Enter who wants to start the game! Enter 1 or 2.... "))
    while(move1<=100 and move2<=100):
        if(who==1):
            chance1 = int(input("{0} Enter 1 ROLL the dice: ".format(whoo)))
            if (chance1==1):
                player1=random.choice(dice)
                move1+=player1
                print(move1,"Before Climb")
                move1= climb (move1)
                print("{0} is at position {1}".format(whoo, move1))
                move1 = fall(move1)
                print("After Fall")
                print("{0} is at position {1}".format(whoo, move1))
            else:
                print("Enter 1 to Proceed!....")
            who+=1
        else:
            chance2 = int(input("{0} Enter 1 ROLL the dice: ".format(wh)))
            if (chance2==1):
                player2=random.choice(dice)
                move2+=player2
                print(move2,"Before Climb")
                move2= climb (move2)
                print("{0} is at position {1}".format(wh, move2))
                move2 = fall(move2)
                print("After Fall")
                print("{0} is at position {1}".format(wh, move2))
            else:
                print("Enter 1 to Proceed!....")
            who-=1
    else:
        if (move1>move2):
            print("Congrats {0}!!".format(whoo))
        else:
            print("Congrats {0}!!".format(wh))

l=[]
board(l)
snakeandladder()
accept_from_user(move1=1,move2=1)