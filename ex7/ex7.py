"""
*Student name: or paz
*Student ID: 311250708
*Course Exercise Group: 01
*Exercise name: 07
"""

import turtle
import argparse
import random

"""
convert number to binary/hexa/dec/oct (base num)
Keyword arguments: a-num n-base number
Return: print the number after convert.
"""
def mysteryFunc(a, n):
    if a > 0:
        temp = a % n
        print temp
        mysteryFunc(a/n, n)

class Sierpinski(object):

    def __init__(self):
        self.window = turtle.Screen()
        self.sierpinski_turtle = turtle.Turtle()

    def draw_sierpinski(self, length, depth):
        """
        draws a sierpinski tree
        :param length: the length of the base of the all tree
        :param depth: the depth of the tree recursion
        :return:
        """
        if depth == 0:
            for i in range(3):
                # create triangle
                self.sierpinski_turtle.forward(length)
                self.sierpinski_turtle.left(120)
        else:
            # draw triangle in length and depth that enter with recusion calls
            self.draw_sierpinski(length / 2, depth - 1)
            self.sierpinski_turtle.forward(length / 2)
            self.draw_sierpinski(length / 2, depth - 1)
            self.sierpinski_turtle.left(120)
            self.sierpinski_turtle.forward(length / 2)
            self.sierpinski_turtle.right(120)
            self.draw_sierpinski(length / 2, depth - 1)
            self.sierpinski_turtle.right(120)
            self.sierpinski_turtle.forward(length / 2)
            self.sierpinski_turtle.left(120)

    def finish_draw(self):
        self.window.bye()

    def save_draw(self, length, depth):
        self.sierpinski_turtle.hideturtle()
        nameSav = ("sierpinski_%d_%d" % (length, depth)) + ".svg"
        ts = self.sierpinski_turtle.getscreen().getcanvas()
        ts.postscript(file=nameSav)




class GameStatus(object):
    """Enum of possible Game statuses."""
    __init__ = None
    NotStarted, InProgress, Win, Lose = range(4)


class BoardCell(object):
    """
    Represents a cell in the minesweeper board game and is current status in the game

    """

    # this function are not get any arguments
    def __init__(self):
        """
        Initializes a board cell with no neighboring mines and status is hidden

        Args:
            None

        Returns:
            None (alters self)
        """

        # Status
        self.status = 'H'
        # Neighbors
        self.numOfNearMine = 0
        # Mine
        self.mine = False

    def is_mine(self):
        """
        returns true if this cell contains a mine false otherwise

        Args:
            None

        Returns:
            true if this cell contains a mine false otherwise
        """

        if self.mine:
            return True
        else:
            return False


    def is_hidden(self):
        """
        returns true if this cell is hidden false otherwise

        Args:
            None

        Returns:
            true if this cell is hidden false otherwise
        """

        if self.status == 'H':
            return True
        else:
            return False


    def get_cell_value(self):
        """
        returns the number of adjacent mines

        Args:
            None

        Returns:
            the number of adjacent mines in int or the charcter '*' if this cell is a mine
        """

        # Cell is mine
        if self.is_mine():
            # Return * if the cell contains a mine
            return '*'
        else:
            # Return the number of mine near it
            return self.numOfNearMine


    def uncover_cell(self):
        """
        uncovers this cell. when a cell is uncovered then his status is the value of the mines near it or * if the
        cell is a mine
        Args:
            None

        Returns:
            None (alters self)

        """

        if self.is_mine():
            self.status = '*'
        else:
            self.status = str(self.numOfNearMine)



    def update_cell_value(self, cellValue):
        """
        updates the value of the how many neighboring mines this cell has

        Args:
            numOfNearMine - the new number of the how many neighboring mines this cell has

        Returns:
            None (alters self)
        """

        self.numOfNearMine = cellValue


    def add_one_to_cell_value(self):
        """
        adds one to the number of near mine

        Args:
            None

        Returns:
            None (alters self)
        """

        self.numOfNearMine += 1


    def set_has_mine(self):
        """
        changes this cell to a cell with a mine in it

        Args:
           None

        Returns:
            None (alters self)
        """

        self.mine = True



