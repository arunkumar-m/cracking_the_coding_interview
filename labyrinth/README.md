# Labyrinth

The Prince of Persia has been thrown onto the top level of Jaffar's
underground labyrinth. The labyrinth consists of __h__ levels strictly
on top of each other. Each level is split into __m__ by __n__ areas.
Some areas have columns that support ceiling, some areas are free. The
Prince can move only to free areas. To move to the level below, the
Prince can break the floor underneath him and jump down if there is no
column underneath. Every move takes the Prince 5 seconds. A princess is
waiting for the Princess at the lowest level. Write a program that will
help the Prince to save the Princess as fast as possible by finding the
shortest path between them and outputting time it took the Prince to
find the Princess. The structure of the labyrinth is given below. The
prince's location is marked with '1', the Princess's location is marked
with '2'. '.' marks a free spot and 'o' marks a column.

1 . .
o o .
. . .

o o o
. . o
. o o

o o o
o . .
o . 2
