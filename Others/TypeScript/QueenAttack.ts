const WHITE: Player = 'W';
const BLACK: Player = 'B';
const BOARD_WIDTH = 8;
const EMPTY_SQUARE = '_';

type Position = [number, number];
type Player = 'W' | 'B';

class Board {
  static build(pieceOn: (square: Square) => string) {
    let board = '';
    for (let rank = 0; rank < BOARD_WIDTH; rank++) {
      for (let file = 0; file < BOARD_WIDTH; file++) {
        board += `${pieceOn(new Square([rank, file]))} `;
      }
      board = board.trim() + '\n';
    }
    return board;
  }
}

class Square {
  public rank: number;
  public file: number;

  constructor([rank, file]: Position) {
    this.rank = rank;
    this.file = file;
  }

  sameSquare(square: Square) {
    return this.file === square.file && this.rank === square.rank;
  }

  sameRow(square: Square) {
    return this.rank === square.rank;
  }

  sameColumn(square: Square) {
    return this.file === square.file;
  }

  inDiagonal(square: Square) {
    return Math.abs(this.file - square.file) === Math.abs(this.rank - square.rank);
  }
}

class Piece extends Square {
  public icon: string;

  constructor(square: Position, icon: string) {
    super(square);
    this.icon = icon;
  }
}

class QueenAttack {
  public white: Position;
  public black: Position;
  public whiteQueen: Piece;
  public blackQueen: Piece;

  constructor({ white = [0, 3], black = [7, 3] }: { black: Position; white: Position }) {
    this.white = white;
    this.black = black;
    this.whiteQueen = new Piece(white, WHITE);
    this.blackQueen = new Piece(black, BLACK);

    if (this.whiteQueen.sameSquare(this.blackQueen)) {
      throw new Error(`Queens cannot share the same space`);
    }
  }

  toString() {
    return Board.build((square: Square): string => this.pieceOn(square));
  }

  pieceOn(square: Square) {
    for (const queen of [this.blackQueen, this.whiteQueen]) {
      if (square.sameSquare(queen)) return queen.icon;
    }
    return EMPTY_SQUARE;
  }

  canAttack() {
    return (
      this.whiteQueen.sameRow(this.blackQueen) ||
      this.whiteQueen.sameColumn(this.blackQueen) ||
      this.whiteQueen.inDiagonal(this.blackQueen)
    );
  }
}

export default QueenAttack;