class Board(object):
    """Represents a board of minesweeper game and its current progress."""

    def __init__(self, rows, columns, mines):
        """Initializes an empty hidden board.

        The board will be in the specified dimensions, without mines in it,
        and all of its cells are in hidden state.

        Args:
            rows: the number of rows in the board
            columns: the number of columns in the board

        Returns:
            None (alters self)
        """
        self.numRows = rows
        self.numColumns = columns
        self.mineCounter = mines
        # starts a board with row*col board cells
        self.board = [[BoardCell() for _ in range(columns)] for _ in range(rows)]

    def put_mines(self, mines, seed=None):
        """Randomly scatter the requested number of mines on the board.

        At the beggining, all cells on the board are hidden and with no mines
        at any of them. This method scatters the requested number of mines
        throughout the board randomly, only if the board is in the beginning
        state (as described here). A cell can host only one mine.
        This method not only scatters the mines on the board, but also updates
        the cells around it (so they will hold the right digit).

        Args:
            mines: the number of mines to scatter
            seed: the seed to give the random function. Default value None

        Returns:
            None (alters self)

        """
        listOfCellsIndex = [(numRow, numCol) for numRow in range(self.numRows) for numCol in range(self.numColumns)]
        # randomly choosing cells in the board to place mines in
        random.seed(seed)
        listOfMineCells = random.sample(listOfCellsIndex, mines)

        for mine in listOfMineCells:
            # Put mine in x,y
            self.board[mine[0]][mine[1]].set_has_mine()
            # Update neighbors
            if mine[0] < self.numRows and mine[1] < self.numColumns:
                row = mine[0]
                col = mine[1]
                # add 1 to cell value around cell[row][col]
                if(0 <= row-1 < self.numRows) and (0 <= col-1 < self.numColumns):
                    self.board[row-1][col-1].add_one_to_cell_value()
                if(0 <= row-1 < self.numRows) and (0 <= col < self.numColumns):
                    self.board[row-1][col].add_one_to_cell_value()
                if(0 <= row-1 < self.numRows) and (0 <= col+1 < self.numColumns):
                    self.board[row-1][col+1].add_one_to_cell_value()
                if(0 <= row+1 < self.numRows) and (0 <= col-1 < self.numColumns):
                    self.board[row+1][col-1].add_one_to_cell_value()
                if(0 <= row+1 < self.numRows) and (0 <= col < self.numColumns):
                    self.board[row+1][col].add_one_to_cell_value()
                if(0 <= row+1 < self.numRows) and (0 <= col+1 < self.numColumns):
                    self.board[row+1][col+1].add_one_to_cell_value()
                if (0 <= row < self.numRows) and (0 <= col-1 < self.numColumns):
                    self.board[row][col - 1].add_one_to_cell_value()
                if(0 <= row < self.numRows) and (0 <= col+1 < self.numColumns):
                    self.board[row][col+1].add_one_to_cell_value()

    def print_board(self):
        """prints the board according to the game format
            DO NOT CHANGE ANYTHING IN THIS FUNCTION!!!!!!!
        Args:
            None
        Returns:
            None
        """
        # creates the printing format
        printFormatString = "%-2s " * self.numColumns
        printFormatString += "%-2s"
        # prints the first line of the board which is the line containing the indexes of the columns
        argList = [" "]
        argList.extend([str(i) for i in range(self.numColumns)])
        print printFormatString % tuple(argList)
        # goes over the board rows and prints each one
        for i in range(self.numRows):
            argList = [str(i)]
            for j in range(self.numColumns):
                if self.board[i][j].is_hidden():
                    argList.append("H")
                else:
                    argList.append(str(self.board[i][j].get_cell_value()))
            print printFormatString % tuple(argList)

    def load_board(self, lines):
        """Loads a board from a sequence of lines.

        This method is used to load a saved board from a sequence of strings
        (that usually represent lines). Each line represents a row in the table
        in the following format:
            XY XY XY ... XY
        Where X is one of the characters: 0-8, * and Y is one of letters: H, S.
        0-8 = number of adjusting mines (0 is an empty, mine-free cell)
        * = represents a mine in this cell
        H = this cell is hidden

        The lines can have multiple whitespace of any kind before and after the
        lines of cells, but between each XY pair there is exactly one space.
        Empty or whitespace-only lines are possible between valid lines, or after/before them.
        It is safe to assume that the values are correct (the number represents the number of mines around
        a given cell) and the number of mines is also legal.

        Note that this method doesn't get the first two rows of the file (the
        dimensions) on purpose - they are handled in __init__.

        Args:
            lines: a sequence (list or tuple) of lines with the above restrictions

        Returns:
            None (alters self)
        """
        mineCount = 0
        for i in range(0, self.numRows):
            # remove \n and split lines by space
            lines[i] = lines[i].replace("\n", "").strip()
            newLine = lines[i].split()
            for j in range(0, self.numColumns):
                # if the cell is mine:
                if newLine[j][0] == '*':
                    # update and set has mine
                    self.board[i][j].set_has_mine()
                    self.board[i][j].update_cell_value(newLine[j][0])
                    # count the mine
                    mineCount += 1
                else:
                    # put the value in CellVal and the letter S/H in cellUncover
                    cellVal = int(newLine[j][0])
                    cellUncover = newLine[j][1]
                    self.board[i][j].update_cell_value(cellVal)
                    # if the cell is uncover
                    if cellUncover == 'S':
                        self.board[i][j].uncover_cell()
                    else:
                        self.board[i][j].status = 'H'
        # count the mine
        self.mineCounter = mineCount


    def get_value(self, row, column):
        """Returns the value of the cell at the given indices.

        The return value is a string of one character, out of 0-8 + '*'.

        Args:
            row: row index (integer)
            column: column index (integer)

        Returns:
            If the cell is empty and has no mines around it, return '0'.
            If it has X mines around it (and none in it), return 'X' (digit
            character between 1-8).
            If it has a mine in it return '*'.

        """
        return self.board[row][column].get_cell_value()

    def is_hidden(self, row, column):
        """Returns if the given cell is in hidden or uncovered state.

        Args:
            row: row index (integer)
            column: column index (integer)

        Returns:
            'H' if the cell is hidden, or 'S' if it's uncovered (can be seen).
        """
        if self.board[row][column].is_hidden():
            return 'H'
        else:
            return 'S'


    def uncover(self, row, column):
        """Changes the status of a cell from hidden to seen.

        Args:
            row: row index (integer)
            column: column index (integer)

        Returns:
            None (alters self)
        """
        self.board[row][column].uncover_cell()



