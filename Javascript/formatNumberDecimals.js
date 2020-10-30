function formatNumberDecimals(unformattedNumber, precision) {
  const regExp = /\d(?=(\d{3})+\.)/g;
  const comma = '$&,';

  const numberToFormat = +unformattedNumber; // Use unary operator to cast string to number
  if (Number.isNaN(numberToFormat)) return unformattedNumber;

  return numberToFormat.toFixed(precision).replace(regExp, comma);
}

console.info(formatNumberDecimals(1000, 2)); // This function will get 1000 and return 1,000.00
