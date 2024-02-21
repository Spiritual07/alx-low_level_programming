#!/usr/bin/python3
"""A function that returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """ Calculate the perimeter of the island described in grid

    0 represents a water zone, 1 represents a land zone

    args:
        grid: A list of lists of integers representing the island
    """

    perimeter = 0
    rows = len(grid)
    columns = len(grid[0])

    for i in range(rows):
        for j in range(columns):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

    return perimeter
