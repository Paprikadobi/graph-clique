all:
	gcc main.c undirected_graph.c simple_set.c linked_list.c -o main

clean:
	rm main