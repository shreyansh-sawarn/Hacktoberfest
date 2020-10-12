import { getInputDirections } from "./input.js";
//import { food } from './food.js';

export const snake_speed = 8;
export const snakeBody = [{ x: 11, y: 11 }];
let newsegments = 0;
let count = 0;

export function Update() {
  addNewsegments();
  const inputDirections = getInputDirections();
  for (let i = snakeBody.length - 2; i >= 0; i--) {
    snakeBody[i + 1] = { ...snakeBody[i] };
  }

  snakeBody[0].x += inputDirections.x;
  snakeBody[0].y += inputDirections.y;
}

export function PrintCount(position) {
  snakeBody.some(segment => {
    if (equalPositions(segment, position)) {
      count++;
    }
  });
  return count;
  //console.log(count);
}

export function draw(gameBoard) {
  snakeBody.forEach(segment => {
    const snakeElement = document.createElement("div");
    snakeElement.style.gridRowStart = segment.y;
    snakeElement.style.gridColumnStart = segment.x;
    snakeElement.classList.add("snake");
    gameBoard.appendChild(snakeElement);
  });
}

export function expandSnake(amount) {
  newsegments += amount;
}

export function onSnake(position, { ignoreHead = false } = {}) {
  return snakeBody.some((segment, index) => {
    if (ignoreHead && index === 0) return false;
    return equalPositions(segment, position);
  });
}

export function getSnakehead() {
  return snakeBody[0];
}

export function snakeIntersection() {
  return onSnake(snakeBody[0], { ignoreHead: true });
}

export function equalPositions(pos1, pos2) {
  return pos1.x === pos2.x && pos1.y === pos2.y;
}

function addNewsegments() {
  for (let i = 0; i < newsegments; i++) {
    snakeBody.push({ ...snakeBody[snakeBody.length - 1] });
  }
  newsegments = 0;
}
