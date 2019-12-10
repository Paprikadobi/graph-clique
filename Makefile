all:
	gcc main.c undirected_graph.c simple_set.c int_list.c set_list.c -o main

clean:
	rm main