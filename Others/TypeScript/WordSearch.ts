type Index = number[]
type Path = Index[]
type Coordination = number[]
type Direction = number[]

interface IWordResult {
  start: Coordination
  end: Coordination
}

interface IResult {
  [index: string]: IWordResult | undefined
}

const indexToCoordination = (index: Index) => {
  return [index[0] + 1, index[1] + 1]
}
const isInRange = (value: number, min: number, max: number) =>
  value >= min && value < max

export default class WordSearch {
  /**
   * the grid of char
   * it can find a char by indexes in O(1)
   */
  grids: string[][]

  /**
   * the map of char and its all indexes
   * it can find the location of first char in O(1)
   */
  indexes: Map<string, Index[]> = new Map()

  constructor(grids: string[]) {
    this.grids = grids.map((str) => str.split(''))
    for (let row = 0; row < this.grids.length; row++) {
      const grid = this.grids[row]
      for (let col = 0; col < grid.length; col++) {
        const char = grid[col]
        if (!this.indexes.has(char)) {
          this.indexes.set(char, [])
        }
        this.indexes.get(char)?.push([row, col])
      }
    }
  }

  /**
   * find words
   * @param words
   */
  public find(words: string[]): IResult {
    return words.reduce<IResult>((acc, word) => {
      const path = this.findWord(word)
      if (path) {
        const start = indexToCoordination(path[0])
        const end = indexToCoordination(path[path.length - 1])
        acc[word] = { start, end }
      } else {
        acc[word] = undefined
      }
      return acc
    }, {})
  }

  /**
   * find the path of a word
   * @param word
   */
  private findWord(word: string): Path | undefined {
    let paths: Path[] | undefined
    const chars = word.split('')
    const directions: Direction[] = [
      [-1, -1], // top-left
      [-1, 0], // top
      [-1, 1], // top-right
      [0, -1], // left
      [0, 1], // right
      [1, -1], // bottom-left
      [1, 0], // bottom
      [1, 1], // bottom-right
    ]
    for (const direction of directions) {
      for (const char of chars) {
        paths = this.next(char, paths, direction)
        if (paths === undefined) {
          break
        }
      }
      if (paths) {
        return paths[0]
      }
    }
  }

  /**
   * create the path of a word recursively
   * @param char
   * @param paths
   */
  private next(
    char: string,
    paths: Path[] | undefined,
    direction: Direction
  ): Path[] | undefined {
    if (!paths) {
      const starts = this.indexes.get(char)
      if (starts) {
        return starts.map<Path>((start) => [start])
      }
      return undefined
    } else {
      let next: Path[] = []
      for (const path of paths) {
        const end = this.findNextEnd(char, path, direction)
        if (end) {
          next.push([...path, end])
        }
      }
      return next.length ? next : undefined
    }
  }

  /**
   * get next possible ends
   * @param target
   * @param path
   */
  findNextEnd(
    target: string,
    path: Path,
    direction: Direction
  ): Index | undefined {
    const length = path.length
    const end = path[length - 1]
    const row = end[0] + direction[0]
    const col = end[1] + direction[1]
    if (
      isInRange(row, 0, this.grids.length) &&
      isInRange(col, 0, this.grids[row].length) &&
      this.grids[row][col] === target
    ) {
      return [row, col]
    }
  }
}
