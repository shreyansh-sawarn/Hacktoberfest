class Pointers {
  constructor(length) {
    this.start = 0;
    this.end = -1;
    this.empty = true;
    this.full = false;
    this.max = length;
  }

  write(force) {
    const endPOne = (this.end + 1) % this.max;
    this.empty = false;
    if (this.full) {
      if (force) {
        this.start = (this.start + 1) % this.max;
        this.end = endPOne;
        return this.end;
      }
      return -1;
    }
    if (this.start === (endPOne + 1) % this.max) this.full = true;
    else this.full = false;
    this.end = endPOne;
    return this.end;
  }

  read() {
    this.full = false;
    if (this.empty) return -1;
    if (this.start === this.end) this.empty = true;
    const old = this.start;
    this.start = (this.start + 1) % this.max;
    return old;
  }

  clear() {
    this.start = 0;
    this.end = -1;
    this.empty = true;
    this.full = false;
  }
}

class CircularBuffer {
  constructor(length) {
    this.buffer = Array(length).fill("");
    this.pointers = new Pointers(length);
    this.bufferFullError = new BufferFullError();
    this.bufferEmptyError = new BufferEmptyError();
  }

  write(value) {
    if (value === null || value === undefined) return;
    let pos = this.pointers.write(false);
    if (pos === -1) throw this.bufferFullError;
    else this.buffer[pos] = value;
  }

  read() {
    const pos = this.pointers.read();
    if (pos === -1) throw this.bufferEmptyError;
    else {
      const readElm = this.buffer[pos];
      this.buffer[pos] = "";
      return readElm;
    }
  }

  forceWrite(value) {
    if (value === null || value === undefined) return;
    const pos = this.pointers.write(true);
    this.buffer[pos] = value;
  }

  clear() {
    this.pointers.clear();
    this.buffer.fill("");
  }
}

export default CircularBuffer;

export class BufferFullError extends Error {
  constructor() {
    super();
  }
}

export class BufferEmptyError extends Error {
  constructor() {
    super();
  }
}
