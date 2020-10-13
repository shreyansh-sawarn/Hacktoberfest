// format an integer with a comma as a thousands separators in JavaScript
function formatNumber(num) {
  return num.toString().replace(/(\d)(?=(\d{3})+(?!\d))/g, '$1,')
}

console.info(formatNumber(3665)) // 3,665
console.info(formatNumber(103665)) // 103,665
console.info(formatNumber(111103665)) // 111,103,665
