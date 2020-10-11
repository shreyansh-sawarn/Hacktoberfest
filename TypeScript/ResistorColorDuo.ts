export class ResistorColor {
  private colors: string[];

  resistanceMap: { [key: string]: number } = {
    black: 0,
    brown: 1,
    red: 2,
    orange: 3,
    yellow: 4,
    green: 5,
    blue: 6,
    violet: 7,
    grey: 8,
    white: 9
  };

  constructor(colors: string[]) {
    this.colors = colors;
    if(this.colors.length < 2){
      throw new Error("At least two colors need to be present")
    }
  }

  public value() {
    var totalResistance = this.colors
                                .slice(0,2)
                                .map(item => this.resistanceMap[item])
                                .join("");

    return Number(totalResistance);
  };
}
