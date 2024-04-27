import numpy as np
import math

# Function to find the orientation of triplet (p, q, r)
def orientation(p, q, r):
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if val == 0:
        return 0  # Collinear
    return 1 if val > 0 else 2  # Clockwise or Counterclockwise

def graham_scan(points):
    n = len(points)
    if n < 3:
        return points

    # Find the point with the lowest y-coordinate
    ymin = points[0][1]
    min_index = 0
    for i in range(1, n):
        y = points[i][1]
        if (y < ymin) or (ymin == y and points[i][0] < points[min_index][0]):
            ymin = y
            min_index = i

    # Place the point with the lowest y-coordinate at the first position
    points[0], points[min_index] = points[min_index], points[0]

    # Sort the remaining points based on the polar angle in counterclockwise order
    p0 = points[0]
    points[1:] = sorted(points[1:], key=lambda x: math.atan2(x[1]-p0[1], x[0]-p0[0]))

    # Initialize an empty stack
    stack = [points[0], points[1], points[2]]

    # Process remaining n-3 points
    for i in range(3, n):
        # Keep removing the top while the angle formed by points next-to-top,
        # top, and points[i] makes a non-left turn
        while len(stack) > 1 and orientation(stack[-2], stack[-1], points[i]) != 2:
            stack.pop()
        stack.append(points[i])

    return stack

def area_perimeter(graph):
    areas = []
    is_visited = np.zeros_like(graph, dtype=bool)
    for i in range(len(is_visited)):
        for j in range(len(is_visited[i])):
            if is_visited[i][j] == False and graph[i][j] == "#":
                nodes = []
                parent_update(nodes, (i, j), graph, is_visited)
                areas.append(nodes)
              
    min_area = len(graph[0]) * len(graph[1])
    min_perimeter = 100000

    for i in areas:
        if(len(i) < min_area):
            min_area = len(i)
        
        perimeter = 0
        patch = set(i)
        for point in i:
            boundary = 4
            if (point[0]-1, point[1]) in patch:
                boundary -= 1
            if (point[0]+1, point[1]) in patch:
                boundary -= 1
            if (point[0], point[1]-1) in patch:
                boundary -= 1
            if (point[0], point[1]+1) in patch:
                boundary -= 1
            # print(point, boundary)
            perimeter += boundary
        
        if(min_perimeter > perimeter):
            min_perimeter = perimeter
            # print(i)
                
    print(f"Min area {min_area} \n Min perimeter {min_perimeter}")
def parent_update(areas, node, graph, is_visited):
    if( node[0] >= 0 and node[0] < len(graph) and node[1] >= 0 and node[1] < len(graph[node[0]])):
        if not is_visited[node[0]][node[1]] and graph[node[0]][node[1]] == "#":
            is_visited[node[0]][node[1]] = True
            areas.append(node)
            parent_update(areas, (node[0] + 1, node[1]), graph, is_visited)
            parent_update(areas, (node[0] - 1, node[1]), graph, is_visited)
            parent_update(areas, (node[0], node[1] + 1), graph, is_visited)
            parent_update(areas, (node[0], node[1] - 1), graph, is_visited)
    else:
        return
    
input = '''
#.....
##....
..###.
.####.
######
.#...#'''

input = input.split()
for i in range(len(input)):
    input[i] = list(input[i])

input = np.array(input)
area_perimeter(input)