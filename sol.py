def largestCycle(edges):
    result = []
    visitedFrom = [-1] * len(edges)
    for startCell in range(0, len(edges)):
        cells = []
        cell = startCell
        while cell > -1 and visitedFrom[cell] == -1:
            visitedFrom[cell] = startCell
            cells.append(cell)
            cell = edges[cell]
        if cell > -1 and visitedFrom[cell] == startCell:
            cells_idx = cells.index(cell)
            cells = cells[cells_idx:]
            if len(cells) > len(result):
                result = cells

    sum = 0
    for i in result:
        sum += i
    return sum

size = 10
edges = [4, 5, 1, 6, 5, 2, 1, 5, 10, 10]
for i in edges:
    i = i - 1
print(largestCycle(edges))