class Game(object):
    """Handles a game of minesweeper by supplying UI to Board object."""

    def __init__(self, board):
        """Initializes a Game object with the given Board object.

        The Board object can be a board in any given status or stage.

        Args:
            board: a Board object to continue (or start) playing.

        Returns:
            None (alters self)
        """
        self.board = board

    def get_status(self):
        """Returns the current status of the game.

        The current status of the game is as followed:
            NotStarted: if all cells are hidden.
            InProgress: if some cells are hidden and some are uncovered, and
            no cell with a mine is uncovered.
            Lose: a cell with mine is uncovered.
            Win: All non-mine cells are uncovered, and all mine cells are
            covered.

        Returns:
            one of GameStatus values (doesn't alters self)

        """


        hiddenCounter = 0
        # run in matrix
        for row in range(0, self.board.numRows):
            for col in range(0, self.board.numColumns):
                # lose
                if self.board.get_value(row, col) == '*' and \
                        self.board.is_hidden(row, col) == 'S':
                    return GameStatus.Lose
                # count the hidden cell
                if self.board.is_hidden(row, col) == 'H':
                    hiddenCounter += 1

        if hiddenCounter == self.board.numRows * self.board.numColumns:
            return GameStatus.NotStarted
        # num of hidden cell is equal to num of number.
        if hiddenCounter == self.board.mineCounter:
            return GameStatus.Win
        else:
            return GameStatus.InProgress


    def make_move(self, row, column):
        """Makes a move by uncovering the given cell and unrippling it's area.

        The move flow is as following:
        1. Uncover the cell
        2. If the cell is a mine - return
        3. if the cell is not a mine, ripple (if value = 0) and uncover all
            adjacent cells, and recursively on this cells if needed (if they are empty cells)

        Args:
            row: row index (integer)
            column: column index (integer)

        Returns:
            the cell's value.
        """
        # 1. Uncover the cell
        if self.board.is_hidden(row, column) == 'H':
            self.board.uncover(row, column)
            # 2. If the cell is a mine - return
            cellVal = self.board.get_value(row, column)
            if cellVal == '*':
                return '*'
            elif cellVal > 0:
                return cellVal
            else:
                # check the range.
                if row < self.board.numRows and column < self.board.numColumns:
                    col = column
                    # recusion calls by 8 condition for each cell
                    if(0 <= row-1 < self.board.numRows) and (0 <= col-1 < self.board.numColumns):
                        self.make_move(row-1, col-1)
                    if(0 <= row-1 < self.board.numRows) and (0 <= col < self.board.numColumns):
                        self.make_move(row - 1, col)
                    if(0 <= row-1 < self.board.numRows) and (0 <= col+1 < self.board.numColumns):
                        self.make_move(row - 1, col + 1)
                    if(0 <= row+1 < self.board.numRows) and (0 <= col-1 < self.board.numColumns):
                        self.make_move(row + 1, col - 1)
                    if(0 <= row+1 < self.board.numRows) and (0 <= col < self.board.numColumns):
                        self.make_move(row + 1, col)
                    if(0 <= row+1 < self.board.numRows) and (0 <= col+1 < self.board.numColumns):
                        self.make_move(row + 1, col + 1)
                    if (0 <= row < self.board.numRows) and (0 <= col-1 < self.board.numColumns):
                        self.make_move(row, col - 1)
                    if(0 <= row < self.board.numRows) and (0 <= col+1 < self.board.numColumns):
                        self.make_move(row, col + 1)


    def run(self):
        """Runs the game loop.

        At each turn, prints the following:
            current state of the board
            game status
            available actions
        And then wait for input and act accordingly.
        More details are in the project's description.

        Returns:
            None
        """
        selection = 0
        while selection != 1:
            self.board.print_board()
            # print menu
            if self.get_status() == GameStatus.NotStarted:
                print 'Game status: NotStarted'
                print 'Available actions: (1) Exit | (2) Move'
            elif self.get_status() == GameStatus.InProgress:
                print 'Game status: InProgress'
                print 'Available actions: (1) Exit | (2) Move'
            elif self.get_status() == GameStatus.Win:
                print 'Game status: Win'
                print 'Available actions: (1) Exit'
            else:
                print 'Game status: Lose'
                print 'Available actions: (1) Exit'

            selection = raw_input("Enter selection:\n ")
            selection =int(selection)
            if selection == 1:
                break
                # illegal input
            elif selection == 2 and (self.get_status() == GameStatus.Lose or self.get_status() == GameStatus.Win):
                print 'Illegal choice'
            # continue the game.
            elif selection == 2:
                move = raw_input("Enter row then column (space separated): \n")
                move = move.split(" ")
                row = int(move[0])
                col = int(move[1])
                if 0 <= row < self.board.numRows and 0 <= col < self.board.numColumns:
                    if self.board.is_hidden(row, col) == 'S':
                        print 'Illegal move values'
                    else:
                        makeMove = self.make_move(row, col)
                # not in range.
                else:
                    print 'Illegal move values'
            elif selection != 1 and selection !=2:
                print 'Illegal choice'
        print 'Goodbye :)'


