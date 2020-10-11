let inputDirections = { x: 0, y: 0 };
let lastinputDiections = { x: 0, y: 0 };

window.addEventListener("keydown", event => {
  switch (event.key) {
    case "ArrowUp":
      if (lastinputDiections.y !== 0) break;
      inputDirections = { x: 0, y: -1 };
      break;
    case "ArrowDown":
      if (lastinputDiections.y !== 0) break;
      inputDirections = { x: 0, y: 1 };
      break;
    case "ArrowLeft":
      if (lastinputDiections.x !== 0) break;
      inputDirections = { x: -1, y: 0 };
      break;
    case "ArrowRight":
      if (lastinputDiections.x !== 0) break;
      inputDirections = { x: 1, y: 0 };
      break;
  }
});

export function getInputDirections() {
  lastinputDiections = inputDirections;
  return inputDirections;
}
