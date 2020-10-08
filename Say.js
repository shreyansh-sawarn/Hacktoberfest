const ones = ["zero","one","two","three","four","five","six","seven","eight",
        "nine","ten","eleven","twelve","thirteen","fourteen",
        "fifteen","sixteen","seventeen","eighteen","nineteen"]; 

const tens = ["","","twenty","thirty","forty","fifty","sixty","seventy",
        "eighty","ninety"]; 

const largeUnit = {'hundred':100,'thousand':1000,'million':1000000,'billion':1000000000};

function hunderes(hunderesNum,widthR){
	var result = '';
	if(hunderesNum < 100) return false;
	var naturalPart =  Math.floor(hunderesNum/100);
	result += ones[naturalPart]
	result += (widthR < 3) ? '' : ' hundred';
	var remainder = hunderesNum%100;
	if(remainder == 0 && result !== '') return result;
	if(result !== '') result += ' ';
	result += ones[remainder] ? ones[remainder] : tens[remainder/10] ? tens[remainder/10] : tensUnit(remainder) ? tensUnit(remainder) : '';
	return result;
}

function tensUnit(tensNum){
	var result = '';
	var naturalPart = Math.floor(tensNum/10);
	result += tens[naturalPart];
	var remainder = tensNum%10;
	result += (remainder > 0) ? '-' + ones[remainder] : '';
	return result;
}

function largeNum(widthNum) {
	var unit = '';
	switch(true){
		case widthNum == 3 :
			unit = ' hundred';
			break;
		case widthNum <= 6 && widthNum >= 4 :
			unit = ' thousand';
			break;
		case widthNum <= 9 && widthNum >= 7 :
			unit = ' million';
			break;
		case widthNum <= 12 && widthNum >= 10 :
			unit = ' billion';
			break;
	}
	return unit;
}

export class Say {
  inEnglish(number) {

  	if(number < 0) throw new Error('Number must be between 0 and 999,999,999,999.');
  	if(number > 999999999999) throw new Error('Number must be between 0 and 999,999,999,999.');
  	
	var currentNum = '';
	var widthNum = '';
	var arrayNum = [];
	var milestones;
	var naturalPart;
	var remainder;
	var result = '';
	var numberR = number + '';
	var widthR = numberR.length;
    while(number > -1){
    	currentNum = number + '';
    	widthNum = currentNum.length;
    	var unitNum = largeNum(widthNum);
		milestones = (widthNum > 3) ? largeUnit[unitNum.trim()] : 10**(widthNum-1);
		naturalPart = (number > 100) ? Math.floor(number/milestones) : number;
		remainder = (number > 100) ? number%milestones : 0;
		number = remainder;
		if(number == 0) number = -1;
		if(number == 0 && result !== '') naturalPart = -1;
		if(result !== '') result += ' ';
		result += ones[naturalPart] ? ones[naturalPart] : tens[naturalPart/10] ? tens[naturalPart/10] : 
			hunderes(naturalPart,widthR) ? hunderes(naturalPart,widthR) : tensUnit(naturalPart) ? tensUnit(naturalPart) : '';
		result += (widthR >= 3 && numberR != 100) ? unitNum : '';
    }
    return result;
  }
}
