const letters = [
  "A",
  "B",
  "C",
  "D",
  "E",
  "F",
  "G",
  "H",
  "I",
  "J",
  "K",
  "L",
  "M",
  "N",
  "O",
  "P",
  "Q",
  "R",
  "S",
  "T",
  "U",
  "V",
  "W",
  "X",
  "Y",
  "Z"
];

export const rows = letter => {
  const result = [];
  const half = [];

  const indexOfTarget = letters.indexOf(letter);
  for (let i = 0; i < indexOfTarget; i++) {
    const padding = indexOfTarget - i + 1;
    const middleSpacing = i * 2;
    const lineLetter = letters[i];

    half.push(getFormattedLine(lineLetter, padding, middleSpacing));
  }

  result.push(...half);
  result.push(getTargetLetterLine(letter, indexOfTarget));
  result.push(...half.reverse());
  return result;
};

function getFormattedLine(letter, padding, middleSpacing) {
  let line = "";
  if (letter === "A") {
    line = letter;
    line = line.padStart(padding);
    line = line.padEnd(padding * 2 - 1);
  } else {
    line = letter.padStart(padding);
    line = line.padEnd(line.length - 1 + middleSpacing);
    line += letter;
    line = line.padEnd(line.length - 1 + padding);
  }
  return line;
}

function getTargetLetterLine(letter, index) {
  if (letter === "A") {
    return letter.padEnd(index * 2);
  } else {
    return letter.padEnd(index * 2) + letter;
  }
}
