"""
*Student name: or paz
*Student ID: 311250708
*Course Exercise Group: 01
*Exercise name: ex4Py
"""
import string


def CreateDictionary():

    """
    the function create a dictionary by key and value. the keys is the movies and
    value is the actor. the values are set.
    Keyword arguments: none
    Return: the function return movieDictionary
    """

    in_file = open("movies.txt", "r")
    movies = in_file.read().lower()
    moviesLines = movies.splitlines()
    moviesDictionary = {}
    # run all over moviesLines and split by ' , ' the word.
    for i in range(len(moviesLines)):

        # puts every elements in movieLineItem
        movieLineItem = moviesLines[i]
        movieSplitedValuesArr = movieLineItem.split(',')
        actorName = ''
        # run all over the movies in movieSplitedValuesArr and put them as key
        # in dictionary then put the specific actor as a value in the suitable key
        for j in range(len(movieSplitedValuesArr)):
            word = movieSplitedValuesArr[j].strip()
            # if this is a actor name
            if j == 0:
                actorName = word
            # otherwise (movies name)
            else:
                if not (word in moviesDictionary):
                    # put the movie name as a key
                    moviesDictionary[word] = set()
                    # add the actor name as a value
                moviesDictionary[word].add(actorName)

    return moviesDictionary


def QueryByMovies(dictionary):

    """
        the function get from user 2 movies and operator.if the movies didnt exists in
        dictionary print 'error'. then function move to other function that check the operator
        was entered
        Keyword arguments: get a dictionary
        Return: none
    """

    print "Please enter two movies and an operator(&,|,^) separated with ',':"
    userInput = raw_input()
    userInput = str(userInput).lower()
    userList = userInput.split(',')
    # make strip all the element in userList (from stackoverflow)
    userList = [item.strip() for item in userList]

    if (userList[0] not in dictionary) or (userList[1] not in dictionary):
        print "Error"
        return
    # put the values(actors) from specific key(movie) in new set
    setActorFromMovie1 = dictionary.get(userList[0])
    setActorFromMovie2 = dictionary.get(userList[1])
    CheckOperator(userList, setActorFromMovie1, setActorFromMovie2)


def CheckOperator(userList, setActorFromMovie1, setActorFromMovie2):

    """
        the function check witch operataor was enter.
        if enter '&' it is continue goes to IntersectionFunc.
        if enter '|' it is continue to UnionFunc
        if enter '^' it is continue SymmerDifferFunc
        Keyword arguments: userList, setActorFromMovie and setActorFromMovie2- value
        from specific key
        Return: none
    """

    if userList[2] is '&':
        IntersectionFunc(setActorFromMovie1, setActorFromMovie2)
    elif userList[2] is '|':
        UnionFunc(setActorFromMovie1, setActorFromMovie2)
    elif userList[2] is '^':
        SymmerDifferFunc(setActorFromMovie1, setActorFromMovie2)


def QueryByActor(dictionary):
    """
        the function get from user a actor name and then print all actors that
        play with actor that enter in dictionary
        Keyword arguments: the function get the dictionary
        Return: none
    """
    print "Please enter an actor:"
    userActor = raw_input()
    userActor = userActor.lower()
    setWithoutUserActor = set()
    # run all over the keys in dictionary
    for movie in dictionary:
        if str(userActor) in dictionary[movie]:
            setWithoutUserActor = (setWithoutUserActor.union(dictionary[movie]))
    # if entered actor that didn't exists in dictionary
    if len(setWithoutUserActor) == 0:
        print "Error"
    else:
        # remove the userActor from the set.
        setWithoutUserActor.remove(str(userActor))
        if len(setWithoutUserActor) == 0:
            print "There are no actors in this group."
        else:
            print "The actor's co-stars are:"
            setWithoutUserActorCapwords = set()
            # run all over actors in set
            for actor in setWithoutUserActor:
                # add to new set actor with capwords
                setWithoutUserActorCapwords.add(string.capwords(actor))
            setWithoutUserActorCapwords = sorted(setWithoutUserActorCapwords)
            print ", ".join(setWithoutUserActorCapwords)


def UnionFunc(setActorFromMovie1, setActorFromMovie2):
    """
            the UnionFunc print all the actor who play in 2 movies that enterd
            Keyword arguments: setActorFromMovie1,setActorFromMovie2- actor of specific movie.
            Return: none
    """
    setUnion = (setActorFromMovie1.union(setActorFromMovie2))
    print "The union actors are:"
    setUnionCapwords = set()
    # run all over actors in set
    for item in setUnion:
        # add to new set actor with capwords
        setUnionCapwords.add(string.capwords(item))
    setUnionCapwords = sorted(setUnionCapwords)
    print ", ".join(setUnionCapwords)


def IntersectionFunc(setActorFromMovie1, setActorFromMovie2):
    """
            the IntersectionFunc print all the actor who play in movie 1 and movie 2.
            if the function will not find like this it it will print a message.
            Keyword arguments: setActorFromMovie1,setActorFromMovie2- actor of specific movie.
            Return: none
        """
    setIntersection = (setActorFromMovie1.intersection(setActorFromMovie2))
    if len(setIntersection) == 0:
        print "There are no actors in this group."
    else:
        print "The intersection actors are:"
        setIntersectionCapwords = set()
        # run all over actors in set
        for item in setIntersection:
            # add to new set actor with capwords
            setIntersectionCapwords.add(string.capwords(item))
        setIntersectionCapwordsSorted = sorted(setIntersectionCapwords)
        print ", ".join(setIntersectionCapwordsSorted)


def SymmerDifferFunc(setActorFromMovie1, setActorFromMovie2):
    """
            the SymmerDifferFunc print all actors who play in 2 movies without the intesection
            between the movies.
            if the function will not find like this it will print a suitable message
            Keyword arguments: setActorFromMovie1,setActorFromMovie2- actor of specific movie.
            Return: none
        """

    setSymmerDiffer = (setActorFromMovie1.symmetric_difference(setActorFromMovie2))
    if len(setSymmerDiffer) == 0:
        print "There are no actors in this group."
    else:
        print "The symmetric difference actors are:"
        setSymmerDifferCapwords = set()
        # run all over actors in set
        for item in setSymmerDiffer:
            # add to new set actor with capwords
            setSymmerDifferCapwords.add(string.capwords(item))
        setSymmerDifferCapwords = sorted(setSymmerDifferCapwords)
        print ", ".join(setSymmerDifferCapwords)


def MainMenu():

    """
        the MainMenu get number 1-3 from user and send him to the suitable place.
        Keyword arguments: none
        Return: none
    """

    choice = None
    dictionary = CreateDictionary()
    print "Processing..."
    while choice is not 3:
        print "Please select an option:"
        print "1) Query by movies"
        print "2) Query by actor"
        print "3) Quit"
        choice = input()
        if choice == 1:
            QueryByMovies(dictionary)
        elif choice == 2:
            QueryByActor(dictionary)
MainMenu()