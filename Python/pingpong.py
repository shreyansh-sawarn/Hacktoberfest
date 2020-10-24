import turtle

wn = turtle.Screen()
wn.title("Welcome to Justin's ping pong")
wn.bgcolor('black')
wn.setup(800, 600)
wn.tracer(0)

score_a = 0
score_b = 0

# Paddle A
a = turtle.Turtle()
a.speed(0)
a.shape('square')
a.color('white')
a.shapesize(5,1)
a.penup()
a.goto(-350, 0)

# Paddle B
b = turtle.Turtle()
b.speed(0)
b.shape('square')
b.color('white')
b.shapesize(5,1)
b.penup()
b.goto(350, 0)

#ball1
ball1 = turtle.Turtle()
ball1.speed(0)
ball1.shape('circle')
ball1.color('white')
ball1.penup()
ball1.goto(0,0)
ball1.dx = -3
ball1.dy = -3


#ball2
ball2 = turtle.Turtle()
ball2.speed(0)
ball2.shape('circle')
ball2.color('white')
ball2.penup()
ball2.goto(0,0)
ball2.dx = 3
ball2.dy = 3

#ball3
ball3 = turtle.Turtle()
ball3.speed(0)
ball3.shape('circle')
ball3.color('white')
ball3.penup()
ball3.goto(0,0)
ball3.dx = -2
ball3.dy = 2

#ball4
ball4 = turtle.Turtle()
ball4.speed(0)
ball4.shape('circle')
ball4.color('white')
ball4.penup()
ball4.goto(0,0)
ball4.dx = 3
ball4.dy = -3

#ball5
ball5 = turtle.Turtle()
ball5.speed(0)
ball5.shape('circle')
ball5.color('white')
ball5.penup()
ball5.goto(0,0)
ball5.dx = -3
ball5.dy = 3

balls = [ball1, ball2]


# Scoreboard
sb = turtle.Turtle()
sb.speed(0)
sb.shape("square")
sb.color("white")
sb.penup()
sb.hideturtle()
sb.goto(0, 260)
sb.write("Player A: {}                 Player B: {}".format(score_a, score_b), align="center", font=("Courier", 24, "normal"))

def a_up():
    y = a.ycor()
    if y>200:
        y=y
    else:
        y += 20
    a.sety(y)

def a_down():
    y = a.ycor()
    if y<-200:
        y=y
    else:
        y -= 20
    a.sety(y)

def b_up():
    y = b.ycor()
    if y>200:
        y=y
    else:
        y += 20
    b.sety(y)

def b_down():
    y = b.ycor()
    if y<-200:
        y=y
    else:
        y -= 20
    b.sety(y)

wn.listen()
wn.onkeypress(a_up, "w")
wn.onkeypress(a_down, "s")
wn.onkeypress(b_up, 'Up')
wn.onkeypress(b_down, 'Down')

while True:
    wn.update()

    for ball in balls:
        x = ball.xcor() + ball.dx
        y = ball.ycor() + ball.dy

        ball.goto(x,y)

        #ball.setx(ball.xcor() + ball.dx)
        #ball.sety(ball.ycor() + ball.dy)

        if ball.ycor() > 250:
            ball.sety(200)
            ball.dy *= -1

        elif ball.ycor() < -250:
            ball.sety(-200)
            ball.dy *= -1

        if ball.xcor() > 351:
            score_a += 1
            sb.clear()
            sb.write("Player A: {}                 Player B: {}".format(score_a, score_b), align="center", font=("Courier", 24, "normal"))
            ball.goto(0,0)
            ball.dx *= -1

        if ball.xcor() < -351:
            score_b += 1
            sb.clear()
            sb.write("Player A: {}                 Player B: {}".format(score_a, score_b), align="center", font=("Courier", 24, "normal"))
            ball.goto(0,0)
            ball.dx *= -1

        if ball.xcor() < -335 and ball.ycor() < a.ycor() +50 and ball.ycor() > a.ycor() - 50:
            ball.dx *= -1

        elif ball.xcor() > 335 and ball.ycor() < b.ycor() +50 and ball.ycor() > b.ycor() - 50:
            ball.dx *= -1

    closest_ball = balls[0]
    for ball in balls:
        if ball.xcor() > closest_ball.xcor():
            closest_ball = ball

    if b.ycor() < closest_ball.ycor() and abs(b.ycor() - closest_ball.ycor()) > 20:
        b_up()

    elif b.ycor() > closest_ball.ycor() and abs(b.ycor() - closest_ball.ycor()) > 20:
       b_down()

    
        
     
    
