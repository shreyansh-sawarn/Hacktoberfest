import random
def jogada(escolhaj,escolhapc):
    placarj = 0
    placarc = 0
    if escolhaj == "pedra" and escolhapc == "papel":
            print(nome,escolhaj,"X",escolhapc,"Computador")
            print("Você perdeu!")
            placarc = placarc + 1
            return placarc
            
    elif escolhaj == "pedra" and escolhapc == "tesoura":
            print(nome,escolhaj,"X",escolhapc,"Computador")
            print("Você venceu!")
            placarj = placarj + 1
            return placarj
            
    elif escolhaj == "tesoura" and escolhapc == "papel":
            print(nome,escolhaj,"X",escolhapc,"Computador")
            print("Você venceu!")
            placarj = placarj + 1
            return placarj

    elif escolhaj == "tesoura" and escolhapc == "pedra":
            print(nome,escolhaj,"X",escolhapc,"Computador")
            print("Você perdeu!")
            placarc = placarc + 1
            return placarc

    elif escolhaj == "papel" and escolhapc == "tesoura":
            print(nome,escolhaj,"X",escolhapc,"Computador")
            print("Você perdeu!")
            placarc = placarc + 1
            return placarc
            
    elif escolhaj == "papel" and escolhapc == "pedra":
            print(nome,escolhaj,"X",escolhapc,"Computador")
            print("Você ganhou!")
            placarj = placarj + 1
            return placarj
            
    elif escolhaj == escolhapc:
            print("Empate!")
            
           
placarc = 0
placarj = 0
jogadas = 0
nome = str(input("Digite o seu nome: "))
while jogadas <= 5:
    if jogadas != 5:
        escolhaj = str(input("Qual é a sua jogada? Resposta: "))
        lista = ["pedra","papel","tesoura"]
        escolhapc = random.choice(lista)
        jogada(escolhaj,escolhapc)
        jogadas = jogadas + 1
    else:
        resposta = str(input("Deseja continuar jogando? S/N  "))
        if resposta == "s":
            escolhaj = str(input("Qual é a sua jogada? Resposta: "))
            lista = ["pedra","papel","tesoura"]
            escolhapc = random.choice(lista)
            jogada(escolhaj,escolhapc)
        else:
            print(nome,placarj,"X",placarc,"Computador.")