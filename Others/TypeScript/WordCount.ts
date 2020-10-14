class Words {
    public count(text: string): Map<string, number> {
        const counted: Map<string, number> = new Map()
        text.replace('\t', ' ').replace('\n', ' ').split(' ').forEach(function (word: string) {
            const newWord: string = word.toLowerCase().trim()
            if(!newWord)
                return
            if(!counted.has(newWord))
                counted.set(newWord, 0)
            counted.set(newWord, counted.get(newWord)! + 1)
        });
        return counted
    }
}

export default Words
