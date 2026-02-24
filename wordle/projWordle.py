import random
import flask

def readData():
    wordlist = []
    fileExists = False
    while fileExists == False:
        filename = input("Please enter a file name: ")
        try:
            with open(filename , 'r') as file:
                fileExists = True
                for line in file:
                    wordlist.append(line.strip())
        except FileNotFoundError:
            print("Invalid file name try again ...")
    return wordlist

def chooseWord(wordslist):
    randnum = random.randint(0,len(wordslist)-1)
    chosenWord = wordslist[randnum]
    return(chosenWord)

def wordExists(guess,wordlist):
    if guess in wordlist:
        return True
    else:
        return False

def computeClue(guess, targetword):
    clue = ['_','_','_','_','_']
    guess = list(guess)
    targetword = list(targetword)
    for i in range(len(guess)):
        if guess[i] == targetword[i]:
            clue[i] = 'G'
            targetword[i] = '0'
            guess[i] = '9'
    for l in range(len(targetword)):
        for j in range(len(targetword)):
                if guess[l] == targetword[j]:
                    clue[l] = 'Y'
                    targetword[j] = '0'
    for k in range(len(clue)):
        if clue[k] == '_':
            clue[k] = 'X'
    clue = "".join(clue)
    return(clue)

def makeGuess(wordlist):
    check = False
    while check == False:
        guess = input("Make a guess: ")
        guess = guess.upper()
        check = wordExists(guess,wordlist)
        if check == False:
            print("Word not in dictionary - try again...")
            
    return(guess)


def wordCorrect(clue):
    if clue == "GGGGG":
        return True
    else:
        return False
def game(wordlist):
    guessedWords = []
    guesses = 0
    score = 0    
    chosen = chooseWord(wordlist)
    while guesses < 6:
        guess = makeGuess(wordlist)
        clue = computeClue(guess,chosen)
        print(guess)
        print(clue)
        guesses += 1
        guessedWords.append(guess)
        if(wordCorrect(clue) == True):
            score = guesses
            print(f"Congratulations, your wordle score for this game is {score}")
            return score
    if guesses == 6:
        print(f"Sorry, you did not guess the word:  {chosen}")
        score = 10
        return score
        
    return
def playAgain():
    playing = input("Would you like to play again (Y or N)? ")
    if playing == 'Y' or playing == 'y':
        return True
    elif playing == 'N' or playing == 'n':
        return False

def main(seedValue):
    random.seed(seedValue)
    totalscore = 0
    wordlist = readData()
    play = True
    while(play == True):
        score = game(wordlist)
        totalscore += score
        print(f"Your overall score is {totalscore} \n")
        play = playAgain()
    
    print("Thanks for playing!")
    return