def find_meet(edges_list, a,b,n):
    visited = [0]*n
    d = {}
    visited[a] = 1
    if visited[b] == 1:
        return a
    visited[b] = 1
    t = edges_list[a]
    while t!= -1 and visited[t] == 0:
        visited[t] = 1
        t = edges_list[t]
        t = edges_list[b]
    while t!= -1 and visited[t] == 0:
        visited[t] = 1
        t = edges_list[t]
    if t == -1:
        return -1
    return t


n = int(input())
edges_list = list(map(int,input().split()))
print(find_meet(edges_list, edges_list[0], edges_list[1], n))