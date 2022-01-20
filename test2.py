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

    rett = 0;
    for i in result:
        rett += i
    return rett

size = 23
edges = [4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21]
print(largestCycle(edges))