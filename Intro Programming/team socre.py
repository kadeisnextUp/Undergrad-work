# 
# Kaden Sawyer
# Intro to Programming 163/006
# 9/10/2021
# Class Work on September 10
# 




team1 = input('Enter a team: ')
score1 = int(input('Enter ' +team1 + "'s score:"))
team2 = input("Enter a team: ")
score2 = int(input('Enter ' +team2 + "'s score:"))
team3 = input('Enter a team: ')
score3 = int(input('Enter ' +team3 + "'s score:"))

roster = dict({team1:score1, team2:score2, team3:score3})

teamDis = input("Choose a team ") 
print('The score for ' + teamDis + 'is ' + roster.get(teamDis) )

