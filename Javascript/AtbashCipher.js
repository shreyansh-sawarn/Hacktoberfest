const CODE_A = 'a'.charCodeAt(0);
const CODE_Z = 'z'.charCodeAt(0);
const INPUT_RE = /[a-z0-9]/gi;
const LETTER_RE = /[a-z]/i;

export const encode = (plain) => {
	let m, tmp = '', res = '';

	while(m = INPUT_RE.exec(plain)) {
		if (LETTER_RE.test(m[0])) {
			const diff = m[0].toLowerCase().charCodeAt(0) - CODE_A;
			tmp += String.fromCharCode(CODE_Z - diff);
		}
		else {
			tmp += m[0]; // digit
		}
	}

	for (let idx = 0; idx < tmp.length; idx += 5) {
		if (idx) res += ' ';
		res += tmp.substr(idx, 5);
	}

	return res;
};

export const decode = (encoded) => {
	let m, res = '';

	while(m = INPUT_RE.exec(encoded)) {
		if (LETTER_RE.test(m[0])) {
			const diff = CODE_Z - m[0].toLowerCase().charCodeAt(0);
			res += String.fromCharCode(CODE_A + diff);
		}
		else {
			res += m[0]; // digit
		}
	}

	return res;
};
