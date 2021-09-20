import random

points = int(input("Number of points: "));
radius = int(input("Range: "))
pointlist = ""

for i in range(points):
  x = random.randint(0,radius);
  y = random.randint(0,radius);
  pointlist+="{0} {1}\n".format(x,y);

print(pointlist)

with open("points.txt","w") as file:
  file.write(pointlist);
