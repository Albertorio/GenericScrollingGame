# Generic Scrolling Game: If/Else

#Objectives

Throughout this exercise the students will practice:

* if/else
* do/while
* setter/getters

## Concepts

This laboratory consist on a simple side scrolling game. The user controls a car on the left edge of the screen, that can be moved up and down. Obstacles and checkpoints are created on the right edge of the screen, and these scroll toward the user on the left edge. The user earns a score, shown at the bottom, and the game ends when the user hits an obstacle. This laboratory is an adaptation of the assigment presented by Dave Feinberg [1].

<img src="http://i.imgur.com/cH1Cxbn.png">

## Libraries
For this project you need to know how to use the rand function from &lt;cstdlib> and &lt;ctime>.
   
* srand(time(NULL)); // seeds the random number generator with the current system time
* rand( );           // function that generates random numbers

## Exercise 1

The Qt project at *HERE???* contains the skeleton for an application to play a side scrolling game, you can run the code and see what happens. Right now the game runs but no obstacles or flags appear, other than the ones at the beginning, your job is to make them reappear. In the code you will find comments that will guide you in making the objects reappear while the game is running. The way to do this is first we have to generate the objects over and over. Now the width of the window where the game is displayed is 550px. You should start with just the x coordinate of the objects. 

The x1 and x2 variables are extremely important, to give the ilusion that the car is moving we just move the background from right to left, x1 and x2 are the x coordinates of the background. We have two x coordinates because we place two roads next to each other so we can cover the whole window. That way when one road ends and the second road is filling the window we can place the first one next to the current one and so on and we have an infinite road.

All the code you have to write in this exercise will be inside the if's in the updateObs function. Also you should write the code in one if and copy paste it to the other. 

After getting the x coordinates of the objects down, we need to work with the y coordinates, here we are gonna be using the rand function. Now the top of the road is 80px and the bottom its 280px. We need objects to appear within tha range (80 - 280). When adding the other cones, as you increase the difficulty, you have to remember that the second and third cone cannot appear in the same coordinates as the first cone. To avoid having the same coordinates I recommend using a do/while with the conditions of the coordinates. Also you should try the same thing for the flag so that way it doesnt appear in the same coordinates as the cone.

## Exercise 2

For the second exercise, you have to work on the setTrack function. The objective of this exercise is to set the rest of the tracks and the obstacles that go with them, there's one already done as an example. There are some comments in the code to help you along.

## Exercise 3

For the last exercise, you have to make the collision with objects work. Here you are gonna be working in the collision and flagCollision functions. If the coordinates of the car are the same as the cone then you have to call the stopGame function and set the playing boolean to false. As for the flagCollision function you have to do two things: first you have to add a resonable amount to the score (e.g. 30 points) and second you have to set the x coordinate of the flag.

### Deliverables

In the following text box, copy the code that you developed for the program. Remember to properly comment the code and use good indentation and variable naming practices.

### References
[1] Dave Feinberg, http://nifty.stanford.edu/2011/feinberg-generic-scrolling-game/

