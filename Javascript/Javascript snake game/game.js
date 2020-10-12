import { Update as Updatesnake, draw as drawsnake, snake_speed, getSnakehead, snakeIntersection } from './Snake.js';
import { Update as Updatefood, draw as drawfood, Score } from './food.js';
import { outsideGrid } from './grid.js'

//const gameScore = document.getElementById('game-score')

let lastrenderTime = 0;
let gameover = false
const gameBoard = document.getElementById('game-board');

function main(currentTime) {
    
    if(gameover) {
        if(confirm('You Lost. Press ok to restart')) {
            window.location = '/'
        }
        return
    }

    
    const secondssinceLastrender = (currentTime - lastrenderTime)/1000;
    window.requestAnimationFrame(main)
    if(secondssinceLastrender < 1/snake_speed) return
    lastrenderTime = currentTime;

    Update()
    draw()
}

function appendScore(score) {
    const scoreElement = document.createElement('div')
    scoreElement.innerText = ` your score is ${score}`;
    gameBoard.append(scoreElement)
}






window.requestAnimationFrame(main);

function Update() {
    Updatesnake()
    Updatefood()
    checkDeath()
    appendScore(Score);
    console.log(Score);
}

function draw() {
    gameBoard.innerHTML = ''
    drawsnake(gameBoard)
    drawfood(gameBoard)
}

function checkDeath() {
    gameover = outsideGrid(getSnakehead()) || snakeIntersection()
}