# Arduino-Reaction_Game

Developing a game for testing reaction time through pressing buttons. 

## The rules of game
![](https://i.imgur.com/I6zFwOZ.jpg)
* it will begin when you press the button called 3 in the yellow rectangle on the photo.
* When the game starts, lights will flicker. 
* If lights are close,you have to press button 1 in the red rectangle on the photo.
* Then screen shows reaction time and goes to next level. 
* There are three levels in the game,and time between levels would get more and more shorter.
* When you compelete three levels,you win the game.
* If you don't pressing button 3 in 2.5 sec as the lights closed,you would fail the game. 

## Result
![](https://i.imgur.com/QxQu2zs.jpg)
Video:https://youtu.be/v21Af0oOx4I

## What you need to complete project
* Hardware
  - Arduino ADK Mega2560 with DMA Arduino ADK Board
* Build environment in Arduino libries
  - DMA_KEY (support you do something on button)
  - DMA_LED (support you show something on LED)
  - LiquidCrystal
