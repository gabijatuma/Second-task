# Second-task
This program allows you to make a file of 1000, 10000, 100000, 1000000 or 10000000 students. The program creates different
files and then sorts them out with 3 containers: list, vector and deque. These files contain student names and randomly generated grades.
It also shows how much time it takes to read files and sort them out into two categories. In this version there are 3 ways of sorting: splitting them into 2 files while writing the results, splitting data into 2 new containers (which is the fastest way, as written in the text file) however it takes up unnecessary space. And it also takes half students in a new container and deletes them from the original container so the user is left with 2 different lists. this takes less time than my previous method, but more than writing into two new containers. In this case however the original list is gone and the placement of students can no longer be retrieved.
The tested times are in a text file called "failu rezultatai".
It shows that the best results are achieved with a list container and the worst with vector container.
Timewise is best to split data into 2 new containers.

computer that got these results has 8GB of RAM, 2.39GHz processor and 1TB HDD
