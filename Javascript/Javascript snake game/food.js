import { onSnake, expandSnake, PrintCount } from "./Snake.js";
import { randomGridposition } from "./grid.js";

export let food = getRandomFoodposition();
const EXPANSION_RATE = 1;
export let Score = 0;

export function Update() {
  Score = Number(PrintCount(food));
  //console.log(Score);
  if (onSnake(food)) {
    expandSnake(EXPANSION_RATE);
    food = getRandomFoodposition();
  }
  //PrintCount();
}

export function draw(gameBoard) {
  const foodElement = document.createElement("div");
  foodElement.style.gridRowStart = food.y;
  foodElement.style.gridColumnStart = food.x;
  foodElement.classList.add("food");
  gameBoard.appendChild(foodElement);
}

function getRandomFoodposition() {
  let newfoodPosition;
  while (newfoodPosition == null || onSnake(newfoodPosition)) {
    newfoodPosition = randomGridposition();
  }
  return newfoodPosition;
}