def main():
    # make parser
    parser = argparse.ArgumentParser()
    parser.add_argument('-p', dest="p", type=int, help='check mission')
    parser.add_argument('-a', dest="a", type=int, help='for mission 1')
    parser.add_argument('-n', dest="n", type=int, help='for mission 1')
    parser.add_argument('-d', dest="d", type=int, help='for mission 2-depth')
    parser.add_argument('-l', dest="l", type=int, help='for mission 2-length')
    parser.add_argument('-r', dest="r", type=int, help='for mission 3-row')
    parser.add_argument('-c', dest="c", type=int, help='for mission 3-col')
    parser.add_argument('-m', dest="m", type=int, help='for mission 3-mines')
    parser.add_argument('-i', dest="i", type=str, help='for mission 3')
    parser.add_argument('-s', dest="s", type=float, help='for mission 3')
    args = parser.parse_args()

    if args.p == 1:
        mysteryFunc(args.a, args.n)
    if args.p == 2:
        triangle = Sierpinski()
        triangle.draw_sierpinski(args.l, args.d)
        triangle.save_draw(args.l, args.d)
        triangle.finish_draw()
    if args.p == 3:
        if args.i is not None:
            mineSweeperFile = open(args.i, 'r')
            load = mineSweeperFile.readlines()
            mineSweeperFile.close()
            # save the 2 first line in file as row and col
            row = int(load[0])
            load.remove(load[0])
            col = int(load[0])
            load.remove(load[0])
            board = Board(int(row), int(col), 0)
            board.load_board(load)
            mine = board.mineCounter
            # check the size of board
            if (1 < row < 20) and (2 < col < 50) and (((row * col) - 1) >= mine):
                game = Game(board)
                game.run()
        else:
            # check the range
            if (1 < args.r < 20) and (2 < args.c < 50) and ((args.r * args.c) - 1 >= args.m):
                board = Board(args.r, args.c, args.m)
                board.put_mines(args.m, args.s)
                game = Game(board)
                game.run()
            else:
                print 'Illegal board'


if __name__ == '__main__':
    main()