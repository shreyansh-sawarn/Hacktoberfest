def reverse(sentence):
    answer = ''
    temp = ''
    for char in sentence:
        if char != ' ':
            temp += char
        else:
            answer = temp + ' ' + answer
            temp = ''
    answer = temp + ' ' + answer
    print(answer)
sentence = 'This is a string to try'
reverse(sentence)